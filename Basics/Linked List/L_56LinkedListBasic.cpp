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

bool search(node *head, int key)
{
    node *temp;
    temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
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

void reverseList(node *&head)
{
    node *nxt, *prev, *current;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        nxt = current->next;
        current->next = prev;
        // move ptrs
        prev = current;
        current = nxt;
    }
    head = prev;
}

// recursive way to reverse a linked list
node* rev(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *prev, *cur;
    cur = head;
    // go to second last node
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    head = rev(head);
    cur->next = head;
    head = cur;
    return head;
}
//tutorial O(n)
node* revList(node* &head){
    if (head == NULL || head->next == NULL)
        return head;
    node *newhead;
    newhead = revList(head->next);
    head->next->next=head;
    head->next = NULL;
    return newhead;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // insertAtBeg(head, 3);
    // display(head);
    // cout << search(head, 5) << endl;
    // deleteNode(head, 3);
    // display(head);
    // deleteNode(head, 2);
    head = revList(head);
    display(head);
    return 0;
}
