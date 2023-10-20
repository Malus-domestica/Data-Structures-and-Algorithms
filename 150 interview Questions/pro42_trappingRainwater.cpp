#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = height[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], height[i]);
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], height[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(left[i], right[i]) - height[i];
    cout << left[1] << "  " << right[1] << endl;
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 2, 0, 3, 2, 5};
    cout << trap(nums) << endl;
    return 0;
}
