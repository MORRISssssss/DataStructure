#include "BinaryTree.h"

template <class T>
TreeNode<T>::TreeNode(T d, TreeNode<T>* left, TreeNode<T>* right)
{
    data = d;
    leftChild = left;
    rightChild = right;
}

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <class T>
inline bool BinaryTree<T>::IsEmpty() const
{
    return root == nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &bt1, const T &item, const BinaryTree<T> &bt2)
{
    root->data = item;
    root->leftChild = bt1.root;
    root->rightChild = bt2.root;
}

template <class T>
BinaryTree<T> BinaryTree<T>::LeftSubtree()
{
    BinaryTree<T> leftTree;
    CopyTree(leftTree.root, root->leftChild);
    return leftTree;
}

template <class T>
BinaryTree<T> BinaryTree<T>::RightSubtree()
{
    BinaryTree<T> rightTree;
    CopyTree(rightTree.root, root->rightChild);
    return rightTree;
}

template <class T>
T BinaryTree<T>::RootData() const
{
    return root->data;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    DestroyTree(root);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& bt)
{
    CopyTree(root, bt.root);
}

template <class T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &bt)
{
    if (this == &bt){
        return *this;
    }
    DestroyTree(root);
    CopyTree(root, bt.root);
    return *this;
}

template <class T>
void BinaryTree<T>::Inorder() const
{
    Inorder(root);
}

template <class T>
void BinaryTree<T>::Preorder() const
{
    Preorder(root);
}

template <class T>
void BinaryTree<T>::Postorder() const
{
    Postorder(root);
}

template <class T>
void BinaryTree<T>::LevelOrder() const
{
    if (root == nullptr)
        return;
    queue<TreeNode<T>*> q;
    TreeNode<T> *currentNode = root;
    while (currentNode) {
        Visit(currentNode);
        if (currentNode->leftChild)
            q.push(currentNode->leftChild);
        if (currentNode->rightChild) 
            q.push(currentNode->rightChild);
        if (q.empty()) 
            return;
        currentNode = q.front();
        q.pop();
    }
}

template <class T>
void BinaryTree<T>::NonrecInorder() const
{
    stack<TreeNode<T>*> s; 
    TreeNode<T> *currentNode = root;
    while (true) {
        while (currentNode) { 
            s.push(currentNode);
            currentNode = currentNode->leftChild;
        }
        if (s.empty()) 
            return;
        currentNode = s.top();
        s.pop(); 
        Visit(currentNode);
        currentNode = currentNode->rightChild;
    }
}

template <class T>
void BinaryTree<T>::NoStackInorder() const
{
    if (!root) return; //空的二元樹
    TreeNode<T> *top = 0, *lastRight =0, *p, *q, *r, *r1;
    p = q = root;
    while(1) {
        while(1) {
            if ((!p->leftChild) && (!p->rightChild)) { //樹葉節點
                Visit(p);
                break;
            }
            if (!p->leftChild) { // 拜訪p並移至p->rightChild
                Visit(p);
                r = p->rightChild; 
                p->rightChild = q;
                q = p; 
                p = r;
            }
            else { // 移至p->leftChild
                r = p->leftChild; 
                p->leftChild = q;
                q = p; 
                p = r;
            }
        } // 內圈while結束
        // p是一個葉節點，向上移至右子樹還沒被檢查的節點
        TreeNode<T> *av = p;
        while(1) {
            if (p == root) return;
            if (!q->leftChild) { // q是透過rightChild鏈結的
                r = q->rightChild; 
                q->rightChild = p;
                p = q; 
                q = r;
            } else if (!q->rightChild) { // q是透過leftChild鏈結的
                r = q->leftChild; 
                q->leftChild = p;
                p = q; 
                q = r; 
                Visit(p);
            } else { // 檢查p是否為q的rightChild
                if (q == lastRight) {
                    r = top; 
                    lastRight = r->leftChild;
                    top = r->rightChild; // 彈出堆疊
                    r->leftChild = r->rightChild = 0;
                    r = q->rightChild; 
                    q->rightChild = p;
                    p = q; 
                    q = r;
                } else { // p是q的leftChild
                    Visit(q);
                    av->leftChild = lastRight; 
                    av->rightChild = top;
                    top = av; 
                    lastRight = q;
                    r = q->leftChild; 
                    q->leftChild = p;
                    r1 = q->rightChild; 
                    q->rightChild = r;
                    p = r1;
                    break;
                }
            }
        } // 內圈while結束
    } // 外圈while結束

}

template <class T>
T BinaryTree<T>::Visit(const TreeNode<T> *node, bool print) const
{
    if (print){
        cout << node->data << " ";
    }
    return node->data;
}

template <class T>
bool BinaryTree<T>::operator==(const BinaryTree &bt) const
{
    stack<T> s1, s2;
    Inorder(root, s1);
    Inorder(bt.root, s2);
    return s1 == s2;
}

template <class T>
BinaryTree<char> BinaryTree<T>::SetupBinaryTree1()
{
    TreeNode<char>* node1 = new TreeNode<char>('A');
    TreeNode<char>* node2 = new TreeNode<char>('B');
    TreeNode<char>* node3 = new TreeNode<char>('-', node1, node2);
    TreeNode<char>* node4 = new TreeNode<char>('C');
    TreeNode<char>* node5 = new TreeNode<char>('*', node3, node4);
    TreeNode<char>* node6 = new TreeNode<char>('D');
    TreeNode<char>* node7 = new TreeNode<char>('*', node5, node6);
    TreeNode<char>* node8 = new TreeNode<char>('E');
    TreeNode<char>* node9 = new TreeNode<char>('+', node7, node8);
    BinaryTree<char> t;
    t.root = node9;
    return t;
}

template <class T>
BinaryTree<char> BinaryTree<T>::SetupBinaryTree2()
{
    TreeNode<char>* node1 = new TreeNode<char>('H');
    TreeNode<char>* node2 = new TreeNode<char>('J');
    TreeNode<char>* node3 = new TreeNode<char>('D', node1, node2);
    TreeNode<char>* node4 = new TreeNode<char>('E');
    TreeNode<char>* node5 = new TreeNode<char>('B', node3, node4);
    TreeNode<char>* node6 = new TreeNode<char>('F');
    TreeNode<char>* node7 = new TreeNode<char>('G');
    TreeNode<char>* node8 = new TreeNode<char>('C', node6, node7);
    TreeNode<char>* node9 = new TreeNode<char>('A', node5, node8);
    BinaryTree<char> t;
    t.root = node9;
    return t;
}

template <class T>
void BinaryTree<T>::DestroyTree(TreeNode<T>*& node)
{
    if (node != nullptr) {
        DestroyTree(node->leftChild);
        DestroyTree(node->rightChild);
        delete node;
        node = nullptr;
    }
}

template <class T>
void BinaryTree<T>::CopyTree(TreeNode<T> *&copy, const TreeNode<T> *other)
{
    if (other == nullptr){
        copy = nullptr;
        return;
    }
    copy = new TreeNode<T>(other->data);
    CopyTree(copy->leftChild, other->leftChild);
    CopyTree(copy->rightChild, other->rightChild);
}

template <class T>
void BinaryTree<T>::Inorder(const TreeNode<T> *node) const
{
    if (node != nullptr){
        Inorder(node->leftChild);
        Visit(node);
        Inorder(node->rightChild);
    }
}

template <class T>
void BinaryTree<T>::Preorder(const TreeNode<T> *node) const
{
    if (node != nullptr){
        Visit(node);
        Preorder(node->leftChild);
        Preorder(node->rightChild);
    }
}

template <class T>
void BinaryTree<T>::Postorder(const TreeNode<T> *node) const
{
    if (node != nullptr){
        Postorder(node->leftChild);
        Postorder(node->rightChild);
        Visit(node);
    }
}

template <class T>
void BinaryTree<T>::Inorder(const TreeNode<T> *node, stack<T> &buff) const
{
    if (node != nullptr){
        Inorder(node->leftChild, buff);
        buff.push(Visit(node, false));
        Inorder(node->rightChild, buff);
    }
}

