#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
    }
};

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << "  ";
    printInorder(root->right);
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx == n)
        return NULL;
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        // since node with current key is created hence we have to update index
        *preorder = *preorder + 1;
        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

int main(int argc, char const *argv[])
{
    int preorder [] = {10,2,1,13,11};
    int n=5;
    int preorderIdx = 0;
    Node * root = constructBST(preorder,&preorderIdx, preorder[0],INT_MIN,INT_MAX,n);
    printInorder(root);
    cout << endl;
    return 0;
}
//segmentation fault