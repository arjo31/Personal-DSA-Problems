/*You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result: Build the result list and return its head*/

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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    ListNode *q = head1;
    ListNode *p = head1;
    int count1 = 0;
    int count2 = 0;
    while (p && count1 != a - 1)
    {
        count1++;
        p = p->next;
    }
    while (q && count2 != b)
    {
        count2++;
        q = q->next;
    }
    p->next = head2;
    p = head2;
    while (p->next)
    {
        p = p->next;
    }
    p->next = q->next;
    return head1;
}