#include <bits/stdc++.h>
using namespace std;

void getpermuattion(vector<int> &nums, vector<bool> &freq, vector<int> &arr, vector<vector<int>> &ans)
{

    if (arr.size() == nums.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = true;
            arr.push_back(nums[i]);
            getpermuattion(nums, freq, arr, ans);
            arr.pop_back();
            freq[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> arr;
    vector<bool> freq(nums.size(), false);
    getpermuattion(nums, freq, arr, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
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
