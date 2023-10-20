#include <bits/stdc++.h>
#include <climits>
using namespace std;
// get max sub array sum
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int curSum = 0;
    int mx=INT_MIN;
    //kadane's algo for nonwrap sum
    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum < 0)
            curSum = 0;
        mx = max(curSum, mx);
    }
    int nonwrapSum = mx;//algo below works for wrap sum

    int sum_all = 0;
    // reverse sign of all elements and also sum the elements
    for (int i = 0; i < n; i++)
    {
        sum_all += a[i];
        a[i] = - a[i];
    }
    cout<<"Negative Array: "<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<"  ";
     curSum = 0, mx = INT_MIN;
    // to find sum of non contributing elements using kadane's algo
    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum < 0)
            curSum = 0;
        mx = max(curSum, mx);
    }
    cout << "Sum_all : " <<sum_all<<endl;
    cout << "mx : " <<mx<<endl;
    int wrapSum = sum_all + mx;//negative of negative sum is positive
    cout << "WrapSum : " <<wrapSum<<endl;
    cout << "NonWrapSum : " <<nonwrapSum<<endl;
    cout << "Max sum of sub array: " << max(wrapSum,nonwrapSum)<<endl;
    return 0;
}