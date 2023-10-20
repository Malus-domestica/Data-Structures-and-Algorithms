#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(3);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = head->next;
    cout << hasCycle(head) << endl;
    return 0;
}
