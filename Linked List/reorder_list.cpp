/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/

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

void reorderList(ListNode *head)
{
    ListNode *p = nullptr;
    ListNode *q = nullptr;
    ListNode *temp = head;
    deque<ListNode *> d;
    while (temp)
    {
        d.push_back(temp);
        temp = temp->next;
    }
    temp = nullptr;
    while (!d.empty())
    {
        p = d.front();
        d.pop_front();
        if (q)
            q->next = p;
        if (!d.empty())
        {
            q = d.back();
            d.pop_back();
            p->next = q;
            if (d.empty())
            {
                q->next = nullptr;
            }
        }
        else
        {
            p->next = nullptr;
        }
    }
}