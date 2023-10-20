#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> v;//vector to store {start, end}
    int end, start;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        v.push_back({start, end});
    }
    cout<<endl;
    cout<<"Before sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i][0] << "  " << v[i][1] << endl;
    }
    cout<<endl;
    // sort based on end time
    // custom comparator
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });//sort in ascending order based on end time

    int take = 1;
    end = v[0][1];
    cout<<"After sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i][0] << "  " << v[i][1] << endl;
    }
    cout<<endl;
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] >= end)//start time of new activity should be greater than end time of last activity
        {
            take++;
            end = v[i][1];
        }
    }
    cout << take << "\n";
    return 0;
}
