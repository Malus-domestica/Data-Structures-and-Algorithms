#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> s;
    for (auto e : nums)
    {
        s.insert(e);
    }
    for (auto e : s)
    {
        if (s.find(e - 1) == s.end())
        {
            int cnt = 1;
            int x = e;
            while (s.find(x + 1) != s.end())
            {
                cnt++;
                x++;
            }
            longest = max(cnt, longest);
        }
    }
    return longest;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}
