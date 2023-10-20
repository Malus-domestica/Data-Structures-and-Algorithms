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

void inorder(TreeNode *root, vector<int> &inorderArr)
{
    if (root == NULL)
        return;
    inorder(root->left, inorderArr);
    inorderArr.push_back(root->val);
    inorder(root->right, inorderArr);
}

bool isValidBST(TreeNode *root)
{
    vector<int> inorderArr;
    inorder(root, inorderArr);
    for (int i = 1; i < inorderArr.size(); i++)
        if (inorderArr[i] <= inorderArr[i - 1])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    cout << isValidBST(root) << endl;
    return 0;
}
