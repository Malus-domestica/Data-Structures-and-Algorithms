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

class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
private:
    NodeValue largestSubtreeHelper(TreeNode *root)
    {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // get value from left and right subtree
        auto left = largestSubtreeHelper(root->left);
        auto right = largestSubtreeHelper(root->right);

        if (root->val > left.maxNode and root->val < right.minNode)
        {
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    public:
    int maxSumBST(TreeNode* root) {
        return largestSubtreeHelper(root).maxSize;
    }
};