#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *f(ListNode *head, int k, int len)
    {
        if (len < k)
            return head;
        int m = k;
        ListNode *curr = head, *ptr1 = NULL, *ptr2;
        while (m)
        {
            ptr2 = curr->next;
            curr->next = ptr1;
            ptr1 = curr;
            curr = ptr2;
            m--;
        }
        head->next = f(curr, k, len - k);

        return ptr1;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        int len = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            len++;
            ptr = ptr->next;
        }
        return f(head, k, len);
    }
};