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

void printpreorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "  ";
    printpreorder(root->left);
    printpreorder(root->right);
}

Node *BSTfromSortedArr(vector<int> arr, int st, int end)
{
    if (st > end)
        return NULL;
    int mid = (st + end) / 2;
    Node *node = new Node(arr[mid]);
    node->left = BSTfromSortedArr(arr, st, mid - 1);
    node->right = BSTfromSortedArr(arr, mid + 1, end);
    return node;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {10,20,30,40,50};
    struct Node *root ;
    root = BSTfromSortedArr(arr, 0,4);
    printpreorder(root);
    cout << endl;
    return 0;
}
