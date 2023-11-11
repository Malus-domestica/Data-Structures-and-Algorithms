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

vector<int> inorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            // go create thread
            TreeNode *temp = cur->left;
            while (temp->right != NULL and temp->right != cur)
                temp = temp->right;
            
            if (temp->right == NULL)//if thread is not there create 
            {
                temp->right = cur;
                cur = cur->left;
            }
            else if (temp->right == cur)//when thread is there
            {
                temp->right = NULL;//cut the thread
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
