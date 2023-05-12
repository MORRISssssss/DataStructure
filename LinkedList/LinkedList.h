#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T> class List;
template <class T> class Iterator;

template <class T>
class Node{
    public:
        friend class List<T>;
        friend class Iterator<T>;
        template <class U>
        friend ostream& operator<<(ostream& os, const List<U>& list);
    private:  
        T data;
        Node *link;
};

template <class T>
class List{
    public: 
        friend class Iterator<T>;
        List();
        ~List();
        bool IsEmpty() const;
        // Count the number of nodes in the circular list.
        int Size() const;
        // Insert a new node at the front of this list.
        void InsertFront(const T& e);
        // Insert a new node at the back of this list.
        void InsertBack(const T& e);
        // Delete the first node in this list.
        void DeleteFront();
        // Delete the last node in this list.
        void DeleteBack();
        T& Front() const;
        T& Back() const;
        T& Get(const int i) const;
        void Delete(const int i);
        void Insert(const int i, const T& e);
        void Concatenate(List<T>& b);
        void Reverse();
        Iterator<T> Begin();
        Iterator<T> End();
        template <class U>
        friend ostream& operator<<(ostream& os, const List<U>& list);
    protected:
        Node<T> *first;
};

template <class T>
class Iterator{
    public:
        friend class List<T>;
        Iterator(Node<T>* node = nullptr);
        T& operator*() const;
        T* operator->() const;
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator& r) const;
        bool operator==(const Iterator& r) const;
    private:
        Node<T> *current;
};

#endif