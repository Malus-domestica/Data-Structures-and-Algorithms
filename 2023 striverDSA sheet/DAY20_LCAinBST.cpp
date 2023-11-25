#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL or root == p or root == q)
            return root;

        // when both lie on left
        if (root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        // when both lie on right
        if (root->val < p->val and root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // when split occurs at root
        return root;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
