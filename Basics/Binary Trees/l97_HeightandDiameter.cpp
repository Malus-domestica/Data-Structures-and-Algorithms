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
// time complexity O(n) where n is number of nodes
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int h = max(height(root->left), height(root->right)) + 1;
    return h;
}
// O(n^2)
int calcDia(Node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDia = lHeight + rHeight + 1;
    int lDia = calcDia(root->left);
    int rDia = calcDia(root->right);
    return max(currDia, max(rDia, rDia));
}

// optimized version of dia calc O(n)
// it is the longest path between any 2 leaves
// root may or may not be part of diameter
int calcDiam(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDia = calcDiam(root->left, &lh);
    int rDia = calcDiam(root->right, &rh);
    int curDia = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(curDia, max(lDia, rDia));
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
    cout << height(root) << endl;
    cout << calcDia(root) << endl;
    int h = 0;
    cout << calcDiam(root, &h) << endl;
    return 0;
}
