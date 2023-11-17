#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

//to convert a tree to its mirror
void mirror(struct TreeNode* node)
{
    if (node == NULL)
        return;
    else {
        struct TreeNode* temp;
 
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
 
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
