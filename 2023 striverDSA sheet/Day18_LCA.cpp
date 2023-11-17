#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || q == root || p == root)
        return root;

    TreeNode *l = lca(root->left, p, q);
    TreeNode *r = lca(root->right, p, q);

    if (l == NULL)
        return r;
    else if (r == NULL)
        return l;
    else
        return root;
}

int main(int argc, char const *argv[])
{
    return 0;
}
