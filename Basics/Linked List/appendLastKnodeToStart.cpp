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

node *appendKToStart(node *&head, int k)
{
    node *tail, *new_tail, *new_head;
    tail = head;
    int count = 1;
    while (tail != NULL && tail->next != NULL)
    {
        if (count == k - 1)
            new_tail = tail;
        if (count == k)
            new_head = tail;
        tail = tail->next;
        count++;
    }
    new_tail->next = NULL;
    tail->next = head;
    return new_head;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    head = appendKToStart(head, 3);
    display(head);
    return 0;
}