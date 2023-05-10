#include <iostream>
#include "CircularList.h"
using namespace std;

template <class T>
CircularList<T>::CircularList()
{
    first = 0;
}

template <class T>
CircularList<T>::~CircularList()
{
}

template <class T>
inline bool CircularList<T>::IsEmpty() const
{
    return first == 0;
}

template <class T>
int CircularList<T>::Size() const
{
    if (IsEmpty()){
        return 0;
    }else if (first->link == first){
        return 1;
    }else{
        Node<T> *current = first;
        int count = 1;
        while (current->link != first){
            current = current->link;
            count++;
        }
        return count;
    }
}

template <class T>
void CircularList<T>::Empty()
{
    if (!IsEmpty()){
        if (first->link == first){
            delete first;
            first = 0;
        }else{
            Node<T> *current = first->link;
            Node<T> *next = current->link;
            while (next != first){
                delete current;
                current = next;
                next = current->link;
            }
            delete first;
            first = 0;
        }
    }
}

template <class T>
Node<T> *CircularList<T>::IndexPointer(const int i) const
{
    if (IsEmpty())
        return 0;
    Node<T> *current = first;
    int count = 0;
    while (current->link != first && count < i){
        current = current->link;
        count++;
    }
    if (count == i)
        return current;
    else
        return 0;
}

template <class T>
void CircularList<T>::InsertFront(const T &e)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = e;
    if (IsEmpty()){
        first = newNode;
        newNode->link = first;
    }else{
        newNode->link = first;
        Node<T> *current = first;
        while (current->link != first)
            current = current->link;
        current->link = newNode;
        first = newNode;
    }
}

template <class T>
void CircularList<T>::InsertBack(const T &e)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = e;
    if (IsEmpty()){
        first = newNode;
        newNode->link = first;
    }else{
        Node<T> *current = first;
        while (current->link != first)
            current = current->link;
        current->link = newNode;
        newNode->link = first;
    }
}

template <class T>
void CircularList<T>::DeleteFirst()
{
    if (IsEmpty()){
        throw "Cannot delete from empty list.";
    }else if (first->link == first){
        delete first;
        first = 0;
    }else{
        Node<T> *current = first;
        while (current->link != first)
            current = current->link;
        current->link = first->link;
        delete first;
        first = current->link;
    }
}

template <class T>
void CircularList<T>::DeleteBack()
{
    if (IsEmpty()){
        throw "Cannot delete from empty list.";
    }else if (first->link == first){
        delete first;
        first = 0;
    }else{
        Node<T> *current = first;
        while (current->link->link != first)
            current = current->link;
        delete current->link;
        current->link = first;
    }
}

template <class T>
void CircularList<T>::DeleteOddNode()
{
    if (IsEmpty()){
        throw "Cannot delete from empty list.";
    }else if (first->link == first){
        delete first;
        first = 0;
    }else{
        Node<T> *current = first->link;
        Node<T> *prev = current;
        int count = 2;
        while (current->link != first){
            if (count % 2 == 0){
                prev = current;
                current = current->link;
                count++;
            }else{
                prev->link = current->link;
                delete current;
                current = prev->link;
                count++;
            }
        }
        if (count % 2 == 0){
            current->link = first->link;
            delete first;
            first = current->link;
        }else{
            prev->link = first->link;
            delete current;
            delete first;
            first = prev->link;
        }
    }
}

template <class T>
void CircularList<T>::Deconcatenate(const Node<T> *split, CircularList<T> &list1, CircularList<T> &list2)
{
    Node<T> *current = first;
    if (IsEmpty()){
        throw "Cannot deconcatenate an empty list.";
    }else if (split == first){
        list1.Empty();
        list2.Empty();
        list2.first = first;
    }else{
        list1.Empty();
        list2.Empty();
        while (current->link != first && current->link != split)
            current = current->link;
        if (current->link == split){
            list2.first = current->link;
            list1.first = first;
            current->link = first;
            Node<T> *current2 = list2.first;
            while (current2->link != first)
                current2 = current2->link;
            current2->link = list2.first;
        }
    }
    first = 0;
}

template <class T>
CircularList<T> CircularList<T>::Merge(CircularList<T> &list2)
{
    CircularList<T> list3;
    if (IsEmpty()){
        list3.first = list2.first;
    }else if (list2.IsEmpty()){
        list3.first = first;
    }else {
        list3.first = first;
        Node<T> *current1 = first->link;
        Node<T> *current2 = list2.first->link;
        list3.first->link = list2.first;
        Node<T> *current3 = list3.first->link;
        while (current1 != first && current2 != list2.first){
            current3->link = current1;
            current3 = current3->link;
            current1 = current1->link;
            current3->link = current2;
            current3 = current3->link;
            current2 = current2->link;
        }
        while (current1 != first){
            current3->link = current1;
            current3 = current3->link;
            current1 = current1->link;
        }
        while (current2 != list2.first){
            current3->link = current2;
            current3 = current3->link;
            current2 = current2->link;
        }
        current3->link = list3.first;
    }
    first = 0;
    list2.first = 0;
    return list3;
}

template <class T>
CircularList<T> &CircularList<T>::operator=(const CircularList list2)
{
    Empty();
    if (!list2.IsEmpty()){
        first = new Node<T>;
        first->data = list2.first->data;
        Node<T> *current1 = first;
        Node<T> *current2 = list2.first->link;
        while (current2 != list2.first){
            Node<T> *newNode = new Node<T>;
            newNode->data = current2->data;
            current1->link = newNode;
            current1 = current1->link;
            current2 = current2->link;
        }
        current1->link = first;
    }
    
    return *this;
}

template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& list)
{
    if (list.IsEmpty()){
        os << "Empty";
    }else{
        Node<T> *current = list.first;
        os << current->data;
        current = current->link;
        while (current != list.first){
            os << " " << current->data;
            current = current->link;
        }
    }
    return os;
}

template <class T>
CircularHeaderList<T>::CircularHeaderList()
{
    head = new Node<T>;
    head->link = head;
}

template <class T>
CircularHeaderList<T>::~CircularHeaderList()
{
}

template <class T>
inline bool CircularHeaderList<T>::IsEmpty() const
{
    return head->link == head;
}

template <class T>
int CircularHeaderList<T>::Size() const
{
    int count = 0;
    Node<T> *current = head;
    while (current->link != head){
        current = current->link;
        count++;
    }
    return count;
}

template <class T>
void CircularHeaderList<T>::Empty()
{
    if (!IsEmpty()){
        Node<T> *current = head->link;
        Node<T> *next = current->link;
        while (next != head){
            delete current;
            current = next;
            next = next->link;
        }
        delete current;
        head->link = head;
    }
}

template <class T>
Node<T> *CircularHeaderList<T>::IndexPointer(const int i) const
{
    Node<T> *current = head;
    int count = -1;
    while (current->link != head && count < i){
        current = current->link;
        count++;
    }
    if (count == i)
        return current;
    else
        return 0;
}

template <class T>
void CircularHeaderList<T>::InsertFront(const T &e)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = e;
    newNode->link = head->link;
    head->link = newNode;
}

template <class T>
void CircularHeaderList<T>::InsertBack(const T &e)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = e;
    Node<T> *current = head;
    while (current->link != head)
        current = current->link;
    current->link = newNode;
    newNode->link = head;
}

template <class T>
void CircularHeaderList<T>::DeleteFirst()
{
    if (IsEmpty()){
        throw "Cannot delete from empty list.";
    }else{
        Node<T> *delNode = head->link;
        head->link = head->link->link;
        delete delNode;
    }
}

template <class T>
void CircularHeaderList<T>::DeleteBack()
{
    if (IsEmpty()){
        throw "Cannot delete from empty list.";
    }else{
        Node<T> *current = head;
        while (current->link->link != head)
            current = current->link;
        Node<T> *delNode = current->link;
        current->link = head;
        delete delNode;
    }
}

template <class T>
void CircularHeaderList<T>::DeleteOddNode()
{
    if (IsEmpty()){
        throw "Cannot delete from empty list.";
    }else{
        Node<T> *current = head;
        Node<T> *delNode = head->link;
        while (current->link != head && current->link->link != head){
            delNode = current->link;
            current->link = delNode->link;
            delete delNode;
            current = current->link;
        }
        if (current->link->link == head){
            delete current->link;
        }
        current->link = head;
    }
}

template <class T>
void CircularHeaderList<T>::Deconcatenate(const Node<T> *split, CircularHeaderList<T> &list1, CircularHeaderList<T> &list2)
{
    Node<T> *current = head;
    if (IsEmpty()){
        throw "Cannot deconcatenate an empty list.";
    }else{
        list1.Empty();
        list2.Empty();
        while (current->link != head && current->link != split)
            current = current->link;
        if (current->link == split){
            list2.head->link = current->link;
            list1.head->link = head->link;
            current->link = list1.head;
            Node<T> *current2 = list2.head;
            while (current2->link != head)
                current2 = current2->link;
            current2->link = list2.head;
        }
    }
    head->link = head;
}

template <class T>
CircularHeaderList<T> CircularHeaderList<T>::Merge(CircularHeaderList<T> &list2)
{
    CircularHeaderList<T> list3;
    Node<T> *current1 = head->link;
    Node<T> *current2 = list2.head->link;
    Node<T> *current3 = list3.head;
    while (current1 != head && current2 != list2.head){
        current3->link = current1;
        current3 = current3->link;
        current1 = current1->link;
        current3->link = current2;
        current3 = current3->link;
        current2 = current2->link;
    }
    while (current1 != head){
        current3->link = current1;
        current3 = current3->link;
        current1 = current1->link;
    }
    while (current2 != list2.head){
        current3->link = current2;
        current3 = current3->link;
        current2 = current2->link;
    }
    current3->link = list3.head;
    head->link = head;
    list2.head->link = list2.head;
    return list3;
}

template <class T>
CircularHeaderList<T> &CircularHeaderList<T>::operator=(const CircularHeaderList list2)
{
    Empty();
    Node<T> *current1 = head;
    Node<T> *current2 = list2.head;
    while (current2->link != list2.head){
        current2 = current2->link;
        Node<T> *newNode = new Node<T>;
        newNode->data = current2->data;
        current1->link = newNode;
        current1 = current1->link;
    }
    current1->link = head;
    return *this;
}

template <class T>
ostream& operator<<(ostream& os, const CircularHeaderList<T>& list)
{
    if (list.IsEmpty()){
        os << "Empty";
    }else{
        Node<T> *current = list.head->link;
        os << current->data;
        current = current->link;
        while (current != list.head){
            os << " " << current->data;
            current = current->link;
        }
    }
    return os;
}