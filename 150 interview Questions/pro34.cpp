#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &nums, int low, int high, int target)
{
    int ans = nums.size();
    int l = 0;
    int h = nums.size() - 1;
    while (h >= l)
    {
        int mid = (l + h) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int startingPosition = lower_bound(nums, low, high, target);
    int endingPosition = lower_bound(nums, low, high, target + 1) - 1;
    if (startingPosition < nums.size() && nums[startingPosition] == target)
    {
        return {startingPosition, endingPosition};
    }
    return {-1, -1};
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
