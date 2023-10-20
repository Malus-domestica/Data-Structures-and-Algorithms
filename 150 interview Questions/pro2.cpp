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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;
    int c = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    ListNode *newHead = new ListNode(c % 10), *next = l1 ? l1->next : NULL;
    c /= 10;
    if (next)
        next->val += c;
    else if (c)
        next = new ListNode(c);
    newHead->next = addTwoNumbers(l2 ? l2->next : NULL, next);
    return newHead;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *ptr1 = l1, *ptr2 = l2;
    ListNode *newl = NULL, *node, *prev;
    while (ptr1 and ptr2)
    {
        cout << "CHECK" << endl;
        node = new ListNode();
        if (newl == NULL)
            newl = node;
        else
            prev->next = node;
        int sum = ptr1->val + ptr2->val + carry;
        if (sum > 9)
        {
            carry = 1;
            int rem = sum % 10;
            node->val = rem;
        }
        else
        {
            node->val = sum;
            carry = 0;
        }
        prev = node;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ListNode *ptr = ptr2;
    if (!ptr2)
        ptr = ptr1;
    while (ptr)
    {
        cout << "CHECK" << endl;
        node = new ListNode();
        prev->next = node;
        int sum = ptr->val + carry;
        if (sum > 9)
        {
            carry = 1;
            int rem = sum % 10;
            node->val = rem;
        }
        else
        {
            node->val = sum;
            carry = 0;
        }
        prev = node;
        ptr = ptr->next;
    }
    if (carry)
    {
        node = new ListNode(1);
        prev->next = node;
    }
    return newl;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    ListNode *l3 = addTwoNumbers(l1, l2);
    ListNode *ptr = l3;
    while (ptr)
    {
        cout << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}
