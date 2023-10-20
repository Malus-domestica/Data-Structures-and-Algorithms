#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> a, vector<int> b)
{
    return a[2] > b[2];
}
pair<int, int> jobScheduling(vector<vector<int>> arr, int n)
{
    sort(arr.begin(), arr.end(), comparator);

    int ans = 0, cnt = 0;
    int max_deadline = 0;
    for (int i = 0; i < n; i++)
        max_deadline = max(max_deadline, arr[i][1]);

    vector<int> days(max_deadline + 1, -1);

    for (auto a : arr)
    {
        for (int i = a[2]; i <= 1; i--)
        {
            if (days[i] == -1)
            {
                days[i] = a[1];
                cnt++;
                ans += a[2];
                break;
            }
        }
    }
    
    return make_pair(cnt, ans);
}

int main(int argc, char const *argv[])
{
    return 0;
}
