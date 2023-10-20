#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> arr;
    arr.push_back({1});
    if (numRows == 1)
    {
        return arr;
    }
    arr.push_back({1, 1});
    if (numRows == 2)
    {
        return arr;
    }
    int j = 1;
    while (j < numRows - 1)
    {
        vector<int> temp2;
        temp2.push_back(1);
        for (int i = 1; i < arr[j].size(); i++)
        {
            int num = arr[j][i - 1] + arr[j][i];
            temp2.push_back(num);
        }
        temp2.push_back(1);
        arr.push_back(temp2);
        j++;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = generate(1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (auto a : arr[i])
            cout << a << "  ";
        cout << endl;
    }
    return 0;
}

// using formula
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int n = numRows;
        vector<vector<int>> ans;
        if (n == 1)
            return {{1}};
        if (n == 2)
            return {{1}, {1, 1}};

        ans.push_back({1});
        ans.push_back({1, 1});

        for (int i = 3; i <= n; i++)
        {
            vector<int> arr;
            int num = 1;
            arr.push_back(1);
            for (int j = 1; j < i; j++)
            {
                num = (num * ((i - 1) - j + 1)) / j;
                arr.push_back(num);
            }
            for (int k = 0; k < arr.size(); k++)
                cout << arr[k] << " ";
            cout << endl;
            ans.push_back(arr);
        }
        return ans;
    }
};