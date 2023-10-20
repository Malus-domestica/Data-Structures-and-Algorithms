#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; // number of activities
    cin >> n;
    set<pair<int, int>> activities; //{end,start}
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        activities.insert({end, start});
    }
    auto f = *(activities.begin());
    int end = f.first;
    int take = 1;        // maintain count of activities performed
    activities.erase(f); // remove first one from top
    for (auto a : activities)
    {
        if (a.second >= end)
        {
            take++;
            end = a.first;
        }
    }
    cout << take << endl;
    return 0;
}
