#include "ThreadedBinaryTree.cpp"

void SetupBinaryTree2(ThreadedBinaryTree<char> t)
{
    t.~ThreadedBinaryTree();
    ThreadedTreeNode<char> *A = new ThreadedTreeNode<char>('A');
    t.InsertLeft(t.head, A);
    ThreadedTreeNode<char> *B = new ThreadedTreeNode<char>('B');
    t.InsertLeft(A, B);
    ThreadedTreeNode<char> *C = new ThreadedTreeNode<char>('C');
    t.InsertRight(A, C);
    ThreadedTreeNode<char> *D = new ThreadedTreeNode<char>('D');
    t.InsertLeft(B, D);
    ThreadedTreeNode<char> *E = new ThreadedTreeNode<char>('E');
    t.InsertRight(B, E);
    ThreadedTreeNode<char> *F = new ThreadedTreeNode<char>('F');
    t.InsertLeft(C, F);
    ThreadedTreeNode<char> *G = new ThreadedTreeNode<char>('G');
    t.InsertRight(C, G);
    ThreadedTreeNode<char> *H = new ThreadedTreeNode<char>('H');
    t.InsertLeft(D, H);
    ThreadedTreeNode<char> *J = new ThreadedTreeNode<char>('J');
    t.InsertRight(D, J);

}


int main()
{
    ThreadedBinaryTree<char> tree;
    SetupBinaryTree2(tree);
    // (a) Forward iterator by sequencing through the nodes in inorder.
    for (ThreadedInorderIterator<char> i = tree.Begin(); i != tree.End(); i.Next())
        cout << *i << " ";
    cout << endl;

    // (b) Traverse a threaded binary tree in postorder.
    tree.Postorder();
    cout << endl;

    // (c) Traverse a threaded binary tree in preorder.
    tree.Preorder();
    cout << endl;

    // (d) Insert a new node r as the right child of node s in a threaded binary tree. 
    // (e)Insert a new node l as the left child of node s in a threaded binary tree. 
    // Both (d) and (e) are showed above in SetupBinaryTree2 function.

    return 0;
}