#include <iostream>
#include <vector>
using namespace std;

void color(int u, vector<vector<int>> &adj, vector<int> &colour, vector<bool> &visited, int curr, bool bipart)
{
    if (colour[u] != -1 && colour[u] != curr)
    {
        bipart = false;
        return;
    }
    colour[u] = curr;
    if (visited[u])
    {
        return;
    }
    visited[u] = true;
    for (auto i : adj[u])
    {
        color(i, adj, colour, visited, curr xor 1, bipart);
    }
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
    vector<bool> visited(n, 0);
    vector<int> colour(n, -1);
    bool bipart = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            color(i, adj, colour, visited, 0, bipart);
        }
    }
    if (bipart)
    {
        cout << "Graph Is Bipartite." << endl;
    }
    else
    {
        cout << "Graph Is Not Bipartite." << endl;
    }
    return 0;
}