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

void printleftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == 1)
                cout << node->data << "  ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
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
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    printInorder(root);
    cout << endl;
    printleftView(root);
    cout << endl;
    // int height = 0;
    // cout << is_Balanced(root, &height);
    // printInorder(root);
    // cout << endl;
    return 0;
}
