#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(pair<int, int> v1, pair<int, int> v2)
{
    return v1.first < v2.first;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    v.pop_back();
    vector<int> v2(3, 50);
    swap(v, v2);
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    vector<pair<int, int>> z;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        z.push_back(make_pair(arr[i], i));
    }
    sort(z.begin(), z.end(),mycompare);
    for (int i = 0; i < z.size(); i++)
    {
        arr[z[i].second] = i;
    }
    for (int i = 0; i < z.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}