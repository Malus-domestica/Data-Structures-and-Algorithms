#include <bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            if (i > 0 and j > 0 and abs(board[i - 1][j - 1]) == 1)
                cnt++;
            if (i > 0 and abs(board[i - 1][j]) == 1)
                cnt++;
            if (i > 0 and j < m - 1 and abs(board[i - 1][j + 1]) == 1)
                cnt++;
            if (j > 0 and abs(board[i][j - 1]) == 1)
                cnt++;
            if (j < m - 1 and abs(board[i][j + 1]) == 1)
                cnt++;
            if (i < n - 1 and j > 0 and abs(board[i + 1][j - 1]) == 1)
                cnt++;
            if (i < n - 1 and abs(board[i + 1][j]) == 1)
                cnt++;
            if (i < n - 1 and j < m - 1 and abs(board[i + 1][j + 1]) == 1)
                cnt++;
            if (board[i][j] == 1)
            {
                if (cnt < 2)
                    board[i][j] = -1; // dies
                // if (cnt == 2 or cnt == 3)
                //     board[i][j] = 1; // lives
                if (cnt > 3)
                    board[i][j] = -1; // dies
            }
            else
            {
                if (cnt == 3)
                    board[i][j] = 2; // becomes alive
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << board[i][j] << " ";
            if (board[i][j] == -1)
                board[i][j] = 0;
            if (board[i][j] == 2)
                board[i][j] = 1;
        }
        // cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> board = {{1,1},{1,0}};
    int n = board.size();
    int m = board[0].size();
    gameOfLife(board);
    cout << endl;
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
