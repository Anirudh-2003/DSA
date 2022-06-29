#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    map<int, int> mp;
    unordered_map<int, int> ump;
    mp[8] = 2;
    ump[8] = 3;
    cout << mp[8] << endl;
    cout << ump[8] << endl;
    return 0;
}