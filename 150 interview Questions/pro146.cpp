#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key,
        value = _value;
    }
};

class LRUCache
{
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> m;//to store key and ptr to node

public:
    LRUCache(int capacity)
    {
        // these two nodes are taken ie head and tail inorder to avoid null condition
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node)
    {
        //addition in always in from in LRU cache
        Node *temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
        // size++;
    }

    void removeNode(Node *node)
    {
        //remove is not always performed from last in LRU cache
        //node can also be removes from between when its demanded by CPU 
        //after removing it from between its put at front
        Node *tempprev = node->prev;
        Node *tempnext = node->next;
        tempprev->next = tempnext;
        tempnext->prev = tempprev;
        // size--;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *resnode = m[key];
            m.erase(key);
            removeNode(resnode); // the node is removed from its prev pos
            addFront(resnode);   // inserted at front
            m[key] = head->next;
            return resnode->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *existingNode = m[key];
            m.erase(key);
            removeNode(existingNode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        addFront(new Node(key, value));
        m[key] = head->next;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}

// struct List
// {
//     int size;
//     Node *head;
//     Node *tail;
//     list()
//     {
//         head = new Node(0, 0);
//         tail = new Node(0, 0);
//         head->next = tail;
//         tail->prev = head;
//         size = 0;
//     }
// };
