#include <iostream>
using namespace std;

void maxSubArraySum(int arr[], int n, int k, int x)
{
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
    {
        ans = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[k];
        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }
    cout << "Max SubArray Sum Less Than Value x Is: " << ans;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    maxSubArraySum(arr, 6, 3, 20);
    return 0;
}