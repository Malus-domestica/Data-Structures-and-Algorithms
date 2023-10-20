#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int i;
    for (i = 0; i <= nums.size(); i++)
    {
        if (find(nums.begin(), nums.end(), i) == nums.end())
            break;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(nums)<<endl;
    return 0;
}
