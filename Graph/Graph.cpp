#include "Graph.h"
#include "LinkedList.cpp"

Graph::Graph(const int vertices)
{
    n = vertices;
    e = 0;
    adjLists = new List<int>[n];
}

Graph::~Graph()
{
    delete[] adjLists;
}

void Graph::BFS(const int v)
{
    visited = new bool [n];
    fill (visited, visited + n, false);
    cout << v << " ";
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (Iterator<int> w = adjLists[vertex].Begin(); w != adjLists[vertex].End(); w++){
            if (!visited[*w]) {
                q.push(*w);
                cout << *w << " ";
                visited[*w] = true;
            }
        }
    } // end of while loop
    delete [] visited;
    cout << endl;
}

void Graph::DFS(const int v)
{
    visited = new bool[n];
    fill (visited, visited + n, false);
    RecDFS(v); // start search at vertex 0
    delete [] visited;
    cout << endl;
}

void Graph::Components()
{
    visited = new bool [n];
    fill (visited, visited + n, false);
    for (int i = 0 ; i < n ; i++){
        if (!visited[i]) {
            cout << "{";
            RecDFS(i); // find the component containing i
            cout << "} ";
        }
    }
    delete [] visited;
    cout << endl;
}

void Graph::DfnLow(const int x)
{
    num = 1; // num 是Graph的一個int資料成員
    dfn = new int[n]; // dfn 在Graph中宣告為int*
    low = new int[n]; // low 在Graph中宣告為int*
    fill(dfn, dfn + n, 0);
    fill(low, low + n, 0);
    DfnLow(x, -1); // 從頂點x開始
    for (int i = 0; i < n; i++){
    }
    cout << "vertex\tdfn\tlow" << endl;
    for (int i = 0; i < n; i++)
        cout << i << '\t' << dfn[i] << '\t' << low[i] << endl;
    delete [] dfn;
    delete [] low;
}

void Graph::Setup1()
{
    if (n < 8)
        throw "Not enough vertices.";

    adjLists[0].InsertBack(1);
    adjLists[0].InsertBack(2);

    adjLists[1].InsertBack(0);
    adjLists[1].InsertBack(3);

    adjLists[2].InsertBack(0);
    adjLists[2].InsertBack(3);

    adjLists[3].InsertBack(1);
    adjLists[3].InsertBack(2);

    adjLists[4].InsertBack(5);

    adjLists[5].InsertBack(4);
    adjLists[5].InsertBack(6);

    adjLists[6].InsertBack(5);
    adjLists[6].InsertBack(7);

    adjLists[7].InsertBack(6);

    e = 7;
}

void Graph::Setup2()
{
    if (n < 8)
        throw "Not enough vertices.";
    
    adjLists[0].InsertBack(1);
    adjLists[0].InsertBack(2);

    adjLists[1].InsertBack(0);
    adjLists[1].InsertBack(3);
    adjLists[1].InsertBack(4);

    adjLists[2].InsertBack(0);
    adjLists[2].InsertBack(5);
    adjLists[2].InsertBack(6);

    adjLists[3].InsertBack(1);
    adjLists[3].InsertBack(7);
    
    adjLists[4].InsertBack(1);
    adjLists[4].InsertBack(7);
    
    adjLists[5].InsertBack(2);
    adjLists[5].InsertBack(7);

    adjLists[6].InsertBack(2);
    adjLists[6].InsertBack(7);
    
    adjLists[7].InsertBack(3);
    adjLists[7].InsertBack(4);
    adjLists[7].InsertBack(5);
    adjLists[7].InsertBack(6);

    e = 10;

}

void Graph::Setup3()
{
    if (n < 10)
        throw "Not enough vertices.";
    
    adjLists[0].InsertBack(1);

    adjLists[1].InsertBack(0);
    adjLists[1].InsertBack(2);
    adjLists[1].InsertBack(3);
    
    adjLists[2].InsertBack(1);
    adjLists[2].InsertBack(4);
    
    adjLists[3].InsertBack(4);
    adjLists[3].InsertBack(1);
    adjLists[3].InsertBack(5);

    adjLists[4].InsertBack(2);
    adjLists[4].InsertBack(3);

    adjLists[5].InsertBack(3);
    adjLists[5].InsertBack(6);
    adjLists[5].InsertBack(7);
    
    adjLists[6].InsertBack(5);
    adjLists[6].InsertBack(7);
    
    adjLists[7].InsertBack(5);
    adjLists[7].InsertBack(6);
    adjLists[7].InsertBack(9);
    adjLists[7].InsertBack(8);
    
    adjLists[8].InsertBack(7);
    
    adjLists[9].InsertBack(7);

    e = 11;
}

void Graph::RecDFS(const int v)
{
    cout << v << " ";
    visited[v] = true;
    for (Iterator<int> w = adjLists[v].Begin(); w != adjLists[v].End(); w++)
    if (!visited[*w]) 
        RecDFS(*w);
}

void Graph::DfnLow(const int u, const int v)
{
    // 由頂點u開始，一邊做深度優先搜尋一邊計算dfn及low。
    // 在製造出的生成樹中v是u的父節點（如果v存在的話）
    dfn [u] = low [u] = num++;
    for (Iterator<int> w = adjLists[u].Begin(); w != adjLists[u].End(); w++) // 實際的程式碼使用疊代器
        if (dfn[*w] == 0){ // w是未拜訪過的頂點
            DfnLow (*w, u);
            low[u] = min(low[u], low[*w]);
        }
        else if (*w != v) 
            low[u] = min(low[u], dfn[*w]); // back edge

}
