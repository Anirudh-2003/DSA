#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        arr[i] = vector<int>(size);
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> index(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (int i = 0; i < n; i++)
    {
        pair<int,int> p;
        p.first = arr[i][0];
        p.second = i;
        minHeap.push(p);
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        pair<int, int> k = minHeap.top();
        minHeap.pop();
        ans.push_back(k.first);
        if (index[k.second] + 1 < arr[k.second].size())
        {
            pair<int,int> p;
            p.first = arr[k.second][index[k.second] + 1];
            p.second = k.second;
            minHeap.push(p);
        }
        index[k.second] += 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}