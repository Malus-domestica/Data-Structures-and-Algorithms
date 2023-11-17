#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigZag(TreeNode *root)
{
    vector<vector<int>> result;

    if (root == NULL)
        return result;

    queue<TreeNode *> q;

    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> row(n);

        for (int i = 0; i < n; i++)
        {
            auto ele = q.front();
            q.pop();

            int index = leftToRight ? i : n - i - 1;
            row[index] = ele->val;

            if (ele->left)
                q.push(ele->left);
            if (ele->right)
                q.push(ele->right);
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    return 0;
}
