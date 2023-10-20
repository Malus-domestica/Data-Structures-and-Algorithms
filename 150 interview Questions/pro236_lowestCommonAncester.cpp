#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// void deleteNode(ListNode *node)
// {
//     ListNode *temp = node->next->next;
//     node->val = node->next->val;
//     node->next = temp;
// }

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root; // if both are not null then parent is found
}

int main(int argc, char const *argv[])
{
    return 0;
}
