#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int cnt;
        int l = 0, r = 0;
        int n = nums.size();

        while (r < n)
        {
            cnt = 1;
            while (r + 1 < n and nums[r] == nums[r + 1])
            {
                r++;
                cnt++;
            }
            for (int i = 0; i < min(2, cnt); i++)
            {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};