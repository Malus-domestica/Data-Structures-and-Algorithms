#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTempTree(TreeNode *root)
{
    TreeNode *newroot = new TreeNode();
    newroot->val = root->val;
    if (root->left)
    {
        newroot->left = createTempTree(root->left);
    }
    if (root->right)
    {
        newroot->right = createTempTree(root->right);
    }
    return newroot;
}

void fillVal(TreeNode *root, vector<int> arr)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    int idx = 0;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node != NULL)
        {
            node->val = arr[idx];
            idx++;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

TreeNode *createCopy(TreeNode *root)
{
    if (root == NULL)
        return root;
    TreeNode *newroot = new TreeNode();
    newroot->val = root->val;
    newroot->left = createCopy(root->left);
    newroot->right = createCopy(root->right);
    return newroot;
}

TreeNode *replaceValueInTree(TreeNode *root)
{
    queue<pair<TreeNode *, TreeNode *>> q;
    TreeNode *newRoot = new TreeNode();
    newRoot = createCopy(root);
    queue<pair<TreeNode *, TreeNode *>> q1;

    int sum = 0;

    if (root->left)
    {
        q.push({root->left, root}); //{*child,*parent}
        q1.push({newRoot->left, newRoot});
        sum += root->left->val;
    }
    if (root->right)
    {
        q.push({root->right, root});
        q1.push({newRoot->right, newRoot});
        sum += root->right->val;
    }

    q.push({NULL, NULL});
    q1.push({NULL, NULL});
    newRoot->val = 0;
    while (!q.empty())
    {
        auto element = q.front();
        TreeNode *node = element.first;
        TreeNode *parent = element.second;
        auto element1 = q1.front();
        q.pop();
        q1.pop();
        if (node != NULL)
        {
            int v = sum - node->val;
            if (parent->left and node != parent->left)
            {
                v -= parent->left->val;
            }
            else if (parent->right and node != parent->right)
            {
                v -= parent->right->val;
            }
            element1.first->val = v;
            if (node->right)
            {
                q.push({node->right, node});
                q1.push({element1.first->right, node});
            }
            if (node->left)
            {
                q.push({node->left, node});
                q1.push({element1.first->left, node});
            }
        }
        else if (!q.empty())
        {
            sum = 0;
            queue<pair<TreeNode *, TreeNode *>> temp = q;
            while (!temp.empty())
            {
                auto ele = temp.front();
                sum += ele.first->val;
                temp.pop();
            }
            q.push({NULL, NULL});
            q1.push({NULL, NULL});
        }
    }
    return newRoot;
}

void display(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root != NULL)
        cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int main(int argc, char const *argv[])
{
    struct TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(10);
    root->right->right = new TreeNode(7);
    root = replaceValueInTree(root);
    display(root);
    return 0;
}
