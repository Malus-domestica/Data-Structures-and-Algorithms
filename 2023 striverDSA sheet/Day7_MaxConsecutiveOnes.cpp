#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int mx_len=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)cnt++;
            else cnt=0;
            mx_len = max(mx_len,cnt);
        }
        return mx_len;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
