#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (auto e : nums)
    {
        mp[e]++;
        if (mp[e] > 1)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4};
    cout << containsDuplicate(nums) << endl;
    return 0;
}
