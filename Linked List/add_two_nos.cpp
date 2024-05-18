/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p = l1;
    ListNode *q = l2;
    int carry = 0;
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    ListNode *a = new ListNode();
    ListNode *b, *c;
    b = a;
    while (p || q)
    {
        int sum = 0;
        if (p)
            sum += p->val;
        else
            sum += 0;
        if (q)
            sum += q->val;
        else
            sum += 0;
        sum += carry;
        carry = sum / 10;
        ListNode *temp = new ListNode(sum % 10);
        if (p)
            p = p->next;
        if (q)
            q = q->next;
        b->next = temp;
        b = temp;
    }
    if (carry == 1)
        b->next = new ListNode(1);
    return a->next;
}