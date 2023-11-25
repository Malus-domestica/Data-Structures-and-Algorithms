#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *create(vector<int> &preorder, int &idx, int n, int upper_bound)
    {
        if (idx >= n or preorder[idx] > upper_bound)
            return NULL;

        TreeNode *root = new TreeNode(preorder[idx++]);

        root->left = create(preorder, idx, n, root->val);
        root->right = create(preorder, idx, n, upper_bound);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int idx = 0;
        int n = preorder.size();
        return create(preorder, idx, n, INT_MAX);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
