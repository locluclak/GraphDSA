#include "Graph.h"
#include "list"
#include "iostream"
#include "queue"
using namespace std;

Graph::~Graph()
{
	if (this->neighbor == NULL) return;
	for (int i = 0; i < this->numV; i++)
	{
		this->neighbor[i].clear();
	}
	delete[] this->neighbor;
}
istream& operator>>(istream& m, Graph& a)
{
	cout << "Nhap so dinh: ";
	m >> a.numV;
	int numE;
	cout << "Nhap so canh: ";
	m >> numE;
	cout << "Nhap cac canh 0-" << a.numV - 1 << ".\n";

	a.neighbor = new list<int>[a.numV];
	for (int i = 0; i < numE; i++)
	{
		int v1, v2;
		m >> v1 >> v2;
		a.neighbor[v1].push_back(v2);
		a.neighbor[v2].push_back(v1);
	}
	return m;
}

ostream& operator<<(ostream& m, const Graph& a)
{
	for (int v = 0; v < a.numV; v++)
	{
		m << "Dinh " << v << " di den: ";
		for (auto nb = a.neighbor[v].begin(); nb != a.neighbor[v].end(); nb++)
		{
			m << *nb << ' ';
		}
		m << '\n';
	}
	return m;
}

void Graph::BFS()
{
	bool* checked = new bool[this->numV];
	for (int i = 0; i < this->numV; i++)
	{
		checked[i] = false;
	}
	queue<int> q;
	q.push(0);
	checked[0] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		cout << "BFS_duyet: " << curr << endl;
		q.pop();

		for (auto nb = neighbor[curr].begin(); nb != neighbor[curr].end(); nb++)
		{
			if (checked[*nb] == false)
			{
				q.push(*nb);
				checked[*nb] = true;	
			}	
		}
	}
	delete[] checked;
}


void Graph::DFS(int start, bool* checked)
{
	checked[start] = 1;
	cout << "DFS_duyet " << start << endl;
	for (auto nb = neighbor[start].begin(); nb != neighbor[start].end(); nb++)
	{
		if (checked[*nb] == false)
		{
			DFS(*nb, checked);
			checked[*nb] = true;
		}
	}
}

void Graph::DFS()
{
	bool* checked = new bool[this->numV];
	for (int i = 0; i < this->numV; i++)
		checked[i] = false;
	this->DFS(0, checked);
	delete[] checked;
}