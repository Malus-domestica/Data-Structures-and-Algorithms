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
// time Complexity O(n)
int sumReplace(Node *root)
{
    if (root == NULL)
        return 0;
    int sum = sumReplace(root->left) + sumReplace(root->right) + root->data;
    root->data = sum;
    return sum;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int h = max(height(root->left), height(root->right)) + 1;
    return h;
}
//tc O(n^2)
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;
    int lh = height(root->left);
    int rh = height(root->right);
    int diff = abs(lh - rh);
    if (diff <= 1)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printInorder(root);
    cout << endl;
    sumReplace(root);
    printInorder(root);
    cout << endl;
    return 0;
}
