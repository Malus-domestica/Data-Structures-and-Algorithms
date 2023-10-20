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

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startCycle;
    int count = 0;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startCycle = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startCycle;
}

bool checkCycle(node *&head)
{
    node *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
//assuming cycle is present
void removeCycle(node *&head)
{
    node *slow, *fast;
    slow = fast = head;
    // bring slow and fast to same position
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    // now bring fast to head
    fast = head;
    // move fast a step and slow also a step
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    makeCycle(head, 3);
    cout << checkCycle(head) << endl;
    removeCycle(head);
    display(head);
    return 0;
}
