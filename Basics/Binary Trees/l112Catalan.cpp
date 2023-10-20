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

// we will use  dp to optimise this code
int catalan(int n)
{
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

void printpreorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "  ";
    printpreorder(root->left);
    printpreorder(root->right);
}

vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtrees = constructTrees(start, i - 1);
        vector<Node *> rightSubtrees = constructTrees(i + 1, end);
        cout<<i<<" : " <<leftSubtrees.size()<<endl;
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                Node *right = rightSubtrees[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }

    return trees;
}

int main(int argc, char const *argv[])
{
    vector<Node *> totalTrees = constructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << ": ";
        printpreorder(totalTrees[i]);
        cout << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        // cout << catalan(i) << "  ";
    }
    cout << endl;
    return 0;
}
