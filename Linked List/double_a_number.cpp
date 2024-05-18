/*You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.*/

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

ListNode *doubleIt(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy;
    stack<ListNode *> st;
    while (temp)
    {
        st.push(temp);
        temp = temp->next;
    }
    int carry = 0;
    while (!st.empty())
    {
        temp = st.top();
        st.pop();
        temp->val = temp->val * 2 + carry;
        carry = temp->val / 10;
        temp->val = temp->val % 10;
    }
    return (dummy->val == 0) ? dummy->next : dummy;
}