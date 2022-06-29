## Latin Square Problem

### DFS Approach


```cpp
void Graph::createGraph(int n, Graph &g) {
 for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            g.addEdge(i, i + 1);
        else
            g.addEdge(i, 0);
    }
}
```
`Time Complexity: O(n)`

---
```cpp
void Graph::DFS(int v)
{
 visited[v] = true;
 cout << v << " ";
 list<int>::iterator i;
 for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
        DFS(*i);
}
```

```cpp
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
```


```cpp
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
```
`Time Complexity: 
 Per nje i te cfaredoshme time complexity per: 
 g.createGraph(n, g) do te jete O(n).
 g.DFS(i) do te jete O(2*n - 1). 
 Totali: O(n + 2*n - 1) = O(3*n - 1)
`


### BFS Approach

---
```cpp
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
```


```cpp
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
```

```cpp
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
```

```cpp
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
```

```cpp
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
```



 ```cpp
 for (int i = 0; i < n; i++) {
        g.BFS(i);
        cout << endl;
    }
 ```


