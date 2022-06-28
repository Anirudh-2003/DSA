#include <iostream>
#include <climits>
using namespace std;

void minSubArraySum(int arr[], int n, int k, int x)
{
    int sum = 0, ans = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum > x)
    {
        ans = min(ans, sum);
    }
    for (int i = k; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        if (sum > x)
        {
            ans = min(ans, sum);
        }
    }
    cout << "Min SubArray Sum Greater Than Value x Is: " << ans;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    minSubArraySum(arr, 6, 3, 18);
    return 0;
}