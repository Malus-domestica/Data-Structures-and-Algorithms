#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int len = nums.size();
    int ans = 0;
    int i;
    for (i = 0; i < len ; i++)
    {
        ans = ans xor (nums[i] xor nums[len - 1 - i]);
    }
    if (len % 2 != 0)
        ans = ans xor nums[i];
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4,1,2,1,2};
    cout<<singleNumber(arr)<<endl;
    return 0;
}
