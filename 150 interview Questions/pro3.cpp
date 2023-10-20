#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;

        unordered_set<char> visited;

        int maxStr = 0;

        for(int r=0;r<n;r++)
        {
            if(visited.find(s[r])==visited.end())
            {
                visited.insert(s[r]);
                maxStr = max(maxStr,r-l+1);

            }
            else
            {
                while(l!=r && s[l]!=s[r])
                    visited.erase(s[l++]);

                //Removing and adding the same element
                visited.erase(s[l++]);
                visited.insert(s[r]);

                maxStr = max(maxStr,r-l+1);
            }
        }

        return maxStr;
    }
};
*/

int lengthOfLongestSubstring(string s)
{
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++)
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

// good solution
int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxLength = 0;
    unordered_set<char> charSet;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (charSet.count(s[right]) == 0)
        {
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        else
        {
            while (charSet.count(s[right]))
            {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
        }
    }

    return maxLength;
}

int main(int argc, char const *argv[])
{
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
