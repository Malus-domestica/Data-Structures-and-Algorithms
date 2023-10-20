#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    void helper(vector<int> &nums, vector<int> &freq, vector<int> arr, int &l, int k, vector<int> &ans)
    {
        if (l == k)
            return;
        if (arr.size() == nums.size())
        {
            l++;
            ans = arr;
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                freq[i] = 1;
                arr.push_back(nums[i]);
                helper(nums, freq, arr, l, k, ans);
                arr.pop_back();
                freq[i] = 0;
            }
        }
    }
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        vector<int> ans;
        vector<int> freq(n, 0);
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        vector<int> arr;
        int l = 0;
        helper(nums, freq, arr, l, k, ans);

        string str = "";
        for (int i = 0; i < ans.size(); i++)
        {
            str += to_string(ans[i]);
        }
        return str;
    }
};

// optimal
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1; // 0 based indexing
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
