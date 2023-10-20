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

Node* insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
       root->left= insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct Node *root = NULL;
    root  = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    printInorder(root);
    cout << endl;
    return 0;
}
