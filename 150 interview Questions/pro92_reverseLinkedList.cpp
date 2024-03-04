#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    int pos = 1;
    ListNode *ptr1, *cur, *ptr2, *left_prev;
    ptr1 = head;
    while (pos != left and ptr1)
    {
        cout << "position1 : "<<pos << endl;
        left_prev = ptr1;
        ptr1 = ptr1->next;
        pos++;
    }
    cout << "left : " << ptr1->val << endl;
    if (ptr1)
        cur = ptr1->next;
    else
        return head;
    while (pos < right  and cur)
    {
        cout << "position2 : "<<pos << endl;
        ptr2 = cur->next;
        cur->next = ptr1;
        ptr1 = cur;
        cur = ptr2;
        pos++;
    }
    if(cur)
    cout << "right : " << cur->val << endl;
    left_prev->next->next = ptr2;
    left_prev->next = ptr1;
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // ListNode *head = new ListNode(3);
    // head->next = new ListNode(5);
    head = reverseBetween(head, 2, 4);
    ListNode *ptr = head;
    int i = 0;
    while (ptr)
    {
        cout << ptr->val << endl;
        ptr = ptr->next;
        i++;
    }
    return 0;
}
