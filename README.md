## Latin Square Problem

#

### DFS Approach

```cpp
for (int i = 0; i < n; i++)
    {
        Graph g;
        g.createGraph(n, g);
        g.DFS(i);
        cout << endl;
    }
    return 0;
```
`Time Complexity:O(n)`

---
```cpp
 for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            g.addEdge(i, i + 1);
        else
            g.addEdge(i, 0);
    }

```
`Time Complexity:O(n)`

---
```cpp

 for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

```

`Time Complexity:O(n^2)`


