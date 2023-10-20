#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1, struct meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    else
        return false;
}
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    struct meeting meet[n];
    for (int i = 0; i< n; i++)
    {
    cout<<"CHECK"<<endl;
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }

    sort(meet, meet + n, comparator);

    vector<int> ans;

    ans.push_back(meet[0].pos);
    int limit = meet[0].end;

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start >= limit)
        {
            ans.push_back(meet[i].pos);
            limit = meet[i].end;
        }
    }

    return ans.size();
}

int main(int argc, char const *argv[])
{
    int start[] = {1,
                   3,
                   0,
                   5,
                   8,
                   5};
    int end[] = {2,
                 4,
                 6,
                 7,
                 9,
                 9};
                
    cout<<maxMeetings(start,end,6)<<endl;
    return 0;
}
