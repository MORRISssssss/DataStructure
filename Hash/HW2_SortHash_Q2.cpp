#include "Hash.cpp"

int main()
{
    char test_1[] = "mickeymouse";
    char test_2[] = "money";
    char test_3[] = "alpha";
    char test_4[] = "beta";
    char test_5[] = "gamma";
    char test_6[] = "theta";
    char test_7[] = "computer";
    char test_8[] = "minus";
    char test_9[] = "add";
    char test_10[] = "cross";
    char test_11[] = "nothing";
    char test_12[] = "is";
    char test_13[] = "wrong";
    LinearProbing linearprobing;
    ChainList chainlist;
    cout << "Linear Probing:" << endl;
    linearprobing.Insert(test_1);
    linearprobing.Insert(test_2);
    linearprobing.Insert(test_3);
    linearprobing.Insert(test_4);
    linearprobing.Insert(test_5);
    linearprobing.Insert(test_6);
    linearprobing.Insert(test_7);
    linearprobing.Insert(test_8);
    linearprobing.Insert(test_9);
    linearprobing.Insert(test_10);
    cout << "Table: " << endl;
    linearprobing.Print();
    cout << "Test: " << endl;
    cout << "Test 1: "<< test_8 << '\t' << "Result: " << (linearprobing.Search(test_8) ? "Yes" : "No") << endl;
    cout << "Test 2: "<< test_3 << '\t' << "Result: " << (linearprobing.Search(test_3) ? "Yes" : "No") << endl;
    cout << "Test 3: "<< test_5 << '\t' << "Result: " << (linearprobing.Search(test_5) ? "Yes" : "No") << endl;
    cout << "Test 4: "<< test_11 << '\t' << "Result: " << (linearprobing.Search(test_11) ? "Yes" : "No") << endl;
    cout << "Test 5: "<< test_12 << '\t' << "Result: " << (linearprobing.Search(test_12) ? "Yes" : "No") << endl;
    cout << "Test 6: "<< test_13 << '\t' << "Result: " << (linearprobing.Search(test_13) ? "Yes" : "No") << endl;
    cout << endl;
    
    cout << "Hash table with chaining: " << endl;
    chainlist.Insert(test_1);
    chainlist.Insert(test_2);
    chainlist.Insert(test_3);
    chainlist.Insert(test_4);
    chainlist.Insert(test_5);
    chainlist.Insert(test_6);
    chainlist.Insert(test_7);
    chainlist.Insert(test_8);
    chainlist.Insert(test_9);
    chainlist.Insert(test_10);
    cout << "Table: " << endl;
    chainlist.Print();
    cout << "Test: " << endl;
    cout << "Test 1: "<< test_8 << '\t' << "Result: " << (chainlist.Search(test_8) ? "Yes" : "No") << endl;
    cout << "Test 2: "<< test_3 << '\t' << "Result: " << (chainlist.Search(test_3) ? "Yes" : "No") << endl;
    cout << "Test 3: "<< test_5 << '\t' << "Result: " << (chainlist.Search(test_5) ? "Yes" : "No") << endl;
    cout << "Test 4: "<< test_11 << '\t' << "Result: " << (chainlist.Search(test_11) ? "Yes" : "No") << endl;
    cout << "Test 5: "<< test_12 << '\t' << "Result: " << (chainlist.Search(test_12) ? "Yes" : "No") << endl;
    cout << "Test 6: "<< test_13 << '\t' << "Result: " << (chainlist.Search(test_13) ? "Yes" : "No") << endl;
}