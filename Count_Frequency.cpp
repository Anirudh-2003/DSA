#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    map<int, int> frequency;
    for (int i = 0; i < size; i++)
    {
        frequency[array[i]]++;
    }
    map<int,int> :: iterator it;
    for (it = frequency.begin(); it != frequency.end(); it++)
    {
        cout << it->first << " -> " << it->second << endl;
    }
    return 0;
}