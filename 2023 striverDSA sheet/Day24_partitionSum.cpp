class Solution {
public:
bool helper(int i,int t,vector<int>& nums,vector<vector<int>> &dp)
{
    // cout<<i<<endl;
    if(t == 0) return true;
    if(i== 0) return t==nums[0];
    if(dp[i][t] != -1) return dp[i][t];
    bool take = false;
    if(t>= nums[i]) take = helper(i-1,t-nums[i],nums,dp);
    bool not_take = helper(i-1,t,nums,dp);
    return dp[i][t] =  take or not_take;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto a:nums)sum += a;
        if(sum%2 != 0) return false;
        // cout<<"hello"<<endl;
        // cout<<sum<<endl;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector(sum/2 + 1,-1));
        return helper(n-1,sum/2,nums,dp);
    }
};