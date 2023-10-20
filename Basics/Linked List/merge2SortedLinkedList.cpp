// lecture 64
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
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

node *merge(node *&head1, node *&head2)
{
    // take dummy node
    node *dummy = new node();
    node *ptr1, *ptr2, *ptr3;

    ptr1 = head1;
    ptr2 = head2;
    ptr3 = dummy;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if (ptr1 != NULL)
        ptr3->next = ptr1;
    else
        ptr3->next = ptr2;
    node *head3;
    head3 = dummy->next;
    return head3;
}

int main(int argc, char const *argv[])
{
    node *head1 = NULL;
    node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);

    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);
    node *head = merge(head1, head2);
    display(head);
    return 0;
}
