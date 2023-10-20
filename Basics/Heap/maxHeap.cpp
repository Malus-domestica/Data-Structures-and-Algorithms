#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

//total time complexity of this algo is O(n)

void heapify(vi &a, int i, int n)//complexity of heapify is O(log(no.of node in given pass))
{
    int maxInd = i;//maxIndex is the index of element with max value
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n and a[l] > a[i])
    {
        maxInd = l;
    }
    if (r < n and a[r] > a[i])
    {
        maxInd = r;
    }
    if (maxInd != i)
    {
        swap(a[i], a[maxInd]);
        heapify(a,maxInd,n);
    }
}

void maxHeap(vi &a)
{
    int n = a.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    maxHeap(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}
