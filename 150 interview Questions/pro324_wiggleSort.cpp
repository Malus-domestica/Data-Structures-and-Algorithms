#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int j = n - 1;
    vector<int> ans(n, 0);
    int i = 1;
    while (i < n)
    {
        ans[i] = nums[j];
        // cout << ans[i] << endl;
        j--;
        i += 2;
    }
    // j = 0;
    i = 0;
    while (i < n)
    {
        ans[i] = nums[j];
        j--;
        i += 2;
    }
    nums = ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,2,2,3,1};
    wiggleSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
