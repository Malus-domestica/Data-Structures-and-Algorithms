#include <bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

string largestNumber(vector<int> &nums)
{
    sort(arr.begin(), arr.end(), compare);
    string ans = "";
    for (int i = 0; i < arr.size(); i++)
        ans += to_string(arr[i]);
    if (ans[0] == '0')
        return "0";
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 2};
    string ans = largestNumber(nums);
    cout << ans << endl;
    return 0;
}
