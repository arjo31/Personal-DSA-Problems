/*You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.*/

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

ListNode *removeNodes(ListNode *head)
{
    stack<ListNode *> st;
    ListNode *temp = head;
    while (temp)
    {
        // if (st.empty())
        // {
        //     st.push(temp);
        //     continue;
        // }
        while (!st.empty() && temp->val > st.top()->val)
            st.pop();
        st.push(temp);
        temp = temp->next;
    }
    ListNode *prev = nullptr;
    ListNode *curr = nullptr;
    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        if (!prev)
            curr->next = nullptr;
        else
            curr->next = prev;
        prev = curr;
    }
    head = prev;
    return head;
}

// Reverse and filter
ListNode *removeNodes(ListNode *head)
{
    ListNode *prev = nullptr, *curr = head;

    while (curr != nullptr)
    {
        swap(curr->next, prev);
        swap(prev, curr);
    }

    ListNode *dummyHead = new ListNode(-1);
    ListNode *tempPrev = dummyHead;
    curr = prev;

    while (curr != nullptr)
    {
        if (curr->val >= tempPrev->val)
        {
            tempPrev->next = curr;
            tempPrev = curr;
            curr = curr->next;
            tempPrev->next = nullptr;
        }
        else
        {
            curr = curr->next;
        }
    }

    ListNode *newPrev = nullptr, *newCurr = dummyHead->next;
    while (newCurr != nullptr)
    {
        swap(newCurr->next, newPrev);
        swap(newPrev, newCurr);
    }

    return newPrev;
}