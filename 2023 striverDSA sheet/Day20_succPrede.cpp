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

Node *inorder_predecessor(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    Node *predecessor = NULL;

    while (root != NULL)
    {
        if (key <= root->val)
            root = root->left;
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

Node *inorder_successor(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    Node *successor = NULL;

    while (root != NULL)
    {
        if (key <= root->val)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}
int main(int argc, char const *argv[])
{
    return 0;
}
