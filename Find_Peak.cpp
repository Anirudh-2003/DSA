#include <iostream>
using namespace std;

int findPeakElement(int arr[], int n, int low, int high)
{
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
    {
        return mid;
    }
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return findPeakElement(arr, n, low, mid - 1);
    }
    else
    {
        return findPeakElement(arr, n, mid + 1, high);
    }
}

int main()
{
    int arr[] = {1, 8, 5, 3, 9, 2};
    cout << "Peak Element Index is: " << findPeakElement(arr, 6, 0, 5);
    return 0;
}