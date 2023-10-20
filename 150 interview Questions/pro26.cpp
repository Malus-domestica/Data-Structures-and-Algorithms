#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    map<int, int> freq;
    int k;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }
    k = 0;
    for (auto &it : freq)
    {
        nums[k] = it.first;
        cout << it.first << endl;
        k++;
    }
    return k;
}

//optimal and correct
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
         int i = 0;
         int n=arr.size();
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++)
        cout << nums[i] << "  ";
    cout << endl;
    return 0;
}
