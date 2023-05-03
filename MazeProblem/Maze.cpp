#include <iostream>
#include "Maze.h"
#include <fstream>
using namespace std;

Items::Items(int x_in, int y_in, int dir_in)
{
    x = x_in;
    y = y_in;
    dir = dir_in;
}

template <class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity)
{
    if (capacity < 1) throw "Capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete [] stack;
}

template <class T>
inline int Stack<T>::Size() const
{ 
    return top + 1; 
}

template<class T>
inline bool Stack<T>::IsEmpty() const
{
    return (Size() == 0);
}

template <class T>
void Stack<T>::ChangeCapacity(int newCapacity)
{
    if (newCapacity < capacity) 
        throw "The new capacity cannot be less than the origin one.";
    T* newStack = new T[newCapacity];
    copy(stack, stack + Size(), newStack);
    delete [] stack;
    stack = newStack; 
    capacity = newCapacity;
}

template <class T>
void Stack<T>::Push(const T& item) 
{
    if (capacity == top + 1)
        ChangeCapacity(2 * capacity);
    stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty()) 
        throw "Stack is empty. Cannot delete.";
    stack[top--].~T();
}

template <class T>
T& Stack<T>::Top() const
{
    if (IsEmpty()) 
        throw "Stack is empty.";
    return stack[top];
}

template<class U>
ostream& operator<<(ostream& os, const Stack<U>& s)
{
    os << "s.top" << endl;
    for (int i = 0 ; i <= s.top; i++)
    os << i << ": " << s.stack[i] << endl;
    return os;
}

ostream& operator<<(ostream& os, const Items& item)
{
    return os << item.x << ", " << item.y << ", " << item.dir;
}

Maze::Maze(const int r, const int c)
{
    rows = r;
    cols = c;
    move[0] = {-1, 0};
    move[1] = {-1, 1};
    move[2] = {0, 1};
    move[3] = {1, 1};
    move[4] = {1, 0};
    move[5] = {1, -1};
    move[6] = {0, -1};
    move[7] = {-1, -1};
    maze = new int* [rows + 2];
    mark = new int* [rows + 2];
    for (int i = 0; i < rows + 2; i++){
        maze[i] = new int [cols + 2];
        mark[i] = new int [cols + 2];
    }
    for (int i = 0; i < rows + 2; i++){
        for (int j = 0; j < cols + 2; j++){
            mark[i][j] = 0;
        }
    }
}

Maze::~Maze()
{
    for (int i = 0; i < rows + 2; i++){
        delete [] maze[i];
        delete [] mark[i];
    }
    delete [] maze;
    delete [] mark;
}

void Maze::Initial(ifstream &inputFile)
{
    for (int i = 0; i < rows + 2; i++){
        for (int j = 0; j < cols + 2; j++){
            if (i == 0 || i == rows + 1 || j == 0 || j == cols + 1)
                maze[i][j] = 1;
            else
                inputFile >> maze[i][j];
        }
    }
}

void Maze::Path(const int m, const int p)
{
    mark[1][1] = 1;
    Stack<Items> stack(m * p);
    Items temp(1, 1, E);

    stack.Push(temp);

    while (!stack.IsEmpty()) {
        temp = stack.Top();
        stack.Pop();
        int i = temp.x;
        int j = temp.y;
        int d = temp.dir;
        while (d < 8) {
            int g = i + move[d].di;
            int h = j + move[d].dj;
            if ((g == m) && (h == p)) {
                temp.x = i;
                temp.y = j;
                temp.dir = d;
                stack.Push(temp);
                temp.x = g;
                temp.y = h;
                temp.dir = -1;
                stack.Push(temp);
                cout << stack;
                return;
            }
            if ((!maze[g][h]) && (!mark[g][h])) {
                mark[g][h] = 1;
                temp.x = i;
                temp.y = j;
                temp.dir = d;
                stack.Push(temp);
                i = g; j = h; d = N;
            } else d++;
        }
    }
    cout << "No path in maze" << endl;
}

ostream &operator<<(ostream &os, const Maze &rhs)
{
    for (int i = 0; i < rhs.rows + 2; i++) {
        for (int j = 0; j < rhs.cols + 2; j++)
            os << rhs.maze[i][j] << " ";
        os << endl;
    }
    return os;
}
