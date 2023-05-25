#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
    BinaryTree<char> t1 = BinaryTree<char>::SetupBinaryTree1();
    BinaryTree<char> t2 = BinaryTree<char>::SetupBinaryTree2();
    // inorder
    t1.Inorder();
    cout << endl;
    // levelorder
    t2.LevelOrder();
    cout << endl;
    // left, right subtree
    BinaryTree<char> t3 = t1.LeftSubtree();
    BinaryTree<char> t4 = t1.RightSubtree();
    // preorder
    t3.Preorder();
    cout << endl;
    // postorder
    t4.Postorder();
    cout << endl;
    // root data
    cout << t1.RootData() << endl;
    // copy constructor
    BinaryTree<char> t5(t1);
    // non-recursive inorder
    t5.NonrecInorder();
    cout << endl;
    // no stack inorder
    t5.NoStackInorder();
    cout << endl;
    // operator==
    cout << (int)(t5 == t1) << endl;
    cout << (int)(t5 == t2) << endl;

}