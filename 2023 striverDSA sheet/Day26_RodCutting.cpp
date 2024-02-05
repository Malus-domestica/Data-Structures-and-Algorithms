class Solution {
public:
int helper(int begin,int end,vector<int> &cuts,vector<vector<int>> &dp)
{
    if((end - begin) == 1 )return 0;
    if(dp[begin][end] != -1) return dp[begin][end] ;
    int ans=INT_MAX;
    for(int i=0;i<cuts.size();i++)
    {
        if(cuts[i]> begin and cuts[i]<end)//when cut can be performed
        {
            ans = min(ans, (end-begin) + helper(begin,cuts[i],cuts,dp) + helper(cuts[i],end,cuts,dp));
        }
    }
    if(ans == INT_MAX) return dp[begin][end] = 0;
    return dp[begin][end] = ans;
}
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(102,vector(102,-1));

     

       return helper(0,n,cuts,dp); 
    }
};

// class Solution {
// public:
//     int dp[101][101];
//     int solve(int start_stick, int end_stick, vector<int>& cuts, int left, int right){
//         if(left > right) return 0;
        
//         if(dp[left][right] != -1) return dp[left][right];
        
//         int cost = 1e9;
        
//         for(int i=left; i<=right; i++){
//             int left_cost = solve(start_stick, cuts[i], cuts, left, i-1);
//             int right_cost = solve(cuts[i], end_stick, cuts, i+1, right);
//             int curr_cost = (end_stick - start_stick) + left_cost + right_cost;
//             cost = min(cost,curr_cost);
//         }
        
//         return dp[left][right] = cost;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         memset(dp,-1,sizeof(dp));
//         sort(cuts.begin(),cuts.end());
//         return solve(0, n, cuts, 0, cuts.size()-1);
//     }
// };