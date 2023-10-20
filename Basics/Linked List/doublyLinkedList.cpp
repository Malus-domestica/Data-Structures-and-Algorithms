#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next, *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    head->prev = n;
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deletion(node *&head, int pos)
{
    node *temp;
    // only one node
    if (head->next == NULL)
    {
        delete head;
        return;
    }
    int count = 0;
    temp = head;
    while (temp != NULL && count != pos)
    {
        count++;
        temp = temp->next;
    }
    // last node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    // temp is not head
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else // if temp is head
    {
        head = temp->next;
    }
    delete temp;
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // insertAthead(head,5);
    display(head);
    deletion(head, 0);
    display(head);
    return 0;
}
