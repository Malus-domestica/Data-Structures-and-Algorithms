#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    // this gives the last node
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

void insertAtBeg(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *revkNode(node *&head, int k)
{
    node *prev, *nxt, *cur;
    cur = head;
    prev = NULL;
    int count = 0;
    while (cur != NULL && count<k)
    {
        nxt = cur->next;
        cur->next = prev;

        prev = cur;
        cur = nxt;
        count++;
    }
    if(nxt!=NULL)
    head->next = revkNode(nxt,k);
    return prev;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    return 0;
}
