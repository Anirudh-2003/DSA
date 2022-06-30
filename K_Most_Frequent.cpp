#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        int presentSize = freq.size();
        if (freq[arr[i]] == 0 && presentSize == k)
        {
            break;
        }
        freq[arr[i]]++;
    }
    vector<pair<int, int>> ans;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second != 0)
        {
            pair<int, int> p;
            p.first = it->second;
            p.second = it->first;
            ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    vector<pair<int, int>>::iterator itr;
    for (itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << itr->second << " " << itr->first << endl;
    }
    return 0;
}