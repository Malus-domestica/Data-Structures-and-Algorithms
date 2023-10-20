#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *curr, *ptr1, *ptr2;
    ptr1 = NULL;
    curr = head;
    while (curr != NULL)
    {
        ptr2 = curr->next;
        curr->next = ptr1;
        ptr1 = curr;
        curr = ptr2;
    }
    return ptr1;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next =  new ListNode(3);
    head = reverseList(head);
    cout<<endl;
    ListNode *ptr = head;
    while (ptr!=NULL)
    {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
    return 0;
}
