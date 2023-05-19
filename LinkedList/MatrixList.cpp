#include "MatrixList.h"

MatrixNode::MatrixNode(bool b, Triple *t)
{
    head = b;
    if (b)
        right = down = this; // 列/行的標頭節點
    else 
        triple = *t; // 標頭節點串列的元素節點或標頭節點

}

Matrix::Matrix()
{
    headnode = 0;
}

Matrix::~Matrix()
{
    if (!headnode) 
        return; // no nodes to delete
    MatrixNode *x = headnode->right;
    while (x != headnode) { // return nodes by rows
        MatrixNode *y = x->right; 
        while (y != x){
            MatrixNode *z = y->right;
            delete y;
            y = z;
        }
        x = x->next;
        delete y;
    }
    delete headnode;
    headnode = 0; // empty linked sparse matrix
}

Matrix Matrix::operator+(const Matrix &b) const
{
    if (!headnode || !b.headnode)
        throw "Cannot add null matrix.";
    if (headnode->triple.row != b.headnode->triple.row || headnode->triple.col != b.headnode->triple.col)
        throw "Cannot add two matrices of different dimensions.";
    Matrix c;
    Triple t;
    t.row = headnode->triple.row;
    t.col = headnode->triple.col;
    t.value = 0;
    c.headnode = new MatrixNode(false, &t);
    int p = max(headnode->triple.row, headnode->triple.col);
    MatrixNode **head = new MatrixNode* [p];
    for (int i = 0; i < p; i++)
        head[i] = new MatrixNode(true, 0);
    for (int i = 0; i < p; i++) 
        head[i]->next = head[i + 1];
    head[p - 1]->next = c.headnode;
    c.headnode->right = head[0];
    MatrixNode *currentA = headnode->right;
    MatrixNode *currentB = b.headnode->right;
    MatrixNode *currentC = c.headnode->right;
    MatrixNode *temp;
    for (int i = 0; i < headnode->triple.row; i++){
        currentA = currentA->right;
        currentB = currentB->right;
        while (!currentA->head && !currentB->head){
            if (currentA->triple.col == currentB->triple.col && currentA->triple.value + currentB->triple.value == 0){
                currentA = currentA->right;
                currentB = currentB->right;
            }else{
                if (currentA->triple.col < currentB->triple.col){
                    currentC->right = new MatrixNode(false, &currentA->triple);
                    currentA = currentA->right;
                    currentC = currentC->right;
                }else if (currentA->triple.col > currentB->triple.col){
                    currentC->right = new MatrixNode(false, &currentB->triple);
                    currentB = currentB->right;
                    currentC = currentC->right;
                }else{
                    t.row = currentA->triple.row;
                    t.col = currentA->triple.col;
                    t.value = currentA->triple.value + currentB->triple.value;
                    currentC->right = new MatrixNode(false, &t);
                    currentA = currentA->right;
                    currentB = currentB->right;
                    currentC = currentC->right;
                }
                temp = head[currentC->triple.col];
                while (temp->down != head[currentC->triple.col])
                    temp = temp->down;
                temp->down = currentC;
                currentC->down = head[currentC->triple.col];
                c.headnode->triple.value++;
            }
        }
        while (!currentA->head){
            currentC->right = new MatrixNode(false, &currentA->triple);
            currentC = currentC->right;
            currentA = currentA->right;
            temp = head[currentC->triple.col];
            while (temp->down != head[currentC->triple.col])
                temp = temp->down;
            temp->down = currentC;
            currentC->down = head[currentC->triple.col];
            c.headnode->triple.value++;
        }
        while (!currentB->head){
            currentC->right = new MatrixNode(false, &currentB->triple);
            currentC = currentC->right;
            currentB = currentB->right;
            temp = head[currentC->triple.col];
            while (temp->down != head[currentC->triple.col])
                temp = temp->down;
            temp->down = currentC;
            currentC->down = head[currentC->triple.col];
            c.headnode->triple.value++;
        }
        currentC->right = head[i];
        currentC = currentC->right;
        currentA = currentA->next;
        currentB = currentB->next;
        currentC = currentC->next;
    }
    delete [] head;
    return c;
}

Matrix Matrix::operator*(const Matrix &b) const
{
    if (!headnode || !b.headnode)
        throw "Cannot multiply null matrix.";
    if (headnode->triple.col != b.headnode->triple.row)
        throw "Invalid matirx dimensions.";
    Matrix c;
    Triple t;
    t.row = headnode->triple.row;
    t.col = b.headnode->triple.col;
    t.value = 0;
    c.headnode = new MatrixNode(false, &t);
    int p = max(headnode->triple.row, b.headnode->triple.col);
    MatrixNode **head = new MatrixNode* [p];
    for (int i = 0; i < p; i++)
        head[i] = new MatrixNode(true, 0);
    for (int i = 0; i < p; i++) 
        head[i]->next = head[i + 1];
    head[p - 1]->next = c.headnode;
    c.headnode->right = head[0];
    MatrixNode *currentA = headnode->right;
    MatrixNode *currentB = b.headnode->right;
    MatrixNode *currentC = c.headnode->right;
    MatrixNode *temp;
    for (int i = 0; i < c.headnode->triple.row; i++){
        for (int j = 0; j < c.headnode->triple.col; j++){
            int sum = 0;
            currentA = currentA->right;
            currentB = currentB->down;
            while (!currentA->head && !currentB->head){
                if (currentA->triple.col == currentB->triple.row){
                    sum += currentA->triple.value * currentB->triple.value;
                    currentA = currentA->right;
                    currentB = currentB->down;
                }else if (currentA->triple.col > currentB->triple.row){
                    currentA = currentA->right;
                }else{
                    currentB = currentB->down;
                }
            }
            if (sum != 0){
                t.row = i;
                t.col = j;
                t.value = sum;
                currentC->right = new MatrixNode(false, &t);
                currentC = currentC->right;
                temp = head[currentC->triple.col];
                while (temp->down != head[currentC->triple.col])
                    temp = temp->down;
                temp->down = currentC;
                currentC->down = head[currentC->triple.col];
                c.headnode->triple.value++;
            }
            while (!currentA->head)
                currentA = currentA->right;
            while (!currentB->head)
                currentB = currentB->down;
            currentB = currentB->next;
        }
        currentC->right = head[i];
        currentC = currentC->right;
        currentA = currentA->next;
        currentB = b.headnode->right;
        currentC = currentC->next;
    }
    delete [] head;
    return c;
}

void Matrix::Transpose()
{
    if (!headnode || headnode->right == headnode)
        return;
    Matrix b;
    Triple t;
    t.row = headnode->triple.col;
    t.col = headnode->triple.row;
    t.value = headnode->triple.value;
    b.headnode = new MatrixNode(false, &t);
    int p = max(headnode->triple.row, headnode->triple.col);
    MatrixNode **head = new MatrixNode* [p];
    for (int i = 0; i < p; i++)
        head[i] = new MatrixNode(true, 0);
    for (int i = 0; i < p; i++) 
        head[i]->next = head[i + 1];
    head[p - 1]->next = b.headnode;
    b.headnode->right = head[0];
    MatrixNode *currentA = headnode->right;
    MatrixNode *currentB = b.headnode->right;
    MatrixNode *temp;
    for (int i = 0; i < headnode->triple.col; i++){
        currentA = currentA->down;
        while (!currentA->head){
            t.row = currentA->triple.col;
            t.col = currentA->triple.row;
            t.value = currentA->triple.value;
            currentB->right = new MatrixNode(false, &t);
            currentB = currentB->right;
            temp = head[currentB->triple.col];
            while (temp->down != head[currentB->triple.col])
                temp = temp->down;
            temp->down = currentB;
            currentB->down = head[currentB->triple.col];
            currentA = currentA->down;
        }
        currentB->right = head[i];
        currentB = currentB->right;
        currentA = currentA->next;
        currentB = currentB->next;
    }
    this->~Matrix();
    headnode = b.headnode;
    b.headnode = 0;
    delete [] head;
    return;
}

Matrix::Matrix(const Matrix &b)
{
    if (!b.headnode)
        return;
    headnode = new MatrixNode(false, &b.headnode->triple);
    int p = max(headnode->triple.row, headnode->triple.col);
    if (!p){
        headnode->right = headnode;
        return;
    }
    MatrixNode **head = new MatrixNode* [p];
    for (int i = 0; i < p; i++)
        head[i] = new MatrixNode(true, 0);
    for (int i = 0; i < p; i++) 
        head[i]->next = head[i + 1];
    head[p - 1]->next = headnode;
    headnode->right = head[0];
    MatrixNode *currentA = headnode->right;
    MatrixNode *currentB = b.headnode->right;
    for (int i = 0; i < headnode->triple.row; i++){
        currentB = currentB->right;
        while (!currentB->head){
            currentA->right = new MatrixNode(false, &currentB->triple);
            currentA = currentA->right;
            MatrixNode *temp = head[currentA->triple.col];
            while (temp->down != head[currentA->triple.col])
                temp = temp->down;
            temp->down = currentA;
            currentA->down = head[currentA->triple.col];
            currentB = currentB->right;
        }
        currentA->right = head[i];
        currentA = currentA->right;
        currentA = currentA->next;
        currentB = currentB->next;
    }
    delete [] head;
}

void Matrix::PrintMatrix() const
{
    if (!headnode || headnode->right == headnode)
        return;
    int row = 0, col = 0;
    MatrixNode *current = headnode->right;
    for (row = 0; row < headnode->triple.row; row++){
        current = current->right;
        for (col = 0; col < headnode->triple.col; col++){
            if (current->head){
                cout << "0\t";
            }else{
                if (row == current->triple.row && col == current->triple.col){
                    cout << current->triple.value << "\t";
                    current = current->right;
                }else{
                    cout << "0\t";
                }
            }
        }
        cout << endl;
        current = current->next;
    }
    return;
}

istream &operator>>(istream &is, Matrix &matrix)
{
    matrix.~Matrix();
    // Read in a maxtix and set up its linked representation
    Triple s;
    is >> s.row >> s.col >> s.value; // matrix dimensions
    int p = max(s.row, s.col);
    // set up header node for list of header nodes
    matrix.headnode = new MatrixNode(false, &s);
    if (p == 0) {// empty matrix
        matrix.headnode->right = matrix.headnode; 
        return is; // for supporting "cin >> mi >> mj;"
    }
    // at least one row or column
    MatrixNode **head = new MatrixNode* [p];
    for (int i = 0; i < p; i++)
        head[i] = new MatrixNode(true, 0);
    int currentRow = 0; // start from row 0
    MatrixNode *last = head[0]; // last node in current row
    for (int i = 0; i < s.value; i++) // input triples
    {
        Triple t;
        is >> t.row >> t.col >> t.value;
        if (t.row > currentRow) { // end of current row
            last->right = head[currentRow]; // close current row
            currentRow = t.row;
            last = head[currentRow];
        } // end of if
        last->right = new MatrixNode(false, &t); 
        last = last->right;
        // link new node into row list, last point to new node
        MatrixNode *temp = head[t.col];
        while (temp->down != head[t.col])
            temp = temp->down;
        temp->down = last;
        last->down = head[t.col]; 
        // link into column list
    } // end of for
    last->right = head[currentRow]; // close last row
    // link the header nodes together
    for (int i = 0; i < p; i++) 
        head[i]->next = head[i + 1];
    head[p-1]->next = matrix.headnode;
    matrix.headnode->right = head[0];
    delete [] head;
    return is;
}

ostream &operator<<(ostream &os, Matrix &matrix)
{
    MatrixNode *current = matrix.headnode;
    if (!current)
        return os;
    os << current->triple.row << " " << current->triple.col << " " << current->triple.value << endl;
    current = current->right;
    while (current != matrix.headnode){
        current = current->right;
        while (!current->head){
            os << current->triple.row << " " << current->triple.col << " " << current->triple.value << endl;
            current = current->right;
        }
        current =current->next;
    }
    return os;
}
