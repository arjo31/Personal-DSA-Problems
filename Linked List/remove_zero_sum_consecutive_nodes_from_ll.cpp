/*Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.*/

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

ListNode *removeZeroSumSublists(ListNode *head)
{
    unordered_map<int, ListNode *> mpp;
    ListNode *dummy = new ListNode(0, head);
    ListNode *p = head;
    int totSum = 0;
    mpp[0] = dummy;
    while (p)
    {
        totSum += p->val;
        p = p->next;
    }
    if (totSum == 0)
        return nullptr;
    p = head;
    int sum = 0;
    while (p)
    {
        sum += p->val;
        if (mpp.find(sum) != mpp.end()) // Found
        {
            ListNode *q = mpp[sum];
            ListNode *temp = q;
            int pSum = sum;
            while (temp != p)
            {
                temp = temp->next;
                pSum += temp->val;
                if (temp != p)
                    mpp.erase(pSum);
            }
            q->next = p->next;
        }
        else
        {
            mpp[sum] = p;
        }
        p = p->next;
    }
    return dummy->next;
}