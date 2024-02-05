#include<bits/stdc++.h>
using namespace std;

//this solution is givin TLE (complexity O(nm))
// where n is maximum end time
// m is length of arrays
class Solution {
public:
int helper(int end,int ind,vector<vector<int>>& nums,vector<vector<int>>  &dp)
{
    if(ind >= nums.size()) return 0;

    // if(dp[end][ind] != -1) return dp[end][ind];
    
    int maxi = 0+helper(end,ind+1,nums,dp);//not take
    if(nums[ind][0] >= end)//take
      maxi = max(maxi,nums[ind][2]+helper(nums[ind][1],ind+1,nums,dp));
    cout<<end<<" "<<ind<<" "<<maxi<<endl;
    return  maxi;
      
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        // we need to sort on the basis of start time
        vector<vector<int>> nums;
        for(int i=0;i<n;i++) nums.push_back({startTime[i],endTime[i],profit[i]});
        sort(nums.begin(),nums.end());
        // find endTime max
        int maxEnd = INT_MIN;
        for(auto a:endTime) maxEnd = max(maxEnd,a);
        
        vector<vector<int>> dp(maxEnd+1,vector(n+1,-1));
        return helper(0,0,nums,dp);
    }
};
//memoizaton is also givin TLE 19/31
class Solution {
public:
int helper(int end,int ind,vector<vector<int>>& nums,vector<vector<int>>  &dp)
{
    if(ind >= nums.size()) return 0;

    if(dp[end][ind] != -1) return dp[end][ind];
    
    int maxi = 0+helper(end,ind+1,nums,dp);//not take
    if(nums[ind][0] >= end)//take
      maxi = max(maxi,nums[ind][2]+helper(nums[ind][1],ind+1,nums,dp));
    cout<<end<<" "<<ind<<" "<<maxi<<endl;
    return  dp[end][ind]=maxi;
      
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        // we need to sort on the basis of start time
        vector<vector<int>> nums;
        for(int i=0;i<n;i++) nums.push_back({startTime[i],endTime[i],profit[i]});
        sort(nums.begin(),nums.end());
        // find endTime max
        int maxEnd = INT_MIN;
        for(auto a:endTime) maxEnd = max(maxEnd,a);
        
        vector<vector<int>> dp(maxEnd+1,vector(n+1,-1));
        return helper(0,0,nums,dp);
    }
};
//this solution is in tc O(n*n) linear search is used
class Solution {
private: int N, memo[1000001];
private:
    int dfs(vector<vector<int>>&nums, int idx){
        if(idx >= N) return 0;
        if(memo[idx]) return memo[idx];
        int k=idx+1, newJobTime = N + 1;//newJobTime is the index of new job
        while(k<N){
            if(nums[k][0] >= nums[idx][1]) 
            {
                newJobTime=k;
                break;
            }
            k++;
        }
        return memo[idx] = max(dfs(nums, idx + 1), nums[idx][2] + dfs(nums, newJobTime));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        N = size(profit);
        vector<vector<int>> nums;
        for(int i = 0; i < N; ++i) nums.push_back({startTime[i], endTime[i], profit[i]});
        sort(begin(nums), end(nums));
        return dfs(nums, 0);
    }
};


//this solution is accepted with TC:- O(nlog(n)) binary search is used
class Solution {
private: int N, memo[1000001];
private:
    int dfs(vector<vector<int>>&nums, int idx){
        if(idx >= N) return 0;
        if(memo[idx]) return memo[idx];
        int lo = 0, hi = N - 1, newJobTime = N + 1;//newJobTime is the index of new job
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(nums[mid][0] >= nums[idx][1]) newJobTime = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return memo[idx] = max(dfs(nums, idx + 1), nums[idx][2] + dfs(nums, newJobTime));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        N = size(profit);
        vector<vector<int>> nums;
        for(int i = 0; i < N; ++i) nums.push_back({startTime[i], endTime[i], profit[i]});
        sort(begin(nums), end(nums));
        return dfs(nums, 0);
    }
};


// final solution
class Solution {
private: int N;
private:
    int helper(vector<vector<int>>&nums, int ind, vector<int>  &dp){
       if(ind >= nums.size()) return 0;
if(dp[ind] != -1) return dp[ind];
       //not_take
       int maxi = helper(nums,ind+1,dp);

       int low=ind+1;int high=nums.size()-1;int nextJodInd=nums.size();

       while(low<=high)
       {
           int mid = (low+high)/2;
           if(nums[ind][1] <= nums[mid][0]) 
           {
               nextJodInd=mid;
               high = mid-1;
           }
           else low = mid+1;
       }
       cout<<"hello"<<endl;
       maxi = max(maxi,nums[ind][2] + helper(nums,nextJodInd,dp));
       return dp[ind] = maxi;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        N = size(profit);
        vector<vector<int>> nums;
        for(int i = 0; i < N; ++i) nums.push_back({startTime[i], endTime[i], profit[i]});
        sort(begin(nums), end(nums));
        // memo={-1};
        cout<<memo[0]<<endl;
        vector<int> dp(N+1,-1);
        return helper(nums, 0, dp);
    }
};