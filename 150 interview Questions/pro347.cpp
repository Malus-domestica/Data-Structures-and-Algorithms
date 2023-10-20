#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (auto e : nums)
    {
        mp[e]++;
    }
    set<pair<int, int>> s;
    for (auto e : mp)
    {
        s.insert({e.second, e.first});
    }
     vector<int> ans;
    set<pair<int, int>>::iterator it;
    it = s.end();
    it--;
    while (k) 
    {
        pair<int, int> e = *it;
        ans.push_back(e.second);
        k--;
        it--;
    }
   
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums, ans;
    int k = 2;
    nums = {
        1,2};
    ans = topKFrequent(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }

    return 0;
}
