/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/

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

// Stack
bool isPalindrome(ListNode *head)
{
    stack<int> stack;
    ListNode *curr = head;
    while (curr)
    {
        stack.push(curr->val);
        curr = curr->next;
    }
    curr = head;
    while (curr && curr->val == stack.top())
    {
        stack.pop();
        curr = curr->next;
    }
    return curr == nullptr;
}

// Recursion
ListNode *curr;
bool isPalindrome(ListNode *head)
{
    curr = head;
    return solve(head);
}

bool solve(ListNode *head)
{
    if (head == nullptr)
        return true;
    bool ans = solve(head->next) && head->val == curr->val;
    curr = curr->next;
    return ans;
}

// O(1) space
ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *rev = reverse(slow);
    while (rev != nullptr)
    {
        if (head->val != rev->val)
        {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }
    return true;
}