#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void count(TreeNode *root, int &cnt)
    {
        if (root == NULL)
            return;
        count(root->left, cnt);
        cnt++;
        count(root->right, cnt);
    }
    void solve(TreeNode *root, int k, int &cnt, int &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, k, cnt, ans);
        cnt++;
        if (cnt == k)
            ans = root->val;

        solve(root->right, k, cnt, ans);
    }
    int kthLargest(TreeNode *root, int k)
    {
        int ans;
        int cnt = 0;
        int n = 0;
        count(root, n);
        k = n - k + 1;
        solve(root, k, cnt, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
