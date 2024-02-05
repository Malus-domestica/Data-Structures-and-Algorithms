#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26] = {NULL};
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        cout << "put : " << ch << endl;
        links[ch-'a'] = node;    
    }
    Node *get(char ch)
    {
        // cout << "get next of : " << ch << endl;
        return links[ch-'a'];
    }

    bool end()
    {
        // cout << "check end : " << endl;
        return flag;
    }
};

class Trie
{
private:
    Node *root = NULL;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (auto e : word)
        {
            if (!node->containsKey(e))
            {
                // cout<<node->containsKey(e)<<" : ";
                node->put(e, new Node);
            }
            node = node->get(e);
        }
        node->flag = true;
    }

    bool search(string word)
    {
        Node *node = root;
        for (auto e : word)
        {
            if (!node->containsKey(e))
                return false;
            node = node->get(e);
        }
        return node->end();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (auto e : prefix)
        {
            if (!node->containsKey(e))
                return false;
            node = node->get(e);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Trie *trie = new Trie();
    trie->insert("hello");
    cout << trie->search("hello") << endl;
    return 0;
}
