#include <iostream>
#include <vector>
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
    int zerocount = 0, ans = 0, i = 0;
    for (int j = 0 ; j< n; j++)
    {
        if(arr[j] == 0)
        {
            zerocount++;
        }
        while (zerocount > k)
        {
            if(arr[i] == 0)
            {
                zerocount--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    cout << ans << endl;
    return 0;
}