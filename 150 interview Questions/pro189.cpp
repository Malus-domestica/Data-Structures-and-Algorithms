#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    if(n==1) return;
    // if(k>n)
    for (int i = n - k; i < n; i++)
        ans.push_back(nums[i]);
    for (int i = 0; i < n - k; i++)
        ans.push_back(nums[i]);
    nums = ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    int k = 2;
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
