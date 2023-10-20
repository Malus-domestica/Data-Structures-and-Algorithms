#include <bits/stdc++.h>
using namespace std;

//time complexity of heapsort is O(nlogn) where n is number of nodes

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

void heapify(vi &a, int n, int i)//O(log(no. of nodes in given pass))
{
    int maxInd = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n and a[l] > a[maxInd])
        maxInd = l;
    if (r < n and a[r] > a[maxInd])
        maxInd = r;

    if (maxInd != i)
    {
        swap(a[i], a[maxInd]);
        heapify(a, n, maxInd);
    }
}

void heapSort(vi &a)//O(nlogn)
{
    int n = a.size();
    //make maxHeap O(n)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);//this brings the max at the top
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
    heapSort(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}
