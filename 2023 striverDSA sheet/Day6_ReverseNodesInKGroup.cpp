#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL or k == 1)
        head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    while (cur->next != NULL)
    {
        cur = cur->next;
        count++;
    }

    while (count >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }

    return dummy->next;
}

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
//using recursion my solution
//considering that list after k node is reversed
//front k nodes are reversed and then current head is attached to (k+1)th node
//front of reversed list is returned
//Time complexity is O(n)
//since all nodes are visited once
//linear space complexity is there
class Solution {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)return NULL;
        int len=0;
        ListNode* ptr=head;
        while(ptr)
        {
            len++;
            ptr=ptr->next;
        }
        return f(head,k,len);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
