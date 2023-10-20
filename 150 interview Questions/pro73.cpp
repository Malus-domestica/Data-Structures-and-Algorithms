#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                s.insert({i, j});
            }
        }
    }

    for (auto e : s)
    {
        int row = e.first, col = e.second;
        for (int i = 0; i < n; i++)
            matrix[i][col] = 0;
        for (int j = 0; j < m; j++)
            matrix[row][j] = 0;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2}, {1,3,1,5}};
    setZeroes(matrix);
    for (auto a :matrix)
    {
        for (auto ele : a)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}
