#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << s.size() << endl;
    s.erase(5);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    multiset<int> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(3);
    t.insert(3);
    for (auto i : t)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << t.size() << endl;
    t.erase(3);
    for (auto i : t)
    {
        cout << i << " ";
    }
    cout << endl;
    unordered_set<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(3);
    a.insert(3);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << a.size() << endl;
    return 0;
}