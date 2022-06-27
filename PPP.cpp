#include <iostream>
using namespace std;

bool findFeasible(int boards[], int n, int limits)
{
    int sum = 0, painter = 1;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > limits)
        {
            sum = boards[i];
            painter++;
        }
    }
    return painter;
}

int paintersPartition(int boards[], int n, int m)
{
    int totalLength = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }
    int low = k, high = totalLength;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int painters = findFeasible(boards, n, mid);
        if (painters <= m)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    cout << paintersPartition(arr, 4, 2);
    return 0;
}