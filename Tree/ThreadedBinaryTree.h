#include <iostream>
using namespace std;
#ifndef THREADEDBINARYTREE_H
#define THREADEDBINARYTREE_H

template <class T> class ThreadedBinaryTree;
template <class T> class ThreadedInorderIterator;

template <class T>
class ThreadedTreeNode {
    friend class ThreadedBinaryTree<T>;
    friend class ThreadedInorderIterator<T>;
    public: 
        ThreadedTreeNode(T d = 0, bool leftT = false, ThreadedTreeNode<T>* left = nullptr, 
                                  bool rightT = false, ThreadedTreeNode<T>* right = nullptr);
    private:
        T data;
        ThreadedTreeNode <T> *leftChild;
        ThreadedTreeNode <T> *rightChild;
        bool leftThread;
        bool rightThread;
};

template<class T>
class ThreadedBinaryTree
{ 
    friend void SetupBinaryTree2(ThreadedBinaryTree<char> t);
    friend class ThreadedInorderIterator<T>;
    public:
        // constructor for an empty binary tree
        ThreadedBinaryTree(); 
        // destructor
        ~ThreadedBinaryTree();
        // copy constructor

        // traversal methods

        void Preorder() const;
        void Postorder() const;

        // insert r as the right child of s
        void InsertRight(ThreadedTreeNode<T> *s, ThreadedTreeNode<T> *r);
        // insert l as the left child of s
        void InsertLeft(ThreadedTreeNode<T> *s, ThreadedTreeNode<T> *l);
        
        T Visit(const ThreadedTreeNode<T>* node, bool print = true) const;

        ThreadedTreeNode<T> RootNode() const;

        ThreadedInorderIterator<T> Begin() const;
        ThreadedInorderIterator<T> End() const;

    private:
        ThreadedTreeNode<T> *head;
        void DestroyTree(ThreadedTreeNode<T>*& node);
        void Preorder(const ThreadedTreeNode<T>* node) const;
        void Postorder(const ThreadedTreeNode<T>* node) const;

    
};

template <class T> 
class ThreadedInorderIterator
{
    friend class ThreadedBinaryTree<T>;
    public:
        ThreadedInorderIterator(ThreadedTreeNode<T> *cur);
        T* Next();
        T* Previous();
        T& operator*() const;
        T* operator->() const;
        bool operator!=(const ThreadedInorderIterator<T>& rhs) const;
    private:
        ThreadedTreeNode<T> *currentNode;
};

#endif