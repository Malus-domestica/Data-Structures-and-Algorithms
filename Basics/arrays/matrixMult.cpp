#include <bits/stdc++.h>
#include <algorithm>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n1, m1;
    cin >> n1 >> m1;
    int a1[n1][m1];
    cout << "matrix 1: " << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> a1[i][j];
        }
    }
    int n2, m2;
    cin >> n2 >> m2;
    int a2[n2][m2];
    cout << "matrix 2: " << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> a2[i][j];
        }
    }
    if (m1 != n2)
        exit(0);
    int sum = 0;
    int mat_ans[n1][m2];
    int j, i, k;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            sum = 0;
            for (k = 0; k <m1;k++){
                sum += (a1[i][k] * a2[k][j]);
            }
            mat_ans[i][j]=sum;
        }
    }
    for ( i = 0; i < n1; i++)
    {
        for ( j = 0; j < m2; j++)
        {
            cout << mat_ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}