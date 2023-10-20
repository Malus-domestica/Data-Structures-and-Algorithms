#include <bits/stdc++.h>
using namespace std;
// this uses O(n) extra space
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums3;
    int len = n;
    if (m < n)
        len = m;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[j] <= nums2[i])
            nums3.push_back(nums1[j++]);
        else
            nums3.push_back(nums2[i++]);
    }
    if (i < n)
    {
        while (i < n)
            nums3.push_back(nums2[i++]);
    }
    if (j < m)
    {
        while (j < m)
            nums3.push_back(nums1[j++]);
    }
    nums1.clear();
    for (int k = 0; k < nums3.size(); k++)
        nums1.push_back(nums3[k]);
}
// this uses O(1) extra space
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0)
    {
        nums1 = nums2;
        return;
    }
    else if (n == 0)
        return;

    int len = nums1.size();
    int i = m - 1;
    int j = n - 1;
    int k = len - 1;
    while (i >= 0 and j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    
    if (j != -1)
    {
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int n = 3, m = 3;
    merge2(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
        cout << nums1[i] << " ";
    cout << endl;
    return 0;
}
