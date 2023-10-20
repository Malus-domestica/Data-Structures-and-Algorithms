#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node *root1, Node *root2)
{
    // cout << "check"
    //      << " ";
    if (root1 == NULL and root2 == NULL)
        return true;
    bool c1 = false, c2 = false, c3 = false;
    if (root1 != NULL and root2 != NULL)
    {
        if (root1->data == root2->data)
            c1 = true;
        c2 = isIdentical(root1->left, root2->left);
        c3 = isIdentical(root1->right, root2->right);
    }
    if (c1 and c2 and c3)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    struct Node *root1 = new Node(1);
    root1->right = new Node(3);
    root1->right->left = new Node(2);
    // root1->right->right = new Node(5);
    // cout << "check"
    //      << endl;

    struct Node *root2 = new Node(1);
    root2->right = new Node(3);
    root2->right->left = new Node(2);
    root2->right->right = new Node(8);
    cout << isIdentical(root1, root2);
    cout << endl;
    return 0;
}
