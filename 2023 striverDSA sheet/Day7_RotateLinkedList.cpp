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

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        if (k == 0)
            return head;

        ListNode *head2 = NULL, *curr;
        int n = 0, m;

        curr = head;
        while (curr)
        {
            curr = curr->next;
            n++;
        }
        if (n == 1)
            return head;

        k = k % n;
        if (k == 0)
            return head;

        m = n - k;
        curr = head;

        while (m - 1 > 0)
        {
            curr = curr->next;
            m--;
        }
        head2 = curr->next;
        curr->next = NULL;

        curr = head2;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = head;

        return head2;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
