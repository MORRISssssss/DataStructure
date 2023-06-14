#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
List<T>::List() 
{
    first = nullptr;
}

template <class T>
List<T>::~List() 
{
    Node<T>* current = first;
    while (current != nullptr) {
        Node<T>* next = current->link;
        delete current;
        current = next;
    }
    first = nullptr;
}

template <class T>
bool List<T>::IsEmpty() const
{
    return first == nullptr;
}

template <class T>
int List<T>::Size() const
{
    Node<T>* temp = first;
    int count = 0;

    while (temp != nullptr){
        temp = temp->link;
        count++;
    }

    return count;
}

template <class T>
void List<T>::InsertFront(const T& e) 
{
    Node<T>* newNode = new Node<T>;
    newNode->data = e;
    newNode->link = first;
    first = newNode;
}

template <class T>
void List<T>::InsertBack(const T& e) 
{
    Node<T>* newNode = new Node<T>;
    newNode->data = e;
    newNode->link = nullptr;
    
    if (first == nullptr) {
        first = newNode;
    } else {
        Node<T>* temp = first;
        while (temp->link != nullptr) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

template <class T>
void List<T>::Concatenate(List<T>& b) 
{
    if (first == nullptr) {
        first = b.first;
    } else {
        Node<T>* temp = first;
        while (temp->link != nullptr) {
            temp = temp->link;
        }
        temp->link = b.first;
    }
    b.first = nullptr;
}

template <class T>
void List<T>::Reverse() 
{
    Node<T>* prev = nullptr;
    Node<T>* current = first;
    Node<T>* next = nullptr;
    
    while (current != nullptr) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    
    first = prev;
}

template <class T>
void List<T>::DeleteFront() 
{
    if (first == nullptr) {
        return;
    }
    
    Node<T>* temp = first;
    first = first->link;
    delete temp;
}

template <class T>
void List<T>::DeleteBack() 
{
    if (first == nullptr) {
        return;
    }
    
    if (first->link == nullptr) {
        delete first;
        first = nullptr;
        return;
    }
    
    Node<T>* prev = nullptr;
    Node<T>* current = first;
    
    while (current->link != nullptr) {
        prev = current;
        current = current->link;
    }
    
    prev->link = nullptr;
    delete current;
}

template <class T>
T& List<T>::Front() const
{
    if (first == nullptr) {
        throw out_of_range("List is empty");
    }
    
    return first->data;
}

template <class T>
T& List<T>::Back() const
{
    if (first == nullptr) {
        throw out_of_range("List is empty");
    }
    
    Node<T>* temp = first;
    while (temp->link != nullptr) {
        temp = temp->link;
    }
    
    return temp->data;
}

template <class T>
T& List<T>::Get(const int i) const
{
    if (i < 0) {
        throw out_of_range("Invalid index");
    }
    
    Node<T>* temp = first;
    int count = 0;
    
    while (temp != nullptr) {
        if (count == i) {
            return temp->data;
        }
        temp = temp->link;
        count++;
    }
    
    throw std::out_of_range("Index out of bounds");
}

template <class T>
void List<T>::Delete(const int i) 
{
    if (i == 0) {
        DeleteFront();
        return;
    }
    
    Node<T>* prev = nullptr;
    Node<T>* current = first;
    int count = 0;
    
    while (current != nullptr) {
        if (count == i) {
            prev->link = current->link;
            delete current;
            return;
        }
        prev = current;
        current = current->link;
        count++;
    }
    
    throw std::out_of_range("Index out of bounds");
}

template <class T>
void List<T>::Insert(const int i, const T& e) 
{
    if (i == 0) {
        InsertFront(e);
        return;
    }
    
    Node<T>* newNode = new Node<T>;
    newNode->data = e;
    
    Node<T>* prev = nullptr;
    Node<T>* current = first;
    int count = 0;
    
    while (current != nullptr) {
        if (count == i) {
            prev->link = newNode;
            newNode->link = current;
            return;
        }
        prev = current;
        current = current->link;
        count++;
    }
    
    throw std::out_of_range("Index out of bounds");
}

template <class T>
Iterator<T> List<T>::Begin() 
{
    return Iterator<T>(first);
}

template <class T>
Iterator<T> List<T>::End() 
{
    return Iterator<T>(nullptr);
}

template <class T>
ostream& operator<<(std::ostream& os, const List<T>& list) 
{
    Node<T>* current = list.first;
    
    while (current != nullptr) {
        os << current->data << " ";
        current = current->link;
    }
    
    return os;
}

template <class T>
Iterator<T>::Iterator(Node<T>* node) 
{
    current = node;
}

template <class T>
T& Iterator<T>::operator*() const 
{
    return current->data;
}

template <class T>
T* Iterator<T>::operator->() const
{
    return &current->data;
}

template <class T>
Iterator<T>& Iterator<T>::operator++() 
{
    if (current != nullptr) {
        current = current->link;
    }
    return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator old = *this;
    if (current != nullptr) {
        current = current->link;
    }
    return old;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& r) const 
{
    return current != r.current;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T> &r) const
{
    return current == r.current;
}
