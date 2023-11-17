#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int d) { data = d; }
};

vector<int> bottomView(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)return ans;

    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        auto ele = q.front();
        q.pop();
        int line = ele.second;
        TreeNode *node = ele.first;
        mp[line] = node->data;

        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }

    for(auto a:mp) ans.push_back(a.second);
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
