#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    vector<vector<int>> a(k);
    for (int i = 0; i < k; i++)
    {
        int size;
        cout << "Enter size of the array: ";
        cin >> size;
        cout << "Enter elements: " << endl;
        for (int j = 0; j < size; j++)
        {
            int num;
            cin >> num;
            a[i].push_back(num);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnHeap;
    vector<int> idx(k, 0);
    vector<int> ans;

    // pushing first element of all arrays
    for (int i = 0; i < k; i++)
    {
        mnHeap.push({a[i][0], i});
    }
    while (!mnHeap.empty())
    {
        pair<int, int> ele = mnHeap.top();
        ans.push_back(ele.first);
        mnHeap.pop();
        if (idx[ele.second] < a[ele.second].size()-1)
        {
            mnHeap.push({a[ele.second][++idx[ele.second]], ele.second});
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    cout << endl;

    return 0;
}
