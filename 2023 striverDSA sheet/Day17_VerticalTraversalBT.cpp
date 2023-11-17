#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int d) { data = d; }
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto ele = q.front();
        q.pop();
        int vertical = ele.second.first;
        int level = ele.second.second;
        TreeNode *node = ele.first;

        nodes[vertical][level].insert(node->data); // inserting into multiset

        if (node->left)
            q.push({node->left, {vertical - 1, level + 1}});
        if (node->right)
            q.push({node->right, {vertical + 1, level + 1}});
    }
    vector<vector<int>> ans;
    for (auto a : nodes)
    {
        vector<int> col;
        for (auto b : a.second)
        {
            col.insert(col.end(), b.second.begin(), b.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
