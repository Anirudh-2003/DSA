#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }
    int ans = 0;
    while (minHeap.size() > 1)
    {
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();
        ans += e1 + e2;
        minHeap.push(e1 + e2);
    }
    cout << ans << endl;
    return 0;
}