#include "Graph.cpp"

int main()
{
    Graph g1(8), g2(8), g3(10);

    // Graph 1
    g1.Setup1();
    cout << "Graph 1" << endl;
    // BFS
    cout << "BFS: " <<endl;
    g1.BFS(0);
    g1.BFS(3);
    g1.BFS(7);
    // DFS
    cout << "DFS: " <<endl;
    g1.DFS(0);
    g1.DFS(3);
    g1.DFS(7);
    //Components & DfnLow
    cout << "Connected components: ";
    g1.Components();
    g1.DfnLow(3);

    cout << endl;

    // Graph 2
    g2.Setup2();
    cout << "Graph 2" << endl;
    // BFS
    cout << "BFS: " <<endl;
    g2.BFS(0);
    g2.BFS(3);
    g2.BFS(7);
    // DFS
    cout << "DFS: " <<endl;
    g2.DFS(0);
    g2.DFS(3);
    g2.DFS(7);
    //Components & DfnLow
    cout << "Connected components: ";
    g2.Components();
    g2.DfnLow(3);

    cout << endl;

    // Graph 3
    g3.Setup3();
    cout << "Graph 3" << endl;
    // BFS
    cout << "BFS: " <<endl;
    g3.BFS(0);
    g3.BFS(3);
    g3.BFS(7);
    // DFS
    cout << "DFS: " <<endl;
    g3.DFS(0);
    g3.DFS(3);
    g3.DFS(7);
    //Components & DfnLow
    cout << "Connected components: ";
    g3.Components();
    g3.DfnLow(3);

    cout << endl;

    return 0;
}