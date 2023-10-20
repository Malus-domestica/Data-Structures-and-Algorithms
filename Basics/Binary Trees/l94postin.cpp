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

int search(int inorder[], int start, int end, int cur)
{
    for (int i = start; i < end; i++)
    {
        if (cur == inorder[i])
            return i;
    }
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = end;
    if (start > end)
        return NULL;
    int cur = preorder[idx];
    cout << "cur: " << cur << endl;
    idx--;
    Node *node = new Node(cur);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, cur);
    node->right = buildTree(preorder, inorder, pos + 1, end);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    return node;
}

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(int argc, char const *argv[])
{
    int preorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    cout << endl;
    return 0;
}
