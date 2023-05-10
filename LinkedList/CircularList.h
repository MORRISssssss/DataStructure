#include <iostream>
using namespace std;
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

template <class T> class CircularList;
template <class T> class CircularHeaderList;
template <class T>
class Node{
    public:
        friend class CircularList<T>;
        friend class CircularHeaderList<T>;
        template <class U>
        friend ostream& operator<<(ostream& os, const CircularList<U>& list);
        template <class U>
        friend ostream& operator<<(ostream& os, const CircularHeaderList<U>& list);
    private:  
        T data;
        Node* link;
};

template <class T>
class CircularList{
    public: 
        CircularList();
        ~CircularList();
        bool IsEmpty() const;
        // Count the number of nodes in the circular list.
        int Size() const;
        // Empty this list.
        void Empty();
        // Return the pointer to the node with index i.
        Node<T> *IndexPointer(const int i) const;
        // Insert a new node at the front of this list.
        void InsertFront(const T& e);
        // Insert a new node at the back of this list.
        void InsertBack(const T& e);
        // Delete the first node in this list.
        void DeleteFirst();
        // Delete the last node in this list.
        void DeleteBack();
        // Delete all odd nodes.
        void DeleteOddNode();
        // Deconcatenate this list into two lists. The node pointed by split is the first node in the second list.
        void Deconcatenate(const Node<T>* split, CircularList<T>& list1, CircularList<T>& list2);
        // Return a list that merge *this and list2
        CircularList<T> Merge(CircularList<T>& list2);
        CircularList<T>& operator=(const CircularList list2);
        template <class U>
        friend ostream& operator<<(ostream& os, const CircularList<U>& list);
    private:
        Node<T> *first;
};

template <class T>
class CircularHeaderList{
    public:
        CircularHeaderList();
        ~CircularHeaderList();
        bool IsEmpty() const;
        // Count the number of nodes in the circular list.
        int Size() const;
        // Empty this list.
        void Empty();
        // Return the pointer to the node with index i.
        Node<T> *IndexPointer(const int i) const;
        // Insert a new node at the front of this list.
        void InsertFront(const T& e);
        // Insert a new node at the back of this list.
        void InsertBack(const T& e);
        // Delete the first node in this list.
        void DeleteFirst();
        // Delete the last node in this list.
        void DeleteBack();
        // Delete all odd nodes.
        void DeleteOddNode();
        // Deconcatenate this list into two lists. The node pointed by split is the first node in the second list.
        void Deconcatenate(const Node<T>* split, CircularHeaderList<T>& list1, CircularHeaderList<T>& list2);
        // Return a list that merge *this and list2
        CircularHeaderList<T> Merge(CircularHeaderList<T>& list2);
        CircularHeaderList<T>& operator=(const CircularHeaderList list2);
        template <class U>
        friend ostream& operator<<(ostream& os, const CircularHeaderList<U>& list);
    private:
        Node<T> *head;
};

#endif