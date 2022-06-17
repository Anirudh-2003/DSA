#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() and arr[q.back()] < arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);

    return 0;
}