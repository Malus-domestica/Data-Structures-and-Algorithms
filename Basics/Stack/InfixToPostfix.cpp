#include <bits/stdc++.h>
using namespace std;

int prec(char op)
{
    if (op == '^')
        return 3;
    else if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

bool isValid(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            // cout << s[i] << endl;
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                // cout << s[i] << endl;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
                // cout << s[i] << endl;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
                // cout << s[i] << endl;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        ans = false;
    }
    return ans;
}

string infixToPostfix(string s)
{
    string postfix_exp = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            postfix_exp += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            while (!st.empty() && (st.top() != '(' || st.top() != '{' || st.top() != '{'))
            {
                postfix_exp += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                postfix_exp += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        postfix_exp += st.top();
        st.pop();
    }
    return postfix_exp;
}

int main(int argc, char const *argv[])
{
    cout << isValid("(a-b/c)*(a/k-l)") << endl;
    cout << infixToPostfix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}
