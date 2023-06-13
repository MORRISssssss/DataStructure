#include "BinarySearchTree.cpp"

int main()
{
    BST<int, char> bst;
    int key[13] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};

    for (int i = 0; i < 13; i++){
        Pair<int, char> p(key[i], 'A' + i);
        bst.Insert(p);
    }
    bst.Inorder();
    cout << endl;

    cout << *bst.Get(80) << endl;
    cout << *bst.RankGet(5) << endl;

    bst.Delete(10);
    bst.Inorder();
    cout << endl;
    
    bst.Delete(60);
    bst.Inorder();
    cout << endl;
    
    bst.Delete(50);
    bst.Inorder();
    cout << endl;
    
    BST<int, char> small, big;
    Pair<int, char> *mid;
    bst.Split(30, small, mid, big);
    cout << *mid << endl;
    small.Inorder();
    cout << endl;
    big.Inorder();
    cout << endl;

    return 0;
}