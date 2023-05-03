#include <iostream>
using namespace std;
#ifndef STRING_H
#define STRING_H

class String
{
public:
    // constructor using input string init of length m
    String(const char *init, const int m);
    //equality test
    bool operator == (const String t) const;
    // empty test, true or false
    bool operator!( ) const; 
    // get the number of characters of *this
    int Length( ) const;
    // concatenation with another string t
    String Concat(const String t) const;  
    // generate a substring i~i+j-1
    String Substr(const int start, const int length) const;  
    // Return an index i such that pat matches the substring
    // of the object begins at position i. Return -1 if pat
    // is empty or not a substring of the object
    int Find(String pat) const;
    // remove length characters beginning at start
    String Delete(const int start, const int length) const; 
    // returns the string with all occurrence of c removed.
    String CharDelete(const char c) const;
    // compare two strings of letters of alphabet.
    int Compare(const String y) const; 
    String& operator = (const String t);
    friend ostream& operator<<(ostream& os, const String& t);
    friend istream& operator>>(istream& is, String& t);

private:
    char *str;
    int *f;
    void FailureFunction();
};


#endif