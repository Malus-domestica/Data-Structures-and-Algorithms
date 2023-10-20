#include <bits/stdc++.h>
using namespace std;

void subsetSums(vector<int> &arr, int i, int sum, int n, vector<int> &ans)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }

    // take
    subsetSums(arr, i + 1, sum + arr[i], n, ans);

    // not take
    subsetSums(arr, i, sum, n, ans);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {};
    int n = arr.size();
    int sum = 0;
    vector<int> ans;
    subsetSums(arr, 0, sum, n, ans);
    sort(ans.begin(), ans.end());
    return 0;
}
