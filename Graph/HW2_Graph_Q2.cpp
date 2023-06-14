#include "WeightedGraph.cpp"

int main()
{
    cout << "Dijkstra: " << endl;
    
    WeightedGraph g1_1(8);
    cout << "G1: " << endl;
    g1_1.Setup1_1();
    g1_1.Dijkstra(4);
    cout << endl;

    WeightedGraph g1_2(6);
    cout << "G1': " << endl;
    g1_2.Setup1_2();
    g1_2.Dijkstra(0);
    cout << endl;

    WeightedGraph g1_3(6);
    cout << "G1'': " << endl;
    g1_3.Setup1_3();
    g1_3.Dijkstra(0);
    cout << endl;

    cout << "Bellman-Ford: " << endl;

    WeightedGraph g2_1(7);
    cout << "G2: " << endl;
    g2_1.Setup2_1();
    g2_1.BellmanFord(0);
    cout << endl;

    WeightedGraph g2_2(3);
    cout << "G2': " << endl;
    g2_2.Setup2_2();
    g2_2.BellmanFord(0);
    cout << endl;

    cout << "Floyd: " << endl;

    WeightedGraph g3_1(3);
    cout << "G3: " << endl;
    g3_1.Setup3_1();
    g3_1.Floyd();
    cout << endl;

    cout << "G2: " << endl;
    g2_1.Floyd();
    cout << endl;

    return 0;
}