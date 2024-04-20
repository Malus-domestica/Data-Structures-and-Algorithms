class Solution {
public:
int helper(int r, int c, int rows, int cols, vector<vector<char>> matrix,  vector<vector<int>> &dp,int &mx)
{
    if(r >= rows or c >= cols) return 0;

    if(dp[r][c] != -1) return dp[r][c];

    int right = helper(r,c+1,rows,cols,matrix,dp,mx);
    int diagonal = helper(r+1,c+1,rows,cols,matrix,dp,mx);
    int down = helper(r+1,c,rows,cols,matrix,dp,mx);

    dp[r][c] =0;
    if(matrix[r][c] =='1')
       dp[r][c] = 1+ min(right,min(diagonal,down));
    mx = max(mx,dp[r][c]);
    return dp[r][c] ;
}

    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows,vector(cols,-1));

        int mx = 0;
        helper(0,0,rows,cols,matrix,dp,mx);

        
        return mx*mx;
    }
};