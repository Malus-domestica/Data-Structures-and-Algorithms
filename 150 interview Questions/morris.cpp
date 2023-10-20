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

void morrisTraversal(TreeNode *root)
{
    TreeNode *cur = root;
    vector<int> inorder;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right != NULL and prev->right != cur)
                prev = prev->right;
            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
