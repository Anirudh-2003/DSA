#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        int l, p;
        cin >> l >> p;
        for (int i = 0; i < n; i++)
        {
            arr[i].first = l - arr[i].first;
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        int currFuel = p;
        priority_queue<int, vector<int>> maxHeap;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (currFuel >= l)
            {
                break;
            }
            while (currFuel < arr[i].first)
            {
                if (maxHeap.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                currFuel += maxHeap.top();
                maxHeap.pop();
            }
            if (flag)
            {
                break;
            }
            maxHeap.push(arr[i].second);
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        while (!maxHeap.empty() && currFuel < l)
        {
            currFuel += maxHeap.top();
            maxHeap.pop();
            ans++;
        }
        if (currFuel < l)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}