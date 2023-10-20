#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

// brute
/*
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            ans.push_back(A[i] + B[j]);
        }
    }
    sort(ans.begin(), ans.end(), compare);
}
*/

// better
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();

    priority_queue<pair<int, pair<int, int>>> maxHeap;
    maxHeap.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    // to keep track of used index
    set<pair<int, int>> myset;
    myset.insert({n - 1, n - 1});
    vector<int> result;

    while (C > 0)
    {
        pair<int, pair<int, int>> top = maxHeap.top();
        maxHeap.pop();

        int sum = top.first;
        int x = top.second.first;
        int y = top.second.second;

        result.push_back(sum);

        if (myset.find({x - 1, y}) == myset.end())
        {
            maxHeap.push({A[x - 1] + B[y], {x - 1, y}});
            myset.insert({x - 1, y});
        }

        if (myset.find({x, y - 1}) == myset.end())
        {
            maxHeap.push({A[x] + B[y - 1], {x, y - 1}});
            myset.insert({x, y - 1});
        }
        C--;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
    vector<int> B = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
    int C = 10;
    vector<int> ans = solve(A, B, C);
    for (int i = 0; i < C; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
