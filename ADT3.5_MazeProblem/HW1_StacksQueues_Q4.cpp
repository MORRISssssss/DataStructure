#include <iostream>
#include "Maze.h"
#include <fstream>
#include "Maze.cpp"

int main()
{
    int r, c;
    ifstream inputFile("maze.txt");
    inputFile >> r >> c;
    Maze m(r, c);
    m.Initial(inputFile);
    inputFile.close();
    cout << m << endl;
    m.Path(r, c);

    

    return 0;
}