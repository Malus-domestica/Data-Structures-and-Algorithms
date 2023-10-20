#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    bool found = false;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        // using two pointers
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int cur = a[i] + a[high] + a[low];
            if (cur == sum)
            {
                found = true;
                break;
            }
            else if (cur < sum)
                low++;
            else
                high--;
        }
    }
    cout << found << endl;
    return 0;
}
