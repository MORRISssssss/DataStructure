#include "String.h"

String::String(char *init = "", int m = 0)
{
    str = new char[m];
    copy(init, init + m, str);
}

bool String::operator==(String t)
{
    int len = Length();
    if (len != t.Length())
        return false;
    for (int i = 0; i < len; i++){
        if (str[i] != t.str[i])
            return false;
    }
    return true;
}

bool String::operator!()
{
    if (*str)
        return true;
    else
        return false;
}

int String::Length()
{
    int len = 0;
    char *temp = str;
    while (*temp){
        len++;
        temp++;
    }
    return len;
}

String String::Concat(String t)
{
    
}

String String::Substr(int i, int j)
{
}

int String::Find(String pat)
{
}

String String::Delete(int start, int length)
{
}

String String::CharDelete(char c)
{
}

int String::Compare(String y)
{
}

String& String::operator = (String t)
{
    int len = t.Length();
    char *temp = new char[len];
    copy(t.str, t.str + len, temp);
    delete [] str;
    str = temp;
    return *this;
}

void String::FailureFunction()
{
}

ostream& operator<<(ostream& os, String& t)
{

}

istream& operator>>(istream& is, String& t)
{

}