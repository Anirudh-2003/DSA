#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void Push(int x)
    {
        s1.push(x);
    }
    int Pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue Empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval =s2.top();
        s2.pop();
        return topval;
    }
    bool Empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    queue s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    cout << s.Empty() << endl;    
    return 0;
}