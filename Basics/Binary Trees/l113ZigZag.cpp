#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
    }
};

void zigzagTraversal(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> currentLevel;
    stack<Node *> nextLevel;
    stack<Node *> temp;
    vector<int> ans;

    bool leftToright = true;

    Node *node;

    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        int n = currentLevel.size();
        for (int i = 0; i < n; i++)
        {
            node = currentLevel.top();
            ans.push_back(node->data);
            currentLevel.pop();
            if (leftToright)
            {
                if (node->left != NULL)
                    nextLevel.push(node->left);
                if (node->right != NULL)
                    nextLevel.push(node->right);
            }
            else
            {
                if (node->right != NULL)
                    nextLevel.push(node->right);
                if (node->left != NULL)
                    nextLevel.push(node->left);
            }
        }
        // swapping
        temp = currentLevel;
        currentLevel = nextLevel;
        nextLevel = temp;
        leftToright = !leftToright;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    struct Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    zigzagTraversal(root);
    cout<<endl;
    return 0;
}
