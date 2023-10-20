#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int l = 1 + maxDepth(root->left);
    int r = 1 + maxDepth(root->right);
    return max(l, r);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(9);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(3);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxDepth(root) << endl;
    return 0;
}
