## Latin Square Problem

#

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
`Time Complexity:O(n)`

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

`Time Complexity:O(2*n - 1)`

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
`Nuk ka time complexity per addEdge dhe klasen Graph`

---

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

---
`Per i prej 0 deri ne n kemi n vlera te ndryshme per te cilat time complexity i llogaritur me siper nuk ndryshon(mbetet e njejta).`

---
`Konkludojme qe Time Complexity total per DFS eshte: 
 n*(3*n - 1) = 3n^2 - n => O(3n^2 - n)`