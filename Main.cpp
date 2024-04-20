#include "Graph.h"
#include "iostream"
using namespace std;

int main()
{
    Graph a;
    cin >> a;
    cout << "Graph:\n" << a;
    a.BFS();
    a.DFS();

    return 0;
}
