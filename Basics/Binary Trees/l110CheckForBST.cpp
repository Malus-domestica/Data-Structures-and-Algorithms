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

// check for BST
bool isBST(Node *root, Node *min=NULL, Node *max=NULL)
{
    if (root == NULL)
        return true;
    if (min != NULL and root->data <= min->data)
    {
        return false;
    }
    if (max != NULL and root->data >= max->data)
    {
        return false;
    }

    bool left_valid = isBST(root->left, min, root);
    bool right_valid = isBST(root->right, root, max);
    return left_valid and right_valid;
}

int main(int argc, char const *argv[])
{
    struct Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(4);
    cout<<isBST(root,NULL,NULL)<<endl;
    return 0;
}
// segmentation fault