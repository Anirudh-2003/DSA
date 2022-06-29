#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<int, vector<int>> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
    }
    int sum = 0, count = 0;
    while (!maxHeap.empty())
    {
        sum += maxHeap.top();
        maxHeap.pop();
        count++;
        if (sum >= k)
        {
            break;
        }
    }
    if (sum < k)
    {
        cout << "No SubSequence Present To Form Sum Equal Or Greater Than K. " << endl;
    }
    else
    {
        cout << "Minimum SubSequence is: " << count << endl;
    }
    return 0;
}