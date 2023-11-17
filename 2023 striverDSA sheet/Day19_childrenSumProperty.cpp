#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isParentSum(Node *root)
{
    if (root->left == NULL and root->right == NULL)
        return true;
    // Write your code here.
    bool l = root->left ? isParentSum(root->left) : true;
    bool r = root->right ? isParentSum(root->right) : true;

    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    return l and r and (root->data == sum);
}

int main(int argc, char const *argv[])
{
    return 0;
}
