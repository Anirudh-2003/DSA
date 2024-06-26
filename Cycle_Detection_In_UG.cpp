#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int source, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[source] = true;
    for (auto i : adj[source])
    {
        if (i != parent)
        {
            if (visited[i])
            {
                return true;
            }
            if (!visited[i] && isCycle(i, adj, visited, source))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycle(i, adj, visited, -1))
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Cycle Is Present." << endl;
    }
    else
    {
        cout << "Cycle Is Not Present." << endl;
    }
    return 0;
}