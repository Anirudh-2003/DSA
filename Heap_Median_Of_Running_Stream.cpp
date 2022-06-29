#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void insert(int n)
{
    if (maxHeap.size() == minHeap.size())
    {
        if (maxHeap.size() == 0)
        {
            maxHeap.push(n);
            return;
        }
        if (n < maxHeap.top())
        {
            maxHeap.push(n);
        }
        else
        {
            minHeap.push(n);
        }
    }
    else
    {
        if (maxHeap.size() > minHeap.size())
        {
            if (n >= maxHeap.top())
            {
                minHeap.push(n);
            }
            else
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(n);
            }
        }
        else
        {
            if (n <= minHeap.top())
            {
                maxHeap.push(n);
            }
            else
            {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(n);
            }
        }
    }
}

double findMedian()
{
    if (maxHeap.size() == minHeap.size())
    {
        return ((maxHeap.top() + minHeap.top()) / 2.0);
    }
    else if (maxHeap.size() > minHeap.size())
    {
        return maxHeap.top();
    }
    else
    {
        return minHeap.top();
    }
}

int main()
{
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    return 0;
}