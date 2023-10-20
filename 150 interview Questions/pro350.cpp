#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> arr;
    for (auto e : nums1)
    {
        if (find(nums2.begin(), nums2.end(), e) != nums2.end())
        {
            arr.push_back(e);
        }
    }
    return arr;
}
// union
vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;  // pointers
    vector<int> Union; // Uninon vector
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}

vector<int> intersect2(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;

    // to maintain visited
    vector<int> visited(B.size(), 0);
    int i = 0, j = 0;

    for (i = 0; i < A.size(); i++)
    {

        for (j = 0; j < B.size(); j++)
        {

            if (A[i] == B[j] && visited[j] == 0)
            {

                // if element matches and has not been matched with any other before
                ans.push_back(B[j]);
                visited[j] = 1;

                break;
            }

            else if (B[j] > A[i])
                break;
            // because array is sorted , element will not be beyond this
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> nums3;
    vector<int>::iterator it;
    it = nums1.begin();
    cout << *(it + 1) << endl;
    nums3 = intersect(nums1, nums2);
    for (auto e : nums3)
        cout << e << "  ";
    cout << endl;
    return 0;
}
