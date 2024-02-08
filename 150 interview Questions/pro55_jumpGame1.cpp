class Solution
{
public:
    // greedy solution
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int goal = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
                goal = i;
        }
        if (goal == 0)
            return true;
        return false;
    }
};

// recursive and memo O(n^2)

class Solution1
{
public:
    bool helper(int i, vector<int> &nums,vector<int> &dp)
    {
        if(nums.size() == 1 ) return true;
        if (i >= nums.size()-1)
            return true;
        if (nums[i] == 0)
            return false;
        if(dp[i] != -1) return dp[i];
        bool ans = false;
        for (int j = 1; j <= nums[i]; j++)
        {
            ans = ans or (helper(i + j, nums,dp));
            if(ans )break;
        }
        cout<<i<<" "<<ans<<endl;
        return dp[i] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size()+1,-1);
        return helper(0, nums,dp);
    }
};