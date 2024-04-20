#include <iostream>
using namespace std;

#pragma once
class Graph
{
private:
    int numV;
    int numE;
    int** G;
public:
    ~Graph();
    friend istream& operator>>(istream&, Graph&);
    friend ostream& operator<<(ostream&, const Graph&);
    void BFS();
    void DFS(int,int*);
    void DFS();
};

