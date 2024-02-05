#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    // finding next greatest
    vector<int> next_greatest(n, -1);
    for (int i = n - 2; i >= 0; i--)
    {
        next_greatest[i] = max(arr[i + 1], next_greatest[i + 1]);
    }
    // finding next greater
    stack<int> st;
    vector<int> next_greater(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        // cout << "hello" << endl;
        while (!st.empty())
        {
            if (st.top() < arr[i])
                st.pop();
            else
                break;
        }
        if (!st.empty())
        {
            next_greater[i] = st.top();
        }
        st.push(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (next_greater[i] != -1 and next_greatest[i] != -1)
        {
            ans = max(abs(next_greater[i] - next_greatest[i]), ans);
        }
    }
   
    cout << ans << endl;
    return 0;
}
