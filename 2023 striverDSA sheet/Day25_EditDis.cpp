#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, string word1, string word2, int n, int m)
    {

        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (word1[i] == word2[j])
            return dp[i][j] = 0 + helper(i - 1, j - 1, dp, word1, word2, n, m);

        if (dp[i][j] != -1)
            return dp[i][j];

        int insert = 1 + helper(i, j - 1, dp, word1, word2, n, m);
        int replace = 1 + helper(i - 1, j - 1, dp, word1, word2, n, m);
        int del = 1 + helper(i - 1, j, dp, word1, word2, n, m);

        return dp[i][j] = min(insert, min(replace, del));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector(m + 1, -1));
        return helper(n - 1, m - 1, dp, word1, word2, n, m);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
