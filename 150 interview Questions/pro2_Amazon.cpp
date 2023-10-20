#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            sort(nums.begin(), nums.begin() + i);
            int x = abs(nums[i]);
            int sum = 0;
            while (sum < x)
            {
                sum += nums[0];
                nums.erase(nums.begin());
                i--;
            }
            nums[i] = x;
        }
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans += nums[i];

    cout << "ans : " << ans << endl;
    
    return 0;
}