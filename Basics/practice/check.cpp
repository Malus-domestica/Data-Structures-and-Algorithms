#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
int ans = INT_MIN;
int32_t main()
{
    cout << "Pro: " << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    k = k % n;
    int j = 0;
    for (int i = k; i < n; i++)
    {
        v1[i] = v[j++];
    }
    for (int i = 0; i < k; i++)
    {
        v1[i] = v[j++];
    }
    for(int i=0;i<n;i++){
        cout<<v1[i]<<"  ";
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout<<pow(2,v1[i])<<" ";
    }
    return 0;
}