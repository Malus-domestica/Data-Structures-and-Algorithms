#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    //    we can reduce this problem to 2Sum
    // Time complexity will be O(n^2)
    // using two ptr approach after sorting the array
    // once we fix nums[i] then we'll use low and high ptrs to traverse the remaining array
    int low, high;
    unordered_set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        int sum = -nums[i];
        low = i + 1;
        high = n - 1;
        while (low < high)
        {
            if ((nums[low] + nums[high]) == sum)
            {
                vector<int> arr = {nums[i], nums[low], nums[high]};
                sort(arr.begin(), arr.end());
                st.insert(arr);
                low++;
                high--;
            }
            else if (sum > (nums[low] + nums[high]))
                low++;
            else
                high--;
        }
    }
    vector<vector<int>> ans;
    for (auto a : st)
    {
        ans.push_back(a);
    }
    return ans;
}

//copied code
//Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
