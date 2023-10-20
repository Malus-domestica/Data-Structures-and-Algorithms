#include <bits/stdc++.h>
using namespace std;

void getSubsets(int ind, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans)
{
    // base case
    if (ind == nums.size())
    {
        ans.push_back(arr);
        return;
    }

    // take
    arr.push_back(nums[ind]);
    getSubsets(ind + 1, nums, arr, ans);
    // not take
    arr.pop_back();
    getSubsets(ind + 1, nums, arr, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> arr;
    getSubsets(0, nums, arr, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "hello Done" << endl;
    return 0;
}
