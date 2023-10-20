#include <stdio.h>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
// for spiral traversal we need to 4 variables
//  one - row_start
//  two - row_end
//  three - column_start
// four - column_end

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "MAtrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // spiral order print
    // int row_start = 0;
    // int row_end = n - 1;
    // int col_start = 0;
    // int col_end = m - 1;

    // while (row_start <= row_end && col_start <= col_end)
    // {
    //     // for row_start
    //     for (int i = col_start; i <= col_end; i++)
    //         cout << a[row_start][i] << " ";
    //     row_start++;
    //     cout << "    ";
    //     // for col_end
    //     for (int i = row_start; i <= row_end; i++)
    //         cout << a[i][col_end] << " ";
    //     ;
    //     col_end--;
    //     cout << "   ";
    //     // for row_end
    //     for (int i = col_end; i >= col_start; i--)
    //         cout << a[row_end][i] << " ";
    //     ;
    //     row_end--;
    //     cout << "   ";
    //     // for col_start
    //     for (int i = row_end; i >= row_start; i--)
    //         cout << a[i][col_start] << " ";
    //     ;
    //     col_start++;
    //     cout << "   ";
    // }
    // cout<<endl;

    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;
    while (row_start <= row_end && column_start <= column_end)
    {
        // row_start
        for (int col = column_start; col <= column_end; col++)
            cout << a[row_start][col] << " ";
        row_start++;
        cout << "   ";

        for (int row = row_start; row <= row_end; row++)
            cout << a[row][column_end] << " ";
        column_end--;
        cout << "   ";
        if (row_start > row_end)
            break;
        for (int col = column_end; col >= column_start; col--)
            cout << a[row_end][col] << " ";
        row_end--;
        cout << "   ";
        if (column_start > column_end)
            break;
        for (int row = row_end; row >= row_start; row--)
            cout << a[row][column_start] << " ";
        cout << "   ";
        column_start++;
    }
    cout << endl;
    return 0;
}
