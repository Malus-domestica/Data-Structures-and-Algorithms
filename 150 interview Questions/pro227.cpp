#include <bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    int curr = 0;
    char op = '+';
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i])) 
        {
            curr = curr * 10 + s[i] - '0';
        }
        if (!isdigit(s[i]) and s[i] != ' ' or i == n - 1)//i == n-1 to evaluate last element
        {
            // cout << op << "  ";
            if (op == '+')
            {
                stk.push(curr);
            }
            else if (op == '-')
            {
                stk.push(-curr);
            }
            else if (op == '*')
            {
                int e = stk.top();
                stk.pop();
                stk.push(e * curr);
            }
            else if (op == '/')
            {
                int e = stk.top();
                stk.pop();
                stk.push(e / curr);
            }
            op = s[i];
            curr = 0;
        }
    }
    int sum = 0;
    // if (stk.empty())
    //     sum = curr;
    while (!stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string s = "2147483647";
    cout << endl;
    cout << calculate(s) << endl;
    return 0;
}
