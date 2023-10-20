#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<char>> _board;
    string _word;
    int rows, cols, len;
    set<pair<int, int>> path;

public:
    bool dfs(int r, int c, int k)
    {
        if (k == len)
            return true;
        if (r < 0 or c < 0 or r >= rows or c >= cols or (_word[k] != _board[r][c]) or path.find({r, c}) != path.end())
            return false;

        path.insert({r, c});
        bool res = (dfs(r + 1, c, k + 1) or
                    dfs(r - 1, c, k + 1) or
                    dfs(r, c + 1, k + 1) or
                    dfs(r, c - 1, k + 1));
        path.erase({r, c});
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        _board = board;
        _word = word;
        rows = board.size();
        cols = board[0].size();
        len = word.size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    Solution *obj = new Solution();
    cout << obj->exist(board, word) << endl;
    return 0;
}
