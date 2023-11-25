#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto ele = q.front();
            q.pop();
            if (ele == NULL)
                s += "#,";
            else
                s += to_string(ele->val) + ",";
            if (ele)
            {
                q.push(ele->left);
                q.push(ele->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        stringstream s(data); // to iteratoe over the string
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto ele = q.front();
            q.pop();

            // left
            getline(s, str, ',');
            if (str == "#")
                ele->left = NULL;
            else
            {
                ele->left = new TreeNode(stoi(str));
                q.push(ele->left);
            }

            // right
            getline(s, str, ',');
            if (str == "#")
                ele->right = NULL;
            else
            {
                ele->right = new TreeNode(stoi(str));
                q.push(ele->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));