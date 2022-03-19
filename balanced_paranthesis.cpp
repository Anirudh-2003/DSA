#include <iostream>
#include <stack>
using namespace std;

bool isvalid(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' ||s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "{[()]}";
    if (isvalid(s))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid String" << endl;
    }
    return 0;
}