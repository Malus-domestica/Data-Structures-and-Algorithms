#include <bits/stdc++.h>
using namespace std;

// vector<int> twoSum(vector<int> &nums, int target)
// {
//     int i, l = nums.size();
//     map<int, int> mp;
//     for (i = 0; i < l; i++)
//     {
//         int diff = nums[i] - target;

//         if (mp.find(diff) != mp.end())
//             return {i, mp[diff]};
//         else
//             mp[nums[i]] = i;
//     }
//     return {-1, -1};
// }

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, -2, -3, -4, -5};
    int target = -8;
    vector<int> arr;
    arr = twoSum(nums, target);
    cout << arr[0] << "  " << arr[1] << endl;
    return 0;
}
