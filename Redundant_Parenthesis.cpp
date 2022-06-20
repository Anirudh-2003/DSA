#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ans;
    int n = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
                n +=1;
            }
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    cout << "Redundant Parenthesis: " << ans << " Number Of Redundant Parenthesis:" << n << endl;
    return 0;
}