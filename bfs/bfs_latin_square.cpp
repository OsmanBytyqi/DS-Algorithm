#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph
{
    int V;
    vector<list<int>> adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void createGraph(int n, Graph& g);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false);
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
void Graph::createGraph(int n, Graph& g) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            g.addEdge(i, i + 1);
        else
        {
            g.addEdge(i, 0);
        }
    }
}

int main() {

    int n;
    cout << "Inputi n = ";
    cin >> n;
    Graph g(n);
    cout << "Latin Square me Breadth First Search" << endl;
    g.createGraph(n, g);

    for (int i = 0; i < n; i++) {
        g.BFS(i);
        cout << endl;
    }

    return 0;
}
