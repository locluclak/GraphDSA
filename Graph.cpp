#include "Graph.h"
#include "iostream"
#include <queue>
using namespace std;

Graph::~Graph()
{
    if (this->G == NULL) return;
    for (int i = 0; i < this->numV; i++)
    {
        delete[] this->G[i];
    }
    delete G;
}
istream& operator>>(istream& m, Graph& a)
{
    cout << "Nhap do thi vo huong\n";
    cout << "Nhap so dinh: ";
    m >> a.numV;
    cout << "Nhap so canh: ";
    m >> a.numE;

    a.G = new int* [a.numV];
    for (int i = 0; i < a.numV; i++)
    {
        a.G[i] = new int[a.numV];
    }
    for (int i = 0; i < a.numV; i++)
    {
        for (int j = 0; j < a.numV; j++)
            a.G[i][j] = 0;
    }
    cout << "Nhap 'dinh dinh' voi dinh tu " << 0 << "-" << a.numV - 1 << endl;
    for (int i = 0; i < a.numE; i++)
    {
        int v1, v2;
        m >> v1 >> v2;
        a.G[v1][v2] = 1;
        a.G[v2][v1] = 1;
    }
    return m;
}

ostream& operator<<(ostream& m, const Graph& a)
{
    for (int i = 0; i < a.numV; i++)
    {
        for (int j = 0; j < a.numV; j++)
            m << a.G[i][j] << ' ';
        m << endl;
    }
    return m;
}



void Graph::BFS()
{
    int *checked = new int[this->numV];
    for (int i = 0; i < this->numV; i++)
    {
        checked[i] = 0; 
    }   
    queue<int> q;
    q.push(0);
    checked[0] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        cout << "duyet: " << curr << endl;
        q.pop();
        
        for (int neighbor = 0; neighbor < this->numV; neighbor++)
        {
            if (this->G[curr][neighbor] && checked[neighbor] == false)
            {
                q.push(neighbor);
                checked[neighbor] = 1;
            }
        }
    }
    delete[] checked;
}

void Graph::DFS()
{
    int* checked = new int[this->numV];
    for (int i = 0; i < this->numV; i++)
        checked[i] = 0;
    this->DFS(0, checked);
    delete[] checked;
}
void Graph::DFS(int start, int* checked)
{
    checked[start] = 1;
    cout << "duyetq " << start << endl;
    for (int neighbor = 0; neighbor < this->numV; neighbor++)
    {
        if (this->G[start][neighbor] && checked[neighbor] == false)
            this->DFS(neighbor, checked);
    }
}