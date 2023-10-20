#include <bits/stdc++.h>
using namespace std;
//time complexity O(n)
void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();
    // 1. find break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return ;
    }

    // 2. find just greater element on right side of ind
    // since right side sorted
    for (int i = n - 1; i >= ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[ind], nums[i]);
            break;
        }
    }

    // 3. reverse the right side of the array after ind
    reverse(nums.begin() + ind + 1, nums.end());
}

int main(int argc, char const *argv[])
{
    return 0;
}
