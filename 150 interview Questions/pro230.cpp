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

void inorder(TreeNode *root, int k, int &cnt, int &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, k, cnt, ans);
    cnt++;
    if (cnt == k)
        ans = root->val;
    if (cnt != k)
        inorder(root->right, k, cnt, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans;
    int cnt=0;
    inorder(root,k,cnt,ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(4);
    root->left->right=new TreeNode(2);
    int ans;
    int k=1;
    ans= kthSmallest(root,k);
    cout<<ans<<endl;
    return 0;
}
