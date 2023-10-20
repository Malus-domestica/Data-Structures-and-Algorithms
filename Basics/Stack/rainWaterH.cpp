#include <bits/stdc++.h>
using namespace std;

int rain_water(vector<int> a)
{
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            // here container is formed
            int cur = a[st.top()];
            st.pop();
            if (st.empty())
            {
                break;
            }
            else
            {
                int width = i - st.top() - 1;
                ans += (min(a[st.top()], a[i]) - a[cur]) * width;
            }
        }
        st.push(i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rain_water(h) << endl;
    return 0;
}
