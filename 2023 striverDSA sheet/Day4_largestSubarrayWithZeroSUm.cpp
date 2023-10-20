#include <bits/stdc++.h>
using namespace std;

int longestSubArrWithZeroSum(vector<int> arr)
{
    int s = 0;
    map<int, int> mp;
    int lenMax = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        s += arr[i];
        if (s == 0)
        {
            lenMax = i + 1;
        }
        else
        {
            if (mp.find(s) != mp.end())
            {
                lenMax = max(lenMax, (i - mp[s]));
            }
            else
                mp[s] = i;
        }
    }
    return lenMax;
}

// subarray with sum k
// this is optimal for negatives
// but for positives and 0 it can be further optimized

class Solution
{
public:
    int maxLen(vector<int> &a, int k)
    {
        int n = a.size(); // size of the array.

        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the prefix sum till index i:
            sum += a[i];

            // if the sum = k, update the maxLen:
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e. x-k:
            long long rem = sum - k;

            // Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Finally, update the map checking the conditions:
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};

// optimal for positive and 0 numbers in array
//time complexity is O(2n) at worst 
//else O(n)
//reason:- 
//because l is moving in one direction only so it can move on array only once
//no extra space O(1)
int f(vector<int> &nums, int k)
{
    int n = nums.size();
    int len = 0;
    int l = 0;
    long long sum = 0;
    for (int r = 0; r < n; r++)
    {
        sum += nums[r];
        if (sum > k)
        {
            while (l <= r and sum > k)
            {
                sum -= nums[l++];
            }
        }
        if (sum == k)
            len = max(len, r - l + 1);
    }
    return len;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    cout << f(nums, 6) << endl;
    return 0;
}
