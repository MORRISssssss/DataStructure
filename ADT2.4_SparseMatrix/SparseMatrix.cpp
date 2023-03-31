#include "SparseMatrix.h"
#include <iostream>
using namespace std;

#define INIT_CAPACITY 5

SparseMatrix::SparseMatrix(const int r = 0, const int c = 0, const int t = 0)
{
    rows = r;
    cols = c;
    terms = t;
    capacity = INIT_CAPACITY;
    smArray = new MatrixTerm[capacity];
}

SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(cols, rows, terms);
    if (terms > 0) {
        int *rowSize = new int[cols];
        int *rowStart = new int[cols];
        // calculate the row size of the new matrix
        fill(rowSize, rowSize + cols, 0); 
        for (int i = 0; i < terms; i ++) 
            rowSize[smArray[i].col]++;
        // calculate the starting array index of each row 
        // of the new matrix
        rowStart[0] = 0;
        for (int i = 1; i < cols; i++) 
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for (int i = 0; i < terms; i++){
            int j = rowStart[smArray[i].col];
            b.smArray[j].row= smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        } // end of for
        delete [] rowSize;
        delete [] rowStart;
    } // end of if
    return b;
}

SparseMatrix SparseMatrix::Add(const SparseMatrix b)
{
    if (rows != b.rows || cols != b.cols)
        throw "Incompatible matrices";
    SparseMatrix c(rows, cols, 0);
    int aPos = 0, bPos = 0, sum = 0;
    while (aPos < terms && bPos < b.terms){
        if (smArray[aPos].row == b.smArray[bPos].row){
            if (smArray[aPos].col == b.smArray[bPos].col){
                sum = smArray[aPos].value + b.smArray[bPos].value;
                c.StoreTerm(sum, smArray[aPos].row, smArray[aPos].col);
                aPos++;
                bPos++;
            }else if (smArray[aPos].col < b.smArray[bPos].col){
                c.StoreTerm(smArray[aPos].value, smArray[aPos].row, smArray[aPos].col);
                aPos++;
            }else {
                c.StoreTerm(b.smArray[bPos].value, b.smArray[bPos].row, b.smArray[bPos].col);
                bPos++;
            }
        }else if (smArray[aPos].row < b.smArray[bPos].row){
            c.StoreTerm(smArray[aPos].value, smArray[aPos].row, smArray[aPos].col);
            aPos++;
        }else {
            c.StoreTerm(b.smArray[bPos].value, b.smArray[bPos].row, b.smArray[bPos].col);
            bPos++;
        }
    }
    for (; aPos < terms; aPos++)
        c.StoreTerm(smArray[aPos].value, smArray[aPos].row, smArray[aPos].col);
    for (; bPos < b.terms; bPos++)
        c.StoreTerm(b.smArray[bPos].value, b.smArray[bPos].row, b.smArray[bPos].col);
    return c;
}

SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{
    if (cols != b.rows) // error handling
        throw "Incompatible matrices"; 
    SparseMatrix bXpose = b.Transpose(); // transpose b
    SparseMatrix d(rows, b.cols, 0); // create the output matrix d
    int currRowIndex = 0, currRowBegin = 0, currRowA = smArray[0].row;
    // introduce dummy terms for handling boundary condition
    if (terms == capacity) 
        ChangeSize1D(terms + 1);
    // introduce dummy terms for handling boundary condition
    bXpose.ChangeSize1D(bXpose.terms + 1);
    smArray[terms].row = rows;
    bXpose.smArray[b.terms].row = b.cols;
    bXpose.smArray[b.terms].col = -1;
    int sum = 0;
    while (currRowIndex < terms) { // check currRowA is valid
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        while (currColIndex <= b.terms){ // process B matrix term by term
            if (smArray[currRowIndex].row != currRowA) { // row end 
                d.StoreTerm(sum, currRowA, currColB); // store the sum
                sum = 0; // reset the sum
                currRowIndex = currRowBegin; // rewind the row
                while (bXpose.smArray[currColIndex].row == currColB)
                    currColIndex++; // skip terms in the curr col
                currColB = bXpose.smArray[currColIndex].row; // next col
            } else if (bXpose.smArray[currColIndex].row != currColB) {
                // col end
                d.StoreTerm(sum, currRowA, currColB); // output the sum
                sum = 0; // reset the sum
                currRowIndex = currRowBegin; // rewind the row
                currColB = bXpose.smArray[currColIndex].row; // next col
            } else {
                if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col)
                    currRowIndex++; 
                else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col) {
                    sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
                    currRowIndex++; 
                    currColIndex++;
                }
                else
                currColIndex++; 
            } // end of if-elseif-else
        } // end of the inner while (currColIndex <= b.terms) 
        while (smArray[currRowIndex].row == currRowA)
            currRowIndex++; // skip terms in the curr row
        currRowBegin = currRowIndex; //next row
        currRowA = smArray[currRowIndex].row; //next row
    } // end of the outer while (currRowIndex < terms) 
return d;

}

void SparseMatrix::StoreTerm(const int v, const int r, const int c)
{
    if (v != 0) {
        if (terms == capacity)
            ChangeSize1D(2 * capacity); 
        smArray[terms].row = r;
        smArray[terms].col = c;
        smArray[terms++].value = v;
    }
}

void SparseMatrix::ChangeSize1D(const int newSize)
{
     // change the array size to newSize
    if (newSize < terms) 
        throw "New size must be >= number of terms";
    MatrixTerm *temp = new MatrixTerm[newSize]; 
    // new array
    copy(smArray, smArray + terms, temp);
    delete [] smArray; 
    smArray = temp; 
    // make smArray point to the newly created array
    capacity = newSize;
}

SparseMatrix& SparseMatrix::operator=(SparseMatrix Matrix)
{
    rows = Matrix.rows;
    cols = Matrix.cols;
    terms = Matrix.terms;
    capacity = Matrix.capacity;
    MatrixTerm *temp = new MatrixTerm[capacity]; 
    copy(Matrix.smArray, Matrix.smArray + terms, temp);
    delete [] smArray; 
    smArray = temp; 
    return *this;
}

ostream& operator<<(ostream& os, const SparseMatrix& Matrix)
{
    int termIndex = 0;
    for (int r = 0; r < Matrix.rows; r++){
        for (int c = 0; c < Matrix.cols; c++){
            if (r == Matrix.smArray[termIndex].row && c == Matrix.smArray[termIndex].col){
                os << Matrix.smArray[termIndex].value << "\t";
                termIndex++;
            }else {
                os << 0 << "\t";
            }
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, SparseMatrix& Matrix)
{
    int ROWS, COLS, TERMS;
    is >> ROWS >> COLS >> TERMS;
    SparseMatrix temp(ROWS, COLS, 0);
    for (int i = 0; i < TERMS; i++){
        int r, c, v;
        is >> r >> c >> v;
        temp.StoreTerm(v, r, c);
    }
    return is;
}