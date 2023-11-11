#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> left(n);
    vector<int> right(n);
    // find left smaller
    for (int i = 0; i < n; i++)
    {
          cout << "CHECK" << endl;
        while (!st.empty() and a[st.top()] > a[i])
            st.pop();
        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.top();
            
        st.push(i);
    }
    cout << "CHECK" << endl;
    // clear stack
    while (!st.empty())
        st.pop();
    // find right smaller

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] > a[i])
            st.pop();
        if (st.empty())
            right[i] = n;
        else
            right[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << left[i] << " ";
    cout << "" << endl;
    for (int i = 0; i < n; i++)
        cout << right[i] << " ";
    cout << "" << endl;
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        ans[right[i] - left[i] - 2] = max(ans[right[i] - left[i] - 1], a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "" << endl;

    int num = ans[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (ans[i] == 0)
        {
            ans[i] = num;
        }
        else
            num = ans[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<int> a = {3, 3, 4, 2,4};
    vector<int> ans = maxMinWindow(a, n);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "" << endl;

    return 0;
}
