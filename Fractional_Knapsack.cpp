#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    double v1 = (double)(a.first / a.second);
    double v2 = (double)(b.first / b.second);
    return v1 > v2;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    int bag;
    cin >> bag;
    int ans = 0;
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
    {
        if (bag >= arr[i].second)
        {
            ans += arr[i].first;
            bag -= arr[i].second;
            continue;
        }
        double valuePerWeight = (double)(arr[i].first / arr[i].second);
        ans += valuePerWeight * bag;
        break;
    }
    cout << ans << endl;
    return 0;
}