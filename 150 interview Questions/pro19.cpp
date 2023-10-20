#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *ptr = head;
    while (ptr)
    {
        ptr = ptr->next;
        len++;
    }
    int pos = len - n;
    ptr = head;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr->next = ptr->next->next;
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next=new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    ListNode *ptr = head;
    head = removeNthFromEnd(head, 2);
    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    return 0;
}
