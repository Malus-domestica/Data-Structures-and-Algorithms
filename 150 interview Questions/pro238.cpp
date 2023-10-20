#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    vector<int> from_front(n, 1);
    vector<int> from_back(n, 1);
    for (int i = 1; i < n; i++)
    {
        from_front[i] = from_front[i - 1] * nums[i - 1];
        from_back[(n - 1) - i] = from_back[n - i] * nums[n - i];
    }
    for (int i = 0;  i < n; i++)
        ans.push_back(from_front[i] * from_back[i]);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums, ans;
    nums={-1,1,0,-3,3};
    ans = productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
