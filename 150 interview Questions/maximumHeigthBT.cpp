#include <bits/stdc++.h>
using namespace std;

struct TreeNode()
{
    int val;
    TreeNode *left;
    TreeNode *right;
}

int maxHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left =  maxHeight(root->left);
    int right =  maxHeight(root->right);
    return 1+ max(left,right);
}

int main(int argc, char const *argv[])
{
    return 0;
}
