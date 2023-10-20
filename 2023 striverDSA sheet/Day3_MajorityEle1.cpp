#include <bits/stdc++.h>
using namespace std;

//most optimal solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;int res = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(res == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt ==0){
                    cnt=1;
                    res = nums[i];
                }
            }
            // cout<<res<<" ";
        }
        return res;
    }
};