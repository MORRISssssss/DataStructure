#include <iostream>
using namespace std;
#ifndef STRING_H
#define STRING_H

class String
{
public:
    // constructor using input string init of length m
    String(char *init, int m);
    //equality test
    bool operator == (String t);
    // empty test, true or false
    bool operator!( ); 
    // get the number of characters of *this
    int Length( );
    // concatenation with another string t
    String Concat(String t);  
    // generate a substring i~i+j-1
    String Substr(int i, int j);  
    // Return an index i such that pat matches the substring
    // of the object begins at position i. Return -1 if pat
    // is empty or not a substring of the object
    int Find(String pat);
    // remove length characters beginning at start
    String Delete(int start, int length); 
    // returns the string with all occurrence of c removed.
    String CharDelete(char c);
    // compare two strings of letters of alphabet.
    int Compare(String y); 
    String& operator = (String t);
    friend ostream& operator<<(ostream& os, String& t);
    friend istream& operator>>(istream& is, String& t);

private:
    char *str;
    int *f;
    void FailureFunction();
};


#endif