#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void createGraph(int n, Graph &g);
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
void Graph::createGraph(int n, Graph &g) {
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            g.addEdge(i, i + 1);
        else
            g.addEdge(i, 0);
    }
}
int main() {

    int n;
    cout << "Inputi n = ";
    cin >> n;
    cout << "Latin Square me Depth First Search" << endl;
    for (int i = 0; i < n; i++)
    {
        Graph g;
        g.createGraph(n, g);
        g.DFS(i);
        cout << endl;
    }
    return 0;
}
