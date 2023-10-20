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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *l = LCA(root->left, n1, n2);
    Node *r = LCA(root->right, n1, n2);
    if (l != NULL and r != NULL)
        return root;
    if (l == NULL and r == NULL)
        return NULL;
    if (l != NULL)
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return dist;
    int l = findDist(root->left, k, dist + 1);
    if (l != -1)
        return l;
    return findDist(root->right, k, dist + 1);
}

int distBtwNode(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

int main(int argc, char const *argv[])
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    printInorder(root);
    cout << endl;
    cout << distBtwNode(root, 4, 5) << endl;
    return 0;
}
