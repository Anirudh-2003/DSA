#include <iostream>
#include <queue>
using namespace std;

class stack
{
    int n;
    queue<int> q1;
    queue<int> q2;
public:
    stack()
    {
        n = 0;
    }
    void Push(int x)
    {
        q2.push(x);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void Pop()
    {
        q1.pop();
        n--;
    }
    int Top()
    {
        return q1.front();
    }
    int Size()
    {
        return n;
    }
};

int main()
{
    stack st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;
    cout << st.Size() << endl;
    return 0;
}