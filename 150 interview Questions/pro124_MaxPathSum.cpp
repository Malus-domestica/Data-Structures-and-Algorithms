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

int maxPathSum(TreeNode *root, int &maxSum)
{
    if (root == NULL)
        return 0;

    int l = max(0, maxPathSum(root->left, maxSum));
    int r = max(0, maxPathSum(root->right, maxSum));
    maxSum = max(maxSum, root->val + l + r);
    return root->val + max(l, r);
}

int main(int argc, char const *argv[])
{
    return 0;
}
