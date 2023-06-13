#include "BinarySearchTree.h"

template <class K, class E>
Pair<K, E>::Pair(const K k, const E e)
{
    first = k;
    second = e;
}

template <class K, class E>
ostream& operator<<(ostream& os, const Pair<K, E>& rhs)
{
    if (&rhs == nullptr)
        os << "null Pair";
    else
        os << rhs.first << ":" << rhs.second;
    return os;
}

template <class T>
TreeNode<T>::TreeNode(T d, TreeNode<T>* left, TreeNode<T>* right)
{
    data = d;
    leftChild = left;
    rightChild = right;
}

template <class K, class E>
BST<K, E>::BST()
{
    root = nullptr;
}

template <class K, class E>
BST<K, E>::~BST()
{
    DestroyTree(root);
}

template <class K, class E>
bool BST<K, E>::IsEmpty() const
{
    return root == nullptr;
}

template <class K, class E>
Pair<K, E> *BST<K, E>::Get(const K &k) const
{
    TreeNode<Pair<K, E>> *currentNode = root;
    while (currentNode) {
        if (k < currentNode->data.first)
            currentNode = currentNode->leftChild;
        else if (k > currentNode->data.first)
            currentNode = currentNode->rightChild;
        else 
            return &currentNode->data;
    } 
    // no matching Pair
    return 0;

}

template <class K, class E>
void BST<K, E>::Insert(const Pair<K, E> &thePair)
{
    TreeNode<Pair<K, E>> *p = root, *pp = nullptr;
    while (p != nullptr) {
        pp = p;
        if (thePair.first < p->data.first) 
            p = p->leftChild;
        else if(thePair.first > p->data.first)
            p = p->rightChild;
        else { // duplicate, update associated element
            p->data.second = thePair.second; 
            return;
        }
    }
    // perform insertion
    p = new TreeNode<Pair<K, E>>(thePair);
    if (root != nullptr) // tree is nonempty
        if (thePair.first < pp->data.first) 
            pp->leftChild = p;
        else 
            pp->rightChild = p;
    else 
        root = p;
}

template <class K, class E>
void BST<K, E>::Delete(const K &k)
{
    root = Delete(root, k);
}

template <class K, class E>
Pair<K, E> *BST<K, E>::RankGet(int r) const
{
    TreeNode<Pair<K, E>> *currentNode = root;
    while (currentNode != nullptr){
        int leftSize = LeftSize(currentNode);
        if (r < leftSize)
            currentNode = currentNode->leftChild;
        else if (r > leftSize){ 
            r -= leftSize;
            currentNode = currentNode->rightChild;
        }
        else 
            return &currentNode->data;
    }
    return 0;
}

template <class K, class E>
void BST<K, E>::Split(const K &k, BST<K, E> &small, Pair<K, E> *&mid, BST<K, E> &big)
{
    if (root == nullptr) {// empty tree
        small.root = big.root = nullptr; 
        return; 
    }
    // create temporary header nodes for small and big
    TreeNode<Pair<K, E>> *sHead = new TreeNode<Pair<K, E>>,
    *s = sHead,
    *bHead = new TreeNode<Pair<K, E>>,
    *b = bHead,
    *currentNode = root;
    while (currentNode != nullptr) {
        if (k < currentNode->data.first){ // case 1
            b->leftChild = currentNode;
            b = currentNode; currentNode = currentNode->leftChild;
        } else if (k > currentNode->data.first) { // case 2
            s->rightChild = currentNode;
            s = currentNode; currentNode = currentNode->rightChild;
        } else { // case 3 
            s->rightChild = currentNode->leftChild;
            b->leftChild = currentNode->rightChild;
            small.root = sHead->rightChild; 
            delete sHead;
            big.root = bHead->leftChild; 
            delete bHead;
            mid = new Pair<K, E>(currentNode->data.first, currentNode->data.second);
            delete currentNode;
            root = nullptr;
            return;
        }
    }// no Pair with key k
    s->rightChild = b->leftChild = nullptr;
    small.root = sHead->rightChild; 
    delete sHead;
    big.root = bHead->leftChild; 
    delete bHead;
    mid = nullptr;
    return;

}

template <class K, class E>
void BST<K, E>::Inorder() const
{
    Inorder(root);
}

template <class K, class E>
void BST<K, E>::DestroyTree(TreeNode<Pair<K, E>> *&node)
{
    if (node != nullptr) {
        DestroyTree(node->leftChild);
        DestroyTree(node->rightChild);
        delete node;
        node = nullptr;
    }
}

template <class K, class E>
int BST<K, E>::LeftSize(const TreeNode<Pair<K, E>> *node) const
{
    return 1 + NodeSize(node->leftChild);
}

template <class K, class E>
int BST<K, E>::NodeSize(const TreeNode<Pair<K, E>> *node) const
{
    if (node == nullptr)
        return 0;
    else
        return NodeSize(node->leftChild) + 1 + NodeSize(node->rightChild);
}

template <class K, class E>
TreeNode<Pair<K, E>>* BST<K, E>::Delete(TreeNode<Pair<K, E>> *&node, const K &k)
{
    if (node == nullptr)
        return nullptr;
    if (k < node->data.first)
        node->leftChild = Delete(node->leftChild, k);
    else if (k > node->data.first)
        node->rightChild = Delete(node->rightChild, k);
    else {
        if (node->leftChild == nullptr) {
            TreeNode<Pair<K, E>> *temp = node->rightChild;
            delete node;
            return temp;
        } else if (node->rightChild == nullptr) {
            TreeNode<Pair<K, E>> *temp = node->leftChild;
            delete node;
            return temp;
        } else {
            TreeNode<Pair<K, E>> *temp = node->leftChild;
            while (temp->rightChild != nullptr)
                temp = temp->rightChild;
            node->data = temp->data;
            node->leftChild = Delete(node->leftChild, temp->data.first);
        }
    }
    return node;
}

template <class K, class E>
void BST<K, E>::Inorder(const TreeNode<Pair<K, E>> *node) const
{
    if (node != nullptr){
        Inorder(node->leftChild);
        Visit(node);
        Inorder(node->rightChild);
    }
}

template <class K, class E>
void BST<K, E>::Visit(const TreeNode<Pair<K, E>> *node) const
{
    cout << node->data.first << ":" << node->data.second << " ";
}
