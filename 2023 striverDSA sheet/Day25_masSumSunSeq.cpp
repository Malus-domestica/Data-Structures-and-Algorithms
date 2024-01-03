class Solution{
		
	public:

	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp;
	    for(int i=0;i<=n;i++)
	    {
	        vector<int> arr;
	        for(int j=0;j<=n;j++) arr.push_back(-1);
	        dp.push_back(arr);
	    }
	    return helper(0,-1,arr,dp);
	} 
		int helper(int ind,int prev_ind, vector<int> arr,vector<vector<int>> &dp)
	{
	    if(ind == arr.size()) return dp[ind][prev_ind+1] = 0;
	    
	    if(dp[ind][prev_ind+1] !=-1) return dp[ind][prev_ind+1];
	    
	    //not take
	    int sum = 0+helper(ind+1,prev_ind, arr, dp);
	    
	    //take
	    if(prev_ind ==-1 or arr[ind] > arr[prev_ind])
	    {
	        sum = max(sum, arr[ind]+helper(ind+1,ind, arr, dp));
	    }
	    return dp[ind][prev_ind+1] = sum;
	}
};