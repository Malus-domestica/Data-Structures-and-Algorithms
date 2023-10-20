#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    int i = 0;//travel direction
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v(sz);
        int j = 0, n = sz;
        while (sz--)
        {
            TreeNode *f = q.front();
            q.pop();
            if (i % 2 == 0)
                v[j] = f->val;
            else
                v[n - j - 1] = f->val;
            j++;
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
        i++;
        ans.push_back(v);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (auto e : ans[i])
            cout << e << "  ";
        cout << endl;
    }
    return 0;
}
