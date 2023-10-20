#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26] = {NULL};
    bool wordEnd = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        wordEnd = true;
    }
    bool isEnd()
    {
        return wordEnd;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
    bool search(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->containsKey(s[i]))
                return false;
            node = node->get(s[i]);
        }

        return node->isEnd();
    }
    bool startsWith(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->containsKey(s[i]))
                return false;
            node = node->get(s[i]);
        }

        return true;
    }
};



vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    Trie *root = new Trie();
    int len = words.size();
    for (int i = 0; i < len; i++)
    {
        root->insert(words[i]);
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
