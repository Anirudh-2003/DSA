#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int rainwater_harvesting(vector <int>a)
{
    int n = a.size() , ans = 0;
    stack<int> st;
    for(int i = 0; i< n; i++)
    {
        while(!st.empty() && a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if(st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> a = {0, 1, 4, 2, 1, 3, 2, 3, 1, 2, 3, 2, 1, 3, 0};
    cout << rainwater_harvesting(a) << endl;
    return 0;
}