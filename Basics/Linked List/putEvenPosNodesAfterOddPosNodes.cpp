// lecture 66
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
        next = NULL;
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

void deleteNode(node *&head, int val)
{
    node *temp;
    // empty list
    if (head == NULL)
    {
        return;
    }
    // if node is first node
    if (head->data == val)
    {
        temp = head->next;
        free(head);
        head = temp;
        return;
    }
    // if node is mid node
    node *ptr;
    ptr = head;
    while (ptr->next->data != val)
    {
        ptr = ptr->next;
    }
    // ptr  points to a node before delnode
    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
    // if node is last node
}

void putEvenAfterOdd(node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    node *odd, *even, *evenStart;
    evenStart = head->next;
    odd = head;
    even = evenStart;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    cout << "CHECK" << endl;
    // even->next = NULL;
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
    putEvenAfterOdd(head);
    display(head);
    return 0;
}
