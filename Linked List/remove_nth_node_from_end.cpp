/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/

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

int length(ListNode *head)
{
    ListNode *p = head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int l = length(head);
    // nth node from end  = (length - n + 1)th node from start
    int diff = l - n + 1;
    ListNode *q = NULL;
    ListNode *p = head;
    int c = 1;
    if (n == l)
    {
        head = head->next;
        delete p;
        return head;
    }
    while (p->next && c != diff)
    {
        c++;
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
    return head;
}

// 2 pointer method...If length not given (One Traversal)
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *p = head;
    ListNode *q = head;
    ListNode *r = nullptr;
    while (--n)
    {
        q = q->next;
    }
    while (q && q->next)
    {
        r = p;
        p = p->next;
        q = q->next;
    }
    if (r == nullptr)
    {
        head = head->next;
        delete p;
        return head;
    }
    r->next = p->next;
    delete p;
    return head;
}