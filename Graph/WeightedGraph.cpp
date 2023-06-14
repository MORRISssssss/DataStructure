#include "WeightedGraph.h"
#include "Heap.cpp"

#define MAX 0x3f3f3f3f

WeightedGraph::WeightedGraph(const int vertices)
{
    n = vertices;
    adjMatrix = new int* [n];
    for (int i = 0; i < n; i++)
        adjMatrix[i] = new int [n];
}

WeightedGraph::~WeightedGraph()
{
    for (int i = 0; i < n; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;

}

void WeightedGraph::Dijkstra(const int v)
{
    MinHeap<Pair> mh(n);
    int dist[n];
    LinkNode *path[n];
    for (int i = 0; i < n; i++){
        path[i] = new LinkNode;
        path[i]->data = i;
        path[i]->link = nullptr;
    }
    mh.Push(Pair(0, v));
    fill(dist, dist + n, MAX);
    dist[v] = 0;

    cout << "\t\t|Vertex\t\t|Distance" << endl;
    cout << "Iteration\t|selected\t|";
    for (int i = 0; i < n; i++) 
        cout << i << '\t';
    cout << endl;
    for (int i = 0; i < 8 * (4 + n); i++) cout << "-";
    cout << endl;

    int cnt = 0;
    while (!mh.IsEmpty()){
        Pair p = mh.Top();
        mh.Pop();
        if (dist[p.vertex] >= p.weight){
            for (int i = 0; i < n; i++){
                if (dist[p.vertex] + adjMatrix[p.vertex][i] < dist[i]){
                    dist[i] = dist[p.vertex] + adjMatrix[p.vertex][i];
                    mh.Push(Pair(dist[i], i));
                    path[i]->link = path[p.vertex];
                }
            }
            cout << cnt++ << "\t\t|" << p.vertex << "\t\t|";
            for (int i = 0; i < n; i++){
                if (dist[i] == MAX)
                    cout << "inf\t";
                else
                    cout << dist[i] << '\t';
            }
            cout << endl;
        }
    }

    stack<int> s;
    cout << "Path (length)" << endl;
    for (int i = 0; i < n; i++){
        LinkNode *current = path[i];
        while (current != nullptr){
            s.push(current->data);
            current = current->link;
        }
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        if (dist[i] == MAX)
            cout << "(inf)" << endl;
        else
            cout << "(" << dist[i] << ")" << endl;
    }
    
    for (int i = 0; i < n; i++)
        delete path[i];
}

void WeightedGraph::BellmanFord(const int v)
{
    cout << "\t|dist^k[]" << endl;
    cout << "k\t|";
    for (int i = 0; i < n; i++) 
        cout << i << '\t';
    cout << endl;
    for (int i = 0; i < 8 * (1 + n); i++) 
        cout << "-";
    cout << endl;

    // n is the number of vertices
    // in-place update for dist[] is used 
    int dist[n];
    int pre_dist[n];
    int cnt = 1;
    cout << cnt++ << "\t|";
    for (int i = 0; i < n ; i++){
        dist[i] = adjMatrix[v][i]; // dist1[] initialization
        if (dist[i] == MAX)
            cout << "inf\t";
        else
            cout << dist[i] << '\t';
    } 
    cout << endl;

    for (int k = 2; k < n ; k++){ // dist2 ~ dist(n-1)
        copy(dist, dist + n, pre_dist);
        for (int u = 0; u < n; u++){
            if (u != v){
                for (int i = 0; i < n; i++){
                    if (dist[u] > pre_dist[i] + adjMatrix[i][u]) 
                        dist[u] = pre_dist[i] + adjMatrix[i][u];
                }
            }
        }
        cout << cnt++ << "\t|";
        for (int i = 0; i < n ; i++)
            if (dist[i] == MAX)
                cout << "inf\t";
            else
                cout << dist[i] << '\t';
        cout << endl;
    } 
}

void WeightedGraph::Floyd()
{
    int a[n][n];
    cout << "A^-1\t|";
    for (int i = 0; i < n; i++)
        cout << i << "\t";
    cout << endl;
    for (int i = 0; i < 8 * (1 + n); i++) 
        cout << "-";
    cout << endl;

    for (int i = 0; i<n; i++){
        cout << i << "\t|";
        for (int j = 0; j<n; j++){
            a[i][j]= adjMatrix[i][j]; 
            if (a[i][j] > MAX / 2)
                cout << "inf\t";
            else
                cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
        
    for (int k= 0; k<n; k++){
        for (int i= 0; i<n; i++) 
            for (int j= 0; j<n; j++)
                if(a[i][j] > (a[i][k] + a[k][j]))
                    a[i][j] = a[i][k] + a[k][j];
        
        cout << "A^" << k << "\t|";
        for (int i = 0; i < n; i++)
            cout << i << "\t";
        cout << endl;
        for (int i = 0; i < 8 * (1 + n); i++) 
            cout << "-";
        cout << endl;

        for (int i = 0; i<n; i++){
            cout << i << "\t|";
            for (int j = 0; j<n; j++){
                if (a[i][j] > MAX / 2)
                    cout << "inf\t";
                else
                    cout << a[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
        

}

void WeightedGraph::Setup1_1()
{
    if (n != 8)
        throw "Wrong size.";
    int mat[n][n] = 
    {{0   , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
     {300 , 0   , MAX , MAX , MAX , MAX , MAX , MAX },
     {1000, 800 , 0   , MAX , MAX , MAX , MAX , MAX },
     {MAX , MAX , 1200, 0   , MAX , MAX , MAX , MAX },
     {MAX , MAX , MAX , 1500, 0   , 250 , MAX , MAX },
     {MAX , MAX , MAX , 1000, MAX , 0   , 900 , 1400},
     {MAX , MAX , MAX , MAX , MAX , MAX , 0   , 1000},
     {1700, MAX , MAX , MAX , MAX , MAX , MAX , 0   }};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = mat[i][j];
}

void WeightedGraph::Setup1_2()
{
    if (n != 6)
        throw "Wrong size.";
    int mat[n][n] = 
    {{0  , 50 , 45 , 10 , MAX, MAX},
     {MAX, 0  , 10 , 15 , MAX, MAX},
     {MAX, MAX, 0  , MAX, 30 , MAX},
     {20 , MAX, MAX, 0  , 15 , MAX},
     {MAX, 20 , 35 , MAX, 0  , MAX},
     {MAX, MAX, MAX, MAX, 3  , 0  }};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = mat[i][j];
}

void WeightedGraph::Setup1_3()
{
    if (n != 6)
        throw "Wrong size.";
    int mat[n][n] = 
    {{0  , 20 , 15 , MAX, MAX, MAX},
     {2  , 0  , MAX, MAX, 10 , 30 },
     {MAX, MAX, 0  , 4  , MAX, 10 },
     {MAX, MAX, MAX, 0  , MAX, MAX},
     {MAX, MAX, MAX, 15 , 0  , MAX},
     {MAX, MAX, MAX, 4  , 10 , 0  }};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = mat[i][j];
}

void WeightedGraph::Setup2_1()
{
    if (n != 7)
        throw "Wrong size.";
    int mat[n][n] = 
    {{0  , 6  , 5  , 5  , MAX, MAX, MAX},
     {MAX, 0  , MAX, MAX, -1 , MAX, MAX},
     {MAX, -2 , 0  , MAX, 1  , MAX, MAX},
     {MAX, MAX, -2 , 0  , MAX, -1 , MAX},
     {MAX, MAX, MAX, MAX, 0  , MAX, 3  },
     {MAX, MAX, MAX, MAX, MAX, 0  , 3  },
     {MAX, MAX, MAX, MAX, MAX, MAX, 0  }};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = mat[i][j];
}

void WeightedGraph::Setup2_2()
{
    if (n != 3)
        throw "Wrong size.";
    int mat[n][n] = 
    {{0  , 7  , 5  },
     {MAX, 0  , -5 },
     {MAX, MAX, 0  }};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = mat[i][j];
}

void WeightedGraph::Setup3_1()
{
    if (n != 3)
        throw "Wrong size.";
    int mat[n][n] = 
    {{0  , 4  , 11 },
     {6  , 0  , 2  },
     {3  , MAX, 0  }};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = mat[i][j];
}

Pair::Pair(const int w, const int v)
{
    weight = w;
    vertex = v;
}

Pair::Pair()
{
}

inline bool Pair::operator>(const Pair p) const
{
    return weight > p.weight;
}

inline bool Pair::operator<(const Pair p) const
{
    return weight < p.weight;
}

inline bool Pair::operator>=(const Pair p) const
{
    return weight >= p.weight;
}

inline bool Pair::operator<=(const Pair p) const
{
    return weight <= p.weight;
}

inline bool Pair::operator==(const Pair p) const
{
    return weight == p.weight;
}

Pair &Pair::operator=(const Pair p)
{
    weight = p.weight;
    vertex = p.vertex;
    return *this;
}

ostream &operator<<(ostream &os, const Pair &rhs)
{
        os << "(" << rhs.vertex << ", " << rhs.weight << ")";
        return os;
}