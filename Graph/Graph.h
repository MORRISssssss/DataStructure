#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include "LinkedList.h"
using namespace std;

class Graph{
    public: 
        Graph(const int vertices = 0);
        ~Graph();
        void BFS(const int v);
        void DFS(const int v);
        void Components();
        void DfnLow(const int x);

        void Setup1();
        void Setup2();
        void Setup3();

    private:
        List<int> *adjLists;
        int n, e;
        bool *visited;
        void RecDFS(const int v);
        int num;
        int *dfn, *low;
        void DfnLow(const int u, const int v);

};

#endif