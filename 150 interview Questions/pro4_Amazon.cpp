#include <bits/stdc++.h>
using namespace std;

vector<int> f()
{
    vector<int> ans;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> adj_list(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        adj_list[arr[i]].push_back(i + 2);
    }

    int sum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        int l = adj_list[i].size();
        if (l > 0)
        {
            sum += l;
            for (int j = 0; j < l; j++)
                sum += adj_list[adj_list[i][j]].size();
            ans.push_back(sum);
            sum = 0;
        }
        else
            ans.push_back(0);
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> ans;
    ans = f();

    cout << endl;
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
