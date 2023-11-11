#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    int l = 0;
    int r = 0;
    while (r<nums.size())
    {
        //pop smaller elements in dq
        while(!dq.empty() and dq.back()<nums[r]) dq.pop_back();

        dq.push_back(nums[r]);

        //now remove elements from front of dq if they are not in range
        while(!dq.empty() and dq.front()<l) dq.pop_front();

        if(r+1 >=k) {
            ans.push_back(dq.front());
            l++;
        }
        r++;
    }
    return ans;
    

}
int main(int argc, char const *argv[])
{
    return 0;
}
