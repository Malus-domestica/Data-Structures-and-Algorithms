#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = 0, col = 0, i, j;
    int n = matrix.size();
    int m = matrix[0].size();

    while (row < n and col < m)
    {
        i = row;
        for (j = col; j < m - col; j++)
        {
            cout << "1";
            ans.push_back(matrix[i][j]);
        }

        j = m - 1 - col;
        for (i = row + 1; i < n - row; i++)
        {
            cout << "2";
            ans.push_back(matrix[i][j]);
        }

        i = n - 1 - row;
        for (j = m - 1 - col - 1; j >= col; j--)
        {
            cout << "3";
            ans.push_back(matrix[i][j]);
        }

        j = col;
        for (i = n - 1 - row - 1; i >= 1 + row; i--)
        {
            cout << "4";
            ans.push_back(matrix[i][j]);
        }
        row++;
        col++;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> ans = spiralOrder(nums);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    cout << endl;
    return 0;
}
