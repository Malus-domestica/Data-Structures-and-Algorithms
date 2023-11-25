#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int inorder_predecessor(Node *root, int key)
{
    int pre = 0;
    while (root != NULL)
    {
        if(key == root->val) return root->val;
        if (key < root->val)
        {
            root = root->left;
        }
        else
        {
            pre = root->val;
            root = root->right;
        }
    }
    return pre;
}

int main(int argc, char const *argv[])
{
    return 0;
}
