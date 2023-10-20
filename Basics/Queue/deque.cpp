// L-83
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    for (auto i : dq)
        cout << i << " ";
    cout << endl;
    dq.pop_back();
    dq.pop_front();
    for (auto i : dq)
        cout << i << " ";
    cout << endl;
    // sliding window maximum
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    // cout << "Check" << endl;
    for (auto &i : a)
    {
        cin >> i;
    }
    deque<int> q; // stores index of largest element
    vector<int> ans;
    // find max in first window
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() and a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    // now iterate over rest given vector
    for (int i = k; i < n; i++)
    {
        if (q.front() == i - k)
            q.pop_front();
        while (!q.empty() and a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}