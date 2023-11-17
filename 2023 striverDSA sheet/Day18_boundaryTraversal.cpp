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

bool isLeaf(TreeNode *root)
{
    return root != NULL and root->left == NULL and root->right == NULL;
}

void addLeftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->val);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *cur = root;
    vector<int> temp;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->val);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

void addLeaf(TreeNode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->val);
        return;
    }
    addLeaf(root->left, res);
    addLeaf(root->right, res);
}

vector<int> printBoundary(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->val);
    addLeftBoundary(root, res);
    addLeaf(root, res);
    addRightBoundary(root, res);
    return res;
}

int main(int argc, char const *argv[])
{
    return 0;
}
