#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> mxHp;
priority_queue<int, vector<int>, greater<int>> mnHp;

void insert(int x)
{
    if (mxHp.size() == mnHp.size())
    {
        if (mxHp.size() == 0)
            mxHp.push(x);
        else if (x < mxHp.top())
            mxHp.push(x);
        else
            mnHp.push(x);
    }
    else
    {
        // case 1: mxheap.size>minheap.size
        if (mxHp.size() > mnHp.size())
        {
            if (x >= mxHp.top())
                mnHp.push(x);
            else
            {
                int temp = mxHp.top();
                mxHp.pop();
                mnHp.push(temp);
                mxHp.push(x);
            }
        }
        else
        {
            if (x <= mnHp.top())
                mxHp.push(x);
            else
            {
                int temp = mnHp.top();
                mnHp.pop();
                mxHp.push(temp);
                mnHp.push(x);
            }
        }
    }
}

double findmedian()
{
    if (mnHp.size() == mxHp.size())
    {
        return ((mnHp.top() + mxHp.top()) / 2.0);
    }
    else if (mnHp.size() > mxHp.size())
    {
        return mnHp.top();
    }
    else
        return mxHp.top();
}

int main(int argc, char const *argv[])
{
    insert(10);
    cout << findmedian() << endl;
    insert(15);
    cout << findmedian() << endl;
    insert(21);
    cout << findmedian() << endl;
    insert(30);
    cout << findmedian() << endl;
    insert(18);
    cout << findmedian() << endl;
    insert(19);
    cout << findmedian() << endl;
    return 0;
}
