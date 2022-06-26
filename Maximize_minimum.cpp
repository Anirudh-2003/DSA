#include <iostream>
#include <algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - pos) >= k)
        {
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int LargestminDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1, right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 4, 8, 9, 2, 3, 7, 6, 5};
    int n = 9;
    int k = 3;
    cout << LargestminDistance(arr, n, k) << endl;
    return 0;
}