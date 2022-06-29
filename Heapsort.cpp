#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int size, int start)
{
    int maxIndex = start;
    int left = (2 * start) + 1;
    int right = (2 * start) + 2;
    if (left < size && arr[left] > arr[maxIndex])
    {
        maxIndex = left;
    }
    if (right < size && arr[right] > arr[maxIndex])
    {
        maxIndex = right;
    }
    if (maxIndex != start)
    {
        swap(arr[start], arr[maxIndex]);
        heapify(arr, size, maxIndex);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}