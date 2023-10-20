#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> stk;
    int len = tokens.size();
    int i = 0;
    while (i < len)
    {
        // cout << tokens[i] << endl;
        if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-")
        {
            int a2 = stk.top();
            stk.pop();
            int a1 = stk.top();
            stk.pop();
            int res = 0;
            if (tokens[i] == "*")
                res = a1 * a2;
            else if (tokens[i] == "+")
                res = a1 + a2;
            else if (tokens[i] == "/")
                res = a1 / a2;
            else if (tokens[i] == "-")
                res = a1 - a2;
            stk.push(res);
        }
        else
        {
            int num = stoi(tokens[i]);
            stk.push(num);
        }
        i++;
    }
    return stk.top();
}

int main(int argc, char const *argv[])
{
    vector<string> t = {"2","1","+","3","*"};
    cout << evalRPN(t) << endl;
    return 0;
}
