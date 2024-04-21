#include "Graph.h"
#include "iostream"
using namespace std;

int main()
{
	Graph A;
	cin >> A;
	cout << A;
	A.BFS();
	A.DFS();
}