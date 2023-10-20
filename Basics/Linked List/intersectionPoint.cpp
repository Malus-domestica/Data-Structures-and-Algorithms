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

void creatIntersection(node *&head1, node *&head2, int pos)
{
    // this function joins end of head2 to pos of head1
    node *ptr1;
    ptr1 = head2;
    // to reach to end of head2
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }

    // to reach to pos in head1
    node *ptr2;
    ptr2 = head1;
    while (ptr2 != NULL && (pos - 1))
    {
        ptr2 = ptr2->next;
        pos--;
    }
    ptr1->next = ptr2;
}

// length of linked list
int len(node *&head)
{
    node *ptr;
    ptr = head;
    int l = 0;
    while (ptr)
    {
        ptr = ptr->next;
        l++;
    }
    return l;
}

// to find the point of intersection
int ptOfIntersection(node *&head1, node *&head2)
{
    int l1, l2, d = 0;
    node *ptr1, *ptr2; // ptr1 points to longer list

    l1 = len(head1);
    l2 = len(head2);

    if (l1 > l2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }

    // bring pointer to the same length
    while (d)
    {
        if (ptr1 == NULL)
            return -1;
        ptr1 = ptr1->next;
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    node *head1 = NULL;
    node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head2, 10);
    insertAtTail(head2, 20);
    insertAtTail(head2, 30);
    insertAtTail(head2, 40);
    display(head1);
    display(head2);
    creatIntersection(head1, head2, 3);
    display(head2);
    cout << ptOfIntersection(head1, head2) << endl;
    return 0;
}
