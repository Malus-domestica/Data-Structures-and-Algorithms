#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int d) { data = d; }
};

int widthBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int n = q.size();
        int mini = q.front().second; // to make starting from 0

        int first, last;

        for (int i = 0; i < n; i++)
        {
            int cur_id = q.front().second - mini;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
                first = cur_id;
            if (i == n - 1)
                last = cur_id;
            if (node->left)
                q.push({node->left, cur_id * 2 + 1});
            if (node->right)
                q.push({node->right, cur_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
