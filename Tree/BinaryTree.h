#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T> class BinaryTree;

template <class T>
class TreeNode {
    friend class BinaryTree <T>;
    public: 
        TreeNode(T d = 0, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr);
    private:
        T data;
        TreeNode <T> *leftChild;
        TreeNode <T> *rightChild;
};

// objects: A finite set of nodes either empty or consisting
// of a root node, left BinaryTree and right BinaryTree
template<class T>
class BinaryTree
{ 
    public:
        // constructor for an empty binary tree
        BinaryTree(); 
        // return true iff the binary tree is empty  
        inline bool IsEmpty() const;   
        // constructor given the root item and left subtrees bt1 and right subtree bt2
        BinaryTree(const BinaryTree<T>& bt1, const T& item, const BinaryTree<T>& bt2);   
        // return the left subtree
        BinaryTree<T> LeftSubtree(); 
        // return the right subtree
        BinaryTree<T> RightSubtree();
        // return the data in the root node of *this
        T RootData() const;  
        // destructor
        ~BinaryTree();
        // copy constructor
        BinaryTree(const BinaryTree<T>& bt);
        BinaryTree<T>& operator=(const BinaryTree<T>& bt);
        // traversal methods

        void Inorder() const;
        void Preorder() const;
        void Postorder() const;
        void LevelOrder() const;
        void NonrecInorder() const;
        void NoStackInorder() const;
        
        T Visit(const TreeNode<T>* node, bool print = true) const;
        bool operator==(const BinaryTree& bt) const;
        
        static BinaryTree<char> SetupBinaryTree1();
        static BinaryTree<char> SetupBinaryTree2();

    private:
        TreeNode <T> *root;
        void DestroyTree(TreeNode<T>*& node);
        void CopyTree(TreeNode<T>*& copy, const TreeNode<T>* other);
        void Inorder(const TreeNode<T>* node) const;
        void Preorder(const TreeNode<T>* node) const;
        void Postorder(const TreeNode<T>* node) const;
        void Inorder(const TreeNode<T>* node, stack<T>& buff) const;
    
};


#endif