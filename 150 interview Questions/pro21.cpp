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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *ptr1, *ptr2, *ptr3, *newList = NULL, *node;
    int n = 0, m = 0, len;
    ptr1 = list1;
    while (ptr1)
    {
        n++;
        ptr1 = ptr1->next;
    }
    ptr2 = list2;
    while (ptr1)
    {
        m++;
        ptr2 = ptr2->next;
    }
    if (n < m)
        len = n;
    else
        len = m;

    ptr1 = list1, ptr2 = list2;
    for (int i = 1; i <= len; i++)
    {
        node = new ListNode();
        if (ptr1->val < ptr2->val)
        {
            node->val = ptr1->val;
            ptr1 = ptr1->next;
        }
        else
        {
            node->val = ptr2->val;
            ptr2 = ptr2->next;
        }
        if (newList != NULL)
        {
            newList = node;
        }
        else
        {
            ptr3->next = node;
        }
        ptr3 = node;
    }
    if (ptr1 != NULL)
        ptr3->next = ptr1;
    if (ptr2 != NULL)
        ptr3->next = ptr2;
}

int main(int argc, char const *argv[])
{
    return 0;
}
