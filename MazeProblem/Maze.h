#include <iostream>
using namespace std;
#ifndef MAZE_H
#define MAZE_H

struct Offsets
{ 
    int di, dj;
};

enum directions {N, NE, E, SE, S, SW, W, NW};

struct Items
{
    Items(int x_in = 0, int y_in = 0, int dir_in = 0);
    int x, y, dir;
};

template <class T>
class Stack
{
    public:
        template <class U>
        friend ostream& operator<<(ostream& os, const Stack<U>& s);
        Stack (int stackCapacity = 10);
        ~Stack();
        bool IsEmpty() const;
        int Size() const;
        T& Top() const;
        void Pop();
        void Push(const T& item);
    private:
        T* stack;
        int top, capacity;
        void ChangeCapacity(int newCapacity);
};

class Maze
{
    public:
        Maze(const int r = 0, const int c = 0);
        ~Maze();
        void Initial(ifstream& inputFile);
        void Path(const int m, const int p);
        friend ostream& operator<<(ostream& os, const Maze& rhs);
    private:
        Offsets move[8];
        int** maze;
        int** mark;
        int rows, cols;
};

#endif