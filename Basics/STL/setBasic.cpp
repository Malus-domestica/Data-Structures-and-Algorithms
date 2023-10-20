#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    //asc order
    for (auto i : s)
        cout << i << " ";
    cout << "\n";

    //desc order
    set<int, greater<int>> s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(2);
    for (auto i : s1)
        cout << i << " ";
    cout << "\n";
    return 0;
}
