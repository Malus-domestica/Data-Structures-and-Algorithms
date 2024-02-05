#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }
    Node *get(int ind)
    {
        return links[ind];
    }
    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;
        // cout << num << endl;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
}
//time complexity
//due to sorting
vector<int>
maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());

    vector<pair<int, pair<int, int>>> offlineQ;

    int q = queries.size();

    for (int i = 0; i < q; i++)
    {
        offlineQ.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(offlineQ.begin(), offlineQ.end());
    vector<int> ans(q, 0);

    int ind = 0;
    Trie trie;
    for (int i = 0; i < q; i++)
    {
        int ai = offlineQ.second.first;
        int xi = offlineQ.second.second;
        while (int < n and arr[ind] < = a[i])
        {
            trie.insert(arr[ind]);
            ind++;
        }
        if (ind == 0)
            ans[qInd] = -1;
        else
            ans[ind] = trie.findMax(xi);
    }
    return ans;
}