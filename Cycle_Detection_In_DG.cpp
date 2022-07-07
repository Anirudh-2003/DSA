#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int i, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[i] = true;
    if (!visited[i])
    {
        visited[i] = true;
        for (auto i : adj[i])
        {
            if (!visited[i] && isCycle(i, adj, visited, stack))
            {
                return true;
            }
            if (stack[i])
            {
                return true;
            }
        }
    }
    stack[i] = false;
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
    }
    bool cycle = false;
    vector<int> stack(n, 0);
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycle(i, adj, visited, stack))
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