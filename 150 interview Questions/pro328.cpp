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

ListNode *oddEvenList(ListNode *head)
{
    ListNode *even_head, *ptr, *even, *odd;
    if (head->next == NULL)
        return head;
    even_head = head->next;
    odd = head;
    even = even_head;
    while ((even and odd) and (even->next and odd->next))
    {
        cout << odd->val << "  " << even->val << endl;
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    cout << "CHECK" << endl;
    odd->next = even_head;
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head = oddEvenList(head);

    ListNode *ptr = head;
    while (ptr)
    {
        cout << ptr->val << "  ";
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}
