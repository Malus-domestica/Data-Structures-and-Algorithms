#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    for (auto a : nums)
        mp[a]++;
    for (auto ele : mp)
    {
        if (ele.second > n / 2)
            return ele.first;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}
