#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(vector<string> tokens)
{
    stack<int> st;
    int op1, op2;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "^")
            st.push(stoi(tokens[i]));
        else
        {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();

            switch (tokens[i][0])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

int main(int argc, char const *argv[])
{
    vector<string> exp = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << postfixEvaluation(exp) << endl;
    return 0;
}
