#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//taking sorted matrix : row ascending
//col: ascending
int main(int argc, char const *argv[])
{
    int n, m,key,flag=0;;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> key;
    //starting from top right
    int row=0,col=m-1;
    while (row<n && col>=0)
    {
        if(a[row][col] == key) {
            cout<<"Found"<<endl;
            flag = 1;
            break;
        }
        else if(a[row][col] > key) col--;
        else row++;
    }
if(flag == 0) cout<<"Key not found"<<endl;
    return 0;
}