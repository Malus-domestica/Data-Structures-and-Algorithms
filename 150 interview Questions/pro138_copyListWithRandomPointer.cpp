#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    private:
  unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
         if (head == nullptr)
      return nullptr;
    if (map.count(head))//The map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container.
      return map[head];

    Node* newNode = new Node(head->val);
    map[head] = newNode;
    newNode->next = copyRandomList(head->next);
    newNode->random = copyRandomList(head->random);
    return newNode;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
