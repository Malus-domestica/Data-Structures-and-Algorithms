#include <bits/stdc++.h>
using namespace std;
//most efficient solution using O(n) complexity
vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;

    vector<vector<int>> bucket(nums.size() + 1);

    for (auto ele : mp)
    {
        cout << "hello" << endl;
        bucket[ele.second].push_back(ele.first);
        cout << ele.first << " " << ele.second << endl;
    }

    vector<int> result;
    cout << endl;
    int j = 0;
    for (int i = n; i >= 0; i--)
    {
        if (bucket[i].size() > 0)
        {
            for (int l = 0; l < bucket[i].size(); l++)
            {
                cout << i << " " << l << endl;
                result.push_back(bucket[i][l]);
                j++;
                if (j >= k)
                    return result;
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, -1};
    int k = 1;
    vector<int> ans = topKFrequent(nums, k);

    for (int i = 0; i < k; i++)
        cout << ans[i] << "  ";
    cout << endl;
    return 0;
}
