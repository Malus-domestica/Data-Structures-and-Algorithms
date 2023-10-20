#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;

    vector<int> nums;
    while (i < mid + 1 and j <= high)
    {
        if (arr[i] < arr[j])
            nums.push_back(arr[i++]);
        else
            nums.push_back(arr[j++]);
    }

    if (i < mid + 1)
    {
        while (i < mid + 1)
            nums.push_back(arr[i++]);
    }
    if (j <= high)
    {
        while (j <= high)
            nums.push_back(arr[j++]);
    }
    int l = 0;
    for (int k = low; k <= high; k++)
        arr[k] = nums[l++];
}
int countInversion(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int j = mid + 1, i;
    for (i = low; i < mid + 1; i++)
    {
        while (j <= high and arr[i] > 2 * arr[j])
            j++;
        cnt += (j - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;
    int cnt = 0;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countInversion(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,4,3,5,1};
    int n = mergeSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << "\n n: " << n << endl;
    return 0;
}
