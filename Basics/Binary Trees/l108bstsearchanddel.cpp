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

Node *searchBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->data == val)
    {
        return root;
    }
    if (val < root->data)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
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

// returns the root of new tree after deletion
Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
    {
        // holds the new left pointer after deletion
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {   
        // when key is found
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3
         Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    printInorder(root);
    cout<<endl;
    root = deleteInBST(root, 5);
    printInorder(root);
    cout<<endl;
    return 0;
}
