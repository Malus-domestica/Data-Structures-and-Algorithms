#include <bits/stdc++.h>
using namespace std;
// Count frequency of each element
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    // to print key:value
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;
    }

    return 0;
}
