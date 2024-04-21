#include "iostream"
#include "list"
using namespace std;
#pragma once
class Graph
{
private:
	int numV;
	list<int> *neighbor;
public:
	~Graph();
	friend istream& operator>>(istream&, Graph&);
	friend ostream& operator<<(ostream&, const Graph&);
	void DFS(int, bool*);
	void DFS();
	void BFS();
};

