#include <bits/stdc++.h>
using namespace std;
// abilivion solution
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> mp;
    for (auto e1 : nums1)
    {
        for (auto e2 : nums2)
            mp[e1 + e2]++;
    }
    int cnt = 0;
    for (auto e3 : nums3)
        for (auto e4 : nums4)
            if (mp[0 - e3 - e4])
                cnt += mp[0 - e3 - e4];
    return cnt;
}

int main(int argc, char const *argv[])
{
    return 0;
}
