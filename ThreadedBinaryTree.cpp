#include "ThreadedBinaryTree.h"

template <class T>
ThreadedTreeNode<T>::ThreadedTreeNode(T d, bool leftT, ThreadedTreeNode<T>* left, bool rightT, ThreadedTreeNode<T>* right)
{
    data = d;
    leftThread = leftT;
    leftChild = left;
    rightThread = rightT;
    rightChild = right;
}

template <class T>
ThreadedBinaryTree<T>::ThreadedBinaryTree()
{
    head = new ThreadedTreeNode<T>(0, true, head, true, head);
}

template <class T>
ThreadedBinaryTree<T>::~ThreadedBinaryTree()
{
    DestroyTree(head);
}

template <class T>
void ThreadedBinaryTree<T>::Preorder() const
{
    Preorder(head->leftChild);
}

template <class T>
void ThreadedBinaryTree<T>::Postorder() const
{
    Postorder(head->leftChild);
}

template <class T>
void ThreadedBinaryTree<T>::InsertRight(ThreadedTreeNode<T> *s, ThreadedTreeNode<T> *r)
{
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;
    r->leftChild = s;
    r->leftThread = true; //leftChild is a thread
    s->rightChild = r; 
    s->rightThread = false;
    if (!r->rightThread) {
        ThreadedInorderIterator<T> temp(r);
        while (!temp.currentNode->leftThread)
            temp.Next();
        temp.currentNode->leftChild = r;
    }
}

template <class T>
void ThreadedBinaryTree<T>::InsertLeft(ThreadedTreeNode<T> *s, ThreadedTreeNode<T> *l)
{
    l->leftChild = s->leftChild;
    l->leftThread = s->leftThread;
    l->rightChild = s;
    l->rightThread = true;
    s->leftChild = l; 
    s->leftThread = false;
    if (!l->leftThread) {
        ThreadedInorderIterator<T> temp(l);
        while (!temp.currentNode->rightThread)
            temp.Previous();
        temp.currentNode->rightChild = l;
    }
}

template <class T>
T ThreadedBinaryTree<T>::Visit(const ThreadedTreeNode<T> *node, bool print) const
{
    if (print){
        cout << node->data << " ";
    }
    return node->data;
}

template <class T>
ThreadedInorderIterator<T> ThreadedBinaryTree<T>::Begin() const
{
    ThreadedTreeNode<T> *temp = head;
    while (!temp->leftThread)
        temp = temp->leftChild;
    return ThreadedInorderIterator<T>(temp);
}

template <class T>
ThreadedInorderIterator<T> ThreadedBinaryTree<T>::End() const
{
    return ThreadedInorderIterator<T>(head);
}

template <class T>
void ThreadedBinaryTree<T>::DestroyTree(ThreadedTreeNode<T> *&node)
{
    if (node != head) {
        if (!node->leftThread)
            DestroyTree(node->leftChild);
        if (!node->rightThread)
            DestroyTree(node->rightChild);
        delete node;
        node = nullptr;
    }
}

template <class T>
void ThreadedBinaryTree<T>::Preorder(const ThreadedTreeNode<T> *node) const
{
    if (node != head){
        Visit(node);
        if (!node->leftThread)
            Preorder(node->leftChild);
        if (!node->rightThread)
            Preorder(node->rightChild);
    }
}

template <class T>
void ThreadedBinaryTree<T>::Postorder(const ThreadedTreeNode<T> *node) const
{
    if (node != head){
        if (!node->leftThread)
            Postorder(node->leftChild);
        if (!node->rightThread)
            Postorder(node->rightChild);
        Visit(node);
    }
}

template <class T>
ThreadedInorderIterator<T>::ThreadedInorderIterator(ThreadedTreeNode<T> *cur)
{
    currentNode = cur;
}

template <class T>
T *ThreadedInorderIterator<T>::Next()
{
    ThreadedTreeNode<T> *temp = currentNode->rightChild;
    if (currentNode->rightThread){
        currentNode = temp;
    }else {
        while (!temp->leftThread) 
            temp = temp->leftChild;
        currentNode = temp;
    }
    return &currentNode->data;
}

template <class T>
T *ThreadedInorderIterator<T>::Previous()
{
    ThreadedTreeNode<T> *temp = currentNode->leftChild;
    if (currentNode->leftThread){
        currentNode = temp;
    }else {
        while (!temp->rightThread) 
            temp = temp->rightChild;
        currentNode = temp;
    }
    return &currentNode->data;
}

template <class T>
T &ThreadedInorderIterator<T>::operator*() const
{
    return currentNode->data;
}

template <class T>
T *ThreadedInorderIterator<T>::operator->() const
{
    return &currentNode->data;
}

template <class T>
bool ThreadedInorderIterator<T>::operator!=(const ThreadedInorderIterator<T> &rhs) const
{
    return currentNode != rhs.currentNode;
}
