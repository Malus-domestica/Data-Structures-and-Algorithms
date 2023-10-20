#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    while (true)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            root = st.top();
            res.push_back(root->val);
            st.pop();
            root = root->right;
        }
    }
    return res;
}

void inorder(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    TreeNode *root = NULL;
    // TreeNode *root = new TreeNode();
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    arr = inorderTraversal(root);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "  ";
    cout << endl;
    return 0;
}
