#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>> mxHeap(nums.begin(), nums.end());

    for (int i = 1; i < k; i++)
    {
        mxHeap.pop();
    }
    return mxHeap.top();
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}
