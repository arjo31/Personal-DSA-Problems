/*Given the head of a sorted linked list, delete all the niodes that have duplicate values, leaving only distinct numbers from the original list. Return the linked list sorted as well.*/

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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            int data = curr->val;
            while (curr && curr->val == data)
            {
                ListNode *del = curr;
                curr = curr->next;
                delete del;
            }
            prev->next = curr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}