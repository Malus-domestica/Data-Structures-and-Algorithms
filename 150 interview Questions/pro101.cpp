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

bool is SymmetricHelp(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return right == left;
    if (left->val != right->val)
        return false;
    return SymmetricHelp(left->left, right->right) && SymmetricHelp(left->right, right->left);
}
bool isSymmetric2(TreeNode *root)
{
    return root == NULL || SymmetricHelp(root->left, root->right);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left == NULL || root->right == NULL)
        return false;

    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    q1.push(root->left);
    q1.push(NULL);
    q2.push(root->right);
    q2.push(NULL);

    while (!q1.empty() && !q2.empty())
    {
        TreeNode *node1 = q1.front();
        q1.pop();
        TreeNode *node2 = q2.front();
        q2.pop();

        if (node1 == NULL xor node2 == NULL)
            return false;
        if ((node1 != NULL and node2 != NULL) and node1->val != node2->val)
            return false;

        if (node1 != NULL and node2 != NULL)
        {
            cout << node1->val << "  " << node2->val << endl;
            if (node1->left)
            {
                q1.push(node1->left);
                if (!node2->right)
                    return false;
            }
            if (node2->right)
            {
                q2.push(node2->right);
                if (!node1->left)
                    return false;
            }
            if (node1->right)
            {
                q1.push(node1->right);
                if (!node2->left)
                    return false;
            }
            if (node2->left)
            {
                q2.push(node2->left);
                if (!node1->right)
                    return false;
            }
        }
        else if (!q1.empty() and !q2.empty())
        {
            q1.push(NULL);
            q2.push(NULL);
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(3);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    cout << isSymmetric(root) << endl;
    return 0;
}
