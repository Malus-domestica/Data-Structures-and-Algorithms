#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int d) { val = d; }
};

bool getpath(TreeNode *root, vector<int> &arr, int b)
{
    if (root == NULL)
        return false;

    arr.push_back(root->val);

    if (root->val == b)
        return true;

    if (getpath(root->left, arr, b) or getpath(root->right, arr, b))
        return true;

    arr.pop_back();

    return false;
}

vector<int> solve(TreeNode *root, int b)
{
    vector<int> arr;
    if (root == NULL)
        return arr;
    getpath(root, arr, b);
    return arr;
}

int main(int argc, char const *argv[])
{
    return 0;
}
