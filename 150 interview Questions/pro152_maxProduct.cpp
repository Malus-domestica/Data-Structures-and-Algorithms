#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int pre = 1, suf = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        pre = pre * arr[i];
        suf = suf * arr[n - 1 - i];
        ans = max(ans, max(pre, suf));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
    return 0;
}
