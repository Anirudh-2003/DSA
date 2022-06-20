#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int get_max_area(vector<int> a)
{
    int n = a.size(), ans = 0, i = 0;
    stack<int> st;
    a.push_back(0);
    while (i < n)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            int t = st.top();
            int h = a[t];
            st.pop();
            if (st.empty())
            {
                ans = max(ans, h * i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i);
        i++;
    }
    while (!st.empty() && st.top() > 0)
    {
        int t = st.top();
        int h = a[t];
        int len = a.size() - st.top() - 1;
        ans = max(ans, h * len);
        st.pop();
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 3, 5, 6, 2, 3};
    cout << get_max_area(a) << endl;
    return 0;
}