#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    // declare max heap
    priority_queue<int, vector<int>> mxHp;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mxHp.push(num);
    }
    int sum = 0, count;
    int j;
    for (j = 0; j < n; j++)
    {
        sum += mxHp.top();
        mxHp.pop();
        // cout << sum << endl;
        if (sum >= k)
            break;
    }
    // smallest seq length
    if (j < n)
        cout << j + 1 << endl;
    else
        cout << "No sub sequence found" << endl;
    return 0;
}
