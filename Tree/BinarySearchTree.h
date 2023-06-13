#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

template <class K, class E>
struct Pair
{
    K first;
    E second;
    Pair(K k = 0, E e = 0);
    template <class A, class B>
    friend ostream& operator<<(ostream& os, const Pair<A, B>& rhs);
};

template <class K, class E>
class Dictionary {
    public: 
        // return true if dictionary is empty
        virtual bool IsEmpty() const = 0; 
        // return pointer to the Pair w. specified key 
        virtual Pair<K, E>* Get(const K&) const = 0;
        // insert the given Pair; if key ia a duplicate, update
        // associate element
        virtual void Insert(const Pair <K, E>&) = 0; 
        // delete Pair w. specified key
        virtual void Delete(const K&) = 0; 
};

template <class K, class E> class BST;

template <class T>
class TreeNode {
    template <class K, class E> 
    friend class BST;
    public: 
        TreeNode(T d = 0, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr);
    private:
        T data;
        TreeNode <T> *leftChild;
        TreeNode <T> *rightChild;
};

template <class K, class E>
class BST: public Dictionary<K, E> {
    public:
        BST(); 
        ~BST();
        bool IsEmpty() const;
        Pair<K, E>* Get(const K& k) const;
        void Insert(const Pair<K, E>& thePair);
        void Delete(const K& k);
        Pair<K, E>* RankGet(int r) const;
        void Split(const K& k, BST<K, E>& small, Pair<K, E>*& mid, BST<K, E>& big);
        void Inorder() const;
    private:
        TreeNode<Pair<K, E>> *root;
        void DestroyTree(TreeNode<Pair<K, E>>*& node);
        int LeftSize(const TreeNode<Pair<K, E>>* node) const;
        int NodeSize(const TreeNode<Pair<K, E>>* node) const;
        TreeNode<Pair<K, E>>* Delete(TreeNode<Pair<K, E>>*& node, const K& k);
        void Inorder(const TreeNode<Pair<K, E>>* node) const;
        void Visit(const TreeNode<Pair<K, E>>* node) const;
};

#endif