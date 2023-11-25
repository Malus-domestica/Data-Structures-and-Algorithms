#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < B; i++)
        mp[A[i]]++;
    ans.push_back(mp.size());

    for (int i = B; i < A.size(); i++)
    {
        mp[A[i - B]]--;
        if (mp[A[i - B]] == 0)
            mp.erase(A[i - B]);
        mp[A[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 1, 3, 4, 3};
    int B = 3;
    vector<int> ans = dNums(A, B);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
