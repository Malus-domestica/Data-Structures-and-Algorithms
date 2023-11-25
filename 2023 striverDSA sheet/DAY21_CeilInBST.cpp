#include<bits/stdc++.h>
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

int inorder_successor(Node *root, int key)
{
    int succ;
    while(root)
    {
        if(key == root->val) return root->val;

        if(key < root->val)
        {
            succ = key;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return succ;
}

int main(int argc, char const *argv[])
{
    return 0;
}
