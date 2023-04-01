#include "String.h"

String::String(char *init = {}, int m = 0)
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
    int lenA = Length();
    int lenB = t.Length();
    char *temp = new char[lenA + lenB];
    for (int i = 0; i < lenA; i++)
        temp[i] = str[i];
    for (int i = 0; i < lenB; i++)
        temp[lenA + i] = t.str[i];
        
    String s(temp, lenA + lenB);
    delete [] temp;
    return s;
}

String String::Substr(int i, int j)
{
    char *temp = new char[j];
    copy(str + i, str + i + j, temp);
    String s(temp, j);
    delete [] temp;
    return s;

}

int String::Find(String pat)
{
    FailureFunction();
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

String String::Delete(int start, int length)
{
    int lenS = Length();
    char *front = new char[start];
    char *back = new char[lenS - start - length];
    copy(str, str + start, front);
    copy(str + start + length, str + lenS, back);
    String Front(front, start);
    String Back(back, lenS - start - length);
    delete [] front;
    delete [] back;
    return Front.Concat(Back);
}

String String::CharDelete(char c)
{
    String s;
    int start = 0;
    for (int i = 0; i < Length(); i++){
        if (str[i] == c){
            s.Concat(Substr(start, i - start));
            start = i + 1;
        }
    }
    s.Concat(Substr(start, Length() - start - 1));
    return s;
}

int String::Compare(String y)
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
    int lengthP = Length();
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

ostream& operator<<(ostream& os, String& t)
{
    os << t.str;
    return os;
}

istream& operator>>(istream& is, String& t)
{
    const int SIZE = 10000;
    char temp[SIZE];
    is.getline(temp, SIZE);
    t.str = temp;
    return is;
}