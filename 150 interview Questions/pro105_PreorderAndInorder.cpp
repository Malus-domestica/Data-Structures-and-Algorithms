#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        data = val;
    }
};

int search(vector<int> &inorder, int start, int end, int cur)
{
    for (int i = start; i < end; i++)
    {
        if (cur == inorder[i])
            return i;
    }
    return -1;
}

TreeNode *buildInpre(vector<int> &preorder, vector<int> &inorder, int start, int end,int &idx)
{
    // cout << "idx: " << idx << endl;
    if (start > end)
        return NULL;
    int cur = preorder[idx];
    idx++;
    TreeNode *node = new TreeNode(cur);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, cur);
    node->left = buildInpre(preorder, inorder, start, pos - 1,idx);
    node->right = buildInpre(preorder, inorder, pos + 1, end,idx);
    return node;
}

void inorderPrint(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(int argc, char const *argv[])
{
    vector<int> preorder = {1, 2};
    vector<int> inorder = {1,2};
    int st = 0;
    int end = preorder.size() - 1;
    int idx=0;
    TreeNode *root = buildInpre(preorder, inorder, st, end,idx);
    inorderPrint(root);
    cout << endl;
    return 0;
}
