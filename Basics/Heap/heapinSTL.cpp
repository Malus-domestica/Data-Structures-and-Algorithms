#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>> mxHeap;
    mxHeap.push(2);
    mxHeap.push(3);
    mxHeap.push(1);
    cout << mxHeap.top() << endl;
    mxHeap.pop();
    cout << mxHeap.top() << endl;
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(1);
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;
    return 0;
}
