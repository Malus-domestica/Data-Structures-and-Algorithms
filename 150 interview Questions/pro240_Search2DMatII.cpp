#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int max_row = matrix.size();
    int max_col = matrix[0].size();
    int row = 0;
    int col = max_col - 1;

    while (row<max_row and col>=0)
    {
        int mid = matrix[row][col];
        if (target == mid)
            return true;
        else if (target < mid)col--;
        else row++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    return 0;
}
