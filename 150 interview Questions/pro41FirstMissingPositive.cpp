#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        int n = nums.size();
        
        for(int i=0;i<n;i++)if(nums[i]>0) mn = min(mn,nums[i]);
        for(int i=0;i<n;i++)mx = max(mx,nums[i]);

        unordered_map<int,int> freq;

        for(int i=0;i<n;i++)freq[nums[i]]++;

        if(mn!=1) return 1;
       
        for(int i=2;i<mx;i++)if(freq[i]==0) return i;

        return mx+1;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
