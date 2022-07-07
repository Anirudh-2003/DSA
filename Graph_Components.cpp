#include <iostream>
#include <vector>
using namespace std;

int getComp(int index, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (visited[index])
    {
        return 0;
    }
    visited[index] = true;
    int ans = 1;
    for (auto i : adj[index])
    {
        if (!visited[i])
        {
            ans += getComp(i, adj, visited);
            visited[i] = true;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, 0);
    vector<int> components;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components.push_back(getComp(i, adj, visited));
        }
    }
    for (auto i : components)
    {
        cout << i << " ";
    }
    cout << endl;
    // Que.....
    long long ans = 0;
    for (auto i : components)
    {
        ans += i * (n - i);
    }
    cout << (ans / 2) << endl;
    return 0;
}