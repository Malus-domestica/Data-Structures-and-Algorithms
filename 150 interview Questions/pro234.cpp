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

bool isPalindrome(ListNode *head)
{
    vector<int> arr;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        arr.push_back(ptr->val);
        ptr = ptr->next;
    }

    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] != arr[j])
            return false;
        j--;
        i++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << isPalindrome(head) << endl;
    return 0;
}
