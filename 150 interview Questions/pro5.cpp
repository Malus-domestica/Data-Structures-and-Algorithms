#include <bits/stdc++.h>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    int mxLen = 0;
    int mxInd = -1;
    int i = 0;
    //in this algo we consider i as pivot and expand from there toward left and right
    while (i < n)
    {
        int l, r;
        l = i;
        r = i; // for odd length palindrome sub str
        int len = 0;
        while (l >= 0 and r < n and s[l] == s[r])
        {
            len = r - l + 1;
            if (mxLen < len)
            {
                mxLen = len;
                mxInd = i;
            }
            l--;
            r++;
        }
        l = i;
        r = i + 1; // for even length palindrome sub str
        len = 0;
        while (l >= 0 and r < n and s[l] == s[r])
        {
            len = r - l + 1;
            if (mxLen < len)
            {
                mxLen = len;
                mxInd = i;
            }
            l--;
            r++;
        }
        i++;
    }
    // cout << mxLen << " " << mxInd << endl;
    string ans = "";
    if (mxLen % 2 == 0)
    {
        ans = s.substr((mxInd - mxLen / 2 + 1), mxLen);
    }
    else
    {
        ans = s.substr((mxInd - mxLen / 2), mxLen);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << longestPalindrome("cbbd") << endl;
    return 0;
}
