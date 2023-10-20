#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> people, vector<char> status)
{
    int n = people.size();
    int mx = 0;
    cout << n << endl;
    vector<int> maxNum;
    if (status[0] == '+')
        maxNum.push_back(1);
    else
        return -1;
    for (int i = 1; i < n; i++)
    {
        if (status[i] == '+')
        {
            maxNum.push_back(maxNum[i - 1] + 1);
            cout << maxNum[i] << endl;
        }
        else
        {
            maxNum.push_back(maxNum[i - 1] - 1);
        }
    }
    mx = maxNum[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, maxNum[i]);
    return mx;
}

int main(int argc, char const *argv[])
{
    vector<int> people = {1,1};
    vector<char> status = {'-','-'};
    cout << getMax(people, status) << endl;
    return 0;
}
