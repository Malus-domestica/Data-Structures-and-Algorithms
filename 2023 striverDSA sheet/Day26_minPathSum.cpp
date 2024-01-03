class Solution {
public:
int helper(int i,int j, vector<vector<int>>& grid,vector<vector<int>>  &dp)
{
    if(i==grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
    if(i>= grid.size() or j>= grid[0].size())
        return INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    int right = helper(i,j+1,grid,dp);
    int bottom = helper(i+1,j,grid,dp);
// cout<<right<<" "<<bottom<<endl;
    return dp[i][j] = grid[i][j] + min(right,bottom);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector(m+1,-1));
        return helper(0,0,grid,dp);
    }
};