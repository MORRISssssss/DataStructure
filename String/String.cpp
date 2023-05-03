#include "String.h"

char null = '\0';

String::String(const char *init = &null, const int m = 0)
{
    str = new char[m + 1];
    copy(init, init + m + 1 , str);
}

bool String::operator ==(const String t) const
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

bool String::operator!() const
{
    if (*str)
        return true;
    else
        return false;
}

int String::Length() const
{
    int len = 0;
    char *temp = str;
    while (*temp){
        len++;
        temp++;
    }
    return len;
}

String String::Concat(const String t) const
{
    int lenA = Length();
    int lenB = t.Length();
    char *temp = new char[lenA + lenB + 1];
    copy(str, str + lenA + 1, temp);
    copy(t.str, t.str + lenB + 1, temp + lenA);
    String s(temp, lenA + lenB);
    delete [] temp;
    return s;
}

String String::Substr(const int start, const int length) const
{
    char *temp = new char[length + 1];
    copy(str + start, str + start + length, temp);
    temp[length] = '\0';
    String s(temp, length);
    delete [] temp;
    return s;

}

int String::Find(String pat) const
{
    pat.FailureFunction();
    int posP = 0, posS = 0;
    int lengthP = pat.Length(), lengthS = Length();
    while (posP < lengthP && posS < lengthS){
        if (pat.str[posP] == str[posS]) { 
            posP++; 
            posS++; 
        }else{
            if (posP == 0) 
                posS++;
            else 
                posP = pat.f[posP -1] + 1;
        }
    }
    if (posP < lengthP) 
        return -1;
    else // Textbook stops pattern matching once a match is found
        return posS-lengthP;

}

String String::Delete(const int start, const int length) const
{
    int lenS = Length();
    String front, back;
    front = Substr(0, start);
    back = Substr(start + length, lenS - start - length);
    return front.Concat(back);
}

String String::CharDelete(const char c) const
{
    String s;
    s.str = new char[Length() + 1];
    copy(str, str + Length() + 1, s.str);
    int i = 0;
    while (s.str[i]){
        if (s.str[i] == c){
            s = s.Delete(i, 1);
        }else {
            i++;
        }
    }
    return s;
}

int String::Compare(const String y) const
{
    int lenX = Length();
    int lenY = y.Length();
    if (lenX < lenY){
        for (int i = 0; i < lenX; i++){
            if (str[i] < y.str[i])
                return -1;
            else if (str[i] > y.str[i])
                return 1;
        }
        return -1;
    }else if (lenX > lenY){
        for (int i = 0; i < lenY; i++){
           if (str[i] < y.str[i])
                return -1;
            else if (str[i] > y.str[i])
                return 1;
        }
        return 1;
    }else{
        for (int i = 0; i < lenY; i++){
           if (str[i] < y.str[i])
                return -1;
            else if (str[i] > y.str[i])
                return 1;
        }
        return 0;
    }
}

String& String::operator = (const String t)
{
    int len = t.Length();
    char *temp = new char[len + 1];
    copy(t.str, t.str + len + 1, temp);
    delete [] str;
    str = temp;
    return *this;
}

void String::FailureFunction()
{
    int lengthP = Length();
    f = new int[lengthP];
    f[0] = -1;
    for (int j = 1; j < lengthP; j++){
        int i = f[j - 1];
        while ((str[j] != str[i + 1]) && (i >= 0)) 
            i = f[i];
        if (str[j] == str[i + 1]) 
            f[j] = i + 1;
        else
            f[j] = -1;
    }
}

ostream& operator<<(ostream& os, const String& t)
{
    os << t.str;
    return os;
}

istream& operator>>(istream& is, String& t)
{
    const int SIZE = 10000;
    char *iLine = new char[SIZE];
    is.getline(iLine, SIZE);
    delete [] t.str;
    t.str = iLine;
    return is;
}