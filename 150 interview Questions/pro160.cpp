#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ptrA, *ptrB, *temp = NULL, *ans = NULL;
    int a = 0, b = 0;
    ptrA = headA;
    ptrB = headB;
    while (ptrA)
    {
        a++;
        ptrA = ptrA->next;
    }
    while (ptrB)
    {
        b++;
        ptrB = ptrB->next;
    }
    if (b < a)
    {
        temp = headB;
        headB = headA;
        headA = temp;
        int t = b;
        b = a;
        a = t;
    }
    ptrB = headB;
    for (int i = 0; i < b - a; i++)
        ptrB = ptrB->next;
    ptrA = headA;
    while (ptrA and ptrB)
    {
        if (ptrA == ptrB)
            return ptrA;
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(7);
    headB->next->next->next = headA->next->next;
    ListNode *ans = getIntersectionNode(headA, headB);
    cout << ans->val << endl;
    return 0;
}
