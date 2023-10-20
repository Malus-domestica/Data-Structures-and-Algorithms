#include <bits/stdc++.h>
using namespace std;
/*
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
*/
// kadane's  algorithm

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    long long mx = LONG_MIN, sum = 0;
    //tc O(n) 
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        // if (sum > mx)
        // {
            // carry only positive forward
            mx = max(sum, mx);
        // }
        if (sum < 0)
            sum = 0;
    }
    return mx;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1};
    cout << maxSubArray(nums) << endl;
    return 0;
}
