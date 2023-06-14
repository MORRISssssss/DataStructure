#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <iostream>
#include "Heap.h"
#include <stack>
using namespace std;

class Pair{
    public: 
        Pair(const int w, const int v);
        Pair();
        inline bool operator>(const Pair p) const;
        inline bool operator<(const Pair p) const;
        inline bool operator>=(const Pair p) const;
        inline bool operator<=(const Pair p) const;
        inline bool operator==(const Pair p) const;
        Pair& operator=(const Pair p);
        int weight;
        int vertex; 
    friend ostream &operator<<(ostream &os, const Pair &rhs);
};

class WeightedGraph{
    public:
        WeightedGraph(const int vertices = 0);
        ~WeightedGraph();
        void Dijkstra(const int v);
        void BellmanFord(const int v);
        void Floyd();
        void Setup1_1();
        void Setup1_2();
        void Setup1_3();
        void Setup2_1();
        void Setup2_2();
        void Setup3_1();

    private:
        int **adjMatrix;
        int n;

};

struct LinkNode{
    int data;
    LinkNode *link;
};

#endif