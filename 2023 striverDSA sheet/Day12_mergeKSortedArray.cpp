#include <bits/stdc++.h>
using namespace std;

struct data
{
    int val;
    int kthArray;
    int posInArr;
};

 

vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    vector<int> output;

    typedef pair<int, pair<int, int>> ppi;//we need to typedef it because ppi is not a datatype

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    while (pq.empty() == false)
    {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    return output;
}
