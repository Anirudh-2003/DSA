#include <iostream>
using namespace std;

void dnfsort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            int temp1 = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp1;
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            int temp2 = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp2;
            high--;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    dnfsort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}