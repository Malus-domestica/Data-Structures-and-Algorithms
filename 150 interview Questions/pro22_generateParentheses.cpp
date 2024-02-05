#include <bits/stdc++.h>
using namespace std;

void parentheses(int open, int close, vector<char> &arr, vector<string> &ans)
{
    // base case
    if (open == 0)
    {
        // cout<<open<<"  "<<close<<"Hello"<<endl;
        vector<char> temp = arr;
        for (int i = 0; i < close; i++)
            temp.push_back(')');
        string str(temp.begin(), temp.end());
        ans.push_back(str);
        return;
    }
    if (open>0  and close>=0)
    {
        int check = 0;
        if (open < close) // if number of opening parentheses is greater than number of closing parentheses
        {
            arr.push_back(')');
            parentheses(open, close - 1, arr, ans);
            check = 1;
        }
        if (check == 1) // if closing parenthesis is pushed then only pop it
            arr.pop_back();

        arr.push_back('(');
        parentheses(open - 1, close, arr, ans);
        arr.pop_back();
    }
}

/*
class Solution {
public:
    vector<string>result;
    
    void helper(int open,int close,int n,string current)
    {
        if(current.length()==n*2)
        {
            result.push_back(current);
            return;
        }
        if(open<n)  helper(open+1,close,n,current+"(");
        if(close<open)  helper(open,close+1,n,current+")");
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return result;
    }
};
*/

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    vector<char> arr;
    parentheses(n, n, arr, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
        cout << endl;
    }
    cout << "hello Done" << endl;
    return 0;
}

// solution by NeetCode
class Solution {
public:
void gen(int open, int close, vector<char> &arr, vector<string> &ans ,int n)
{
    if(open == n and close == n)
    {
        string str(arr.begin(),arr.end());
        ans.push_back(str);
        return;
    }

    if(open < n)
    {
        arr.push_back('(');
        gen(open+1,close,arr,ans,n);
        arr.pop_back();
    }
    if(close < open)
    {
        arr.push_back(')');
        gen(open,close+1,arr,ans,n);
        arr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        //add open parenthesis when open<n
        //add close parenthesis if close < open
        //push into ans array if open == close == n
        int open = 1;
        int close=0;
        vector<char> arr;
        arr.push_back('(');
        vector<string> ans;
        gen(open,close,arr,ans,n);
        return ans;
    }
};
