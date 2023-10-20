class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mxInd = -1, mx = INT_MIN;
    // to find pivot
    int n = nums.size();
    if (n == 1)
    {
        if (nums[0] = target)
            return -1;
        else
            return 0;
    }
    int s = 0, e = n - 1, mid;
    // we try to find the value of maximum index
    while (s < e)
    {
        mid =(e+s) / 2;
        if ( nums[mid] > nums[s])
            s = mid;
        else
            e = mid;
    }
    // cout<<mid<<endl;
    mxInd = mid, mx = nums[mxInd];
    mid = mxInd;
    cout << mxInd << endl;

    if (target < nums[0])
        s = mxInd + 1, e = n - 1;
    else
        s = 0, e = mxInd;
    if (nums[0] < nums[n - 1])
        s = 0, e = n - 1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target < nums[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
    }
};