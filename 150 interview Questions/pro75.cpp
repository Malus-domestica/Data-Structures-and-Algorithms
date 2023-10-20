#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int e = nums.size();
    map<int, int> freq;
    for (auto ele : nums)
        freq[ele]++;
    nums.clear();

    while (freq[0])
    {
        nums.push_back(0);
        freq[0]--;
    }
    while (freq[1])
    {
        nums.push_back(1);
        freq[1]--;
    }
    while (freq[2])
    {
        nums.push_back(2);
        freq[2]--;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,0,1};
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
