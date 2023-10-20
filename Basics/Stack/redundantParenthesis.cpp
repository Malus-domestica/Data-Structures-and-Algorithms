#include <bits/stdc++.h>
using namespace std;

int invalid_paren(string exp)
{
    stack<char> st;
    bool inval = false;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '(' or ch == '+' or ch == '-' or ch == '*' or ch == '/')
            st.push(ch);
        else if (ch == ')' and !st.empty())
        {
            if (st.top() == '(')
            {
                inval = true;
                break;
            }
            while (!st.empty() and st.top() != '(')
            {
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
    }
    return inval;
}

int main(int argc, char const *argv[])
{
    cout << invalid_paren("(a+b)") << endl;
    return 0;
}
