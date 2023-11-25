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

class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }
    bool hasLeft()
    {
        return !myStack.empty();
    }
    /* return next smallest number */
    int next()
    {
        TreeNode *tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node)
        {
            myStack.push(node);
            node = node->left;
        }
    }
};