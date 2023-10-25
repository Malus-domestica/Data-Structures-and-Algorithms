#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> largestValues(TreeNode *root)
{
    queue<TreeNode*> q;
        vector<int> ans={};
        if(root == NULL) return ans;
        int mx = root->val;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            auto ele = q.front();
            q.pop();
           
            if(ele != NULL)
            {
                mx = max(mx,ele->val);
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            else
            {
                ans.push_back(mx);
                 if(q.empty()) break;
                q.push(NULL);
                mx = INT_MIN;
            }
            // cout<<" hello"<<endl;
        }
        return ans;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    vector<int> ans = largestValues(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
