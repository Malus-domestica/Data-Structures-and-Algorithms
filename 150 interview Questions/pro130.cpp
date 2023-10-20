#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, int i, int j, set<pair<int, int>> &path)
{
    if (path.find({i, j}) != path.end())
        return;
    path.insert({i, j});
    if (i < board.size() - 1 and board[i + 1][j] == '0')
        dfs(board, i + 1, j, path);
    if (i > 0 and board[i - 1][j] == '0')
        dfs(board, i - 1, j, path);
    if (j < board[0].size() - 1 and board[i][j + 1] == '0')
        dfs(board, i, j + 1, path);
    if (j > 0 and board[i][j - 1] == '0')
        dfs(board, i, j - 1, path);
    board[i][j] = '1';
    path.erase({i, j});
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    set<pair<int, int>> path;
    for (int j = 0; j < m; j++)
        if (board[0][j] == '0')
            dfs(board, 0, j, path);
    for (int i = 1; i < n; i++)
        if (board[i][0] == '0')
            dfs(board, i, 0, path);
    for (int j = 1; j < m; j++)
        if (board[n - 1][j] == '0')
            dfs(board, n - 1, j, path);
    for (int i = 1; i < n - 1; i++)
        if (board[i][m - 1] == '0')
            dfs(board, i, m - 1, path);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '0')
                board[i][j] = 'X';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '1')
                board[i][j] = '0';
        }
    }
}

// new solution
class Solution
{
private:
    int col, row;
    set<pair<int, int>> path;

public:
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 or i >= row or j < 0 or j >= col or path.find({i, j}) != path.end() or board[i][j] == 'X')
            return;
        path.insert({i, j});
        board[i][j] = '1';
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
        path.erase({i, j});
    }
    void solve(vector<vector<char>> &board)
    {
        col = board[0].size();
        row = board.size();

        // capture unsurrounded region
        for (int j = 0; j < col; j++)
            if (board[0][j] == 'O')
                dfs(0, j, board);
        for (int i = 0; i < row; i++)
            if (board[i][col - 1] == 'O')
                dfs(i, col - 1, board);
        for (int j = 0; j < col - 1; j++)
            if (board[row - 1][j] == 'O')
                dfs(row - 1, j, board);
        for (int i = 1; i < row; i++)
            if (board[i][0] == 'O')
                dfs(i, 0, board);

        // capture surrounded region
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        // uncapture unsurrounded region
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', '0', '0', 'X'}, {'X', 'X', '0', 'X'}, {'X', '0', 'X', 'X'}};
    vector<vector<char>> board = {{'X'}};
    solve(board);
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// copied solution
class Solution
{
public:
    void DFS(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if (i < 0 or j < 0 or i >= m or j >= n or board[i][j] != 'O')
            return;
        board[i][j] = '#';
        DFS(board, i - 1, j, m, n);
        DFS(board, i + 1, j, m, n);
        DFS(board, i, j - 1, m, n);
        DFS(board, i, j + 1, m, n);
    }

    void solve(vector<vector<char>> &board)
    {

        int m = board.size();

        if (m == 0)
            return;

        int n = board[0].size();

        // Moving over firts and last column
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }

        // Moving over first and last row
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                DFS(board, 0, j, m, n);
            if (board[m - 1][j] == 'O')
                DFS(board, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};
