#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        stack<int> s;
        vector<int> ans(n,-1);
        int m = nums2.size();
        vector<int> temp(m,-1);
        //find next greater
        for(int i = m-1;i>=0;i--)
        {
            while (!s.empty() and s.top() <= nums2[i]) {
                s.pop();
            }

            if (!s.empty()) temp[i] = s.top();

            s.push(nums2[i]);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums1[i] == nums2[j])
                {
                    ans[i] = temp[j];
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
