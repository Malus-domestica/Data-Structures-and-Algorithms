class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int res = INT_MAX;
        int total=0;
        for(int r=0;r<n;r++)
        {
            total+=nums[r];
            while(total >= target)
            {
                res = min(res,r-l+1);
                total -= nums[l];
                l++;
            }
        }
        return res == INT_MAX?0:res;
    }
};