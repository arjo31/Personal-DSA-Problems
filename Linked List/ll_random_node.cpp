/*Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.*/

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

// Space = O(n)
class Solution
{
    vector<ListNode *> v;

private:
    void addNodes(ListNode *head)
    {
        while (head)
        {
            v.push_back(head);
            head = head->next;
        }
    }

public:
    Solution(ListNode *head)
    {
        addNodes(head);
    }

    int getRandom()
    {
        ListNode *randNode = v[rand() % v.size()];
        return randNode->val;
    }
};

// Space - O(1)
class Solution
{
private:
    ListNode *head;
    int size = 0;

    int len(ListNode *head)
    {
        ListNode *mover = head;
        int n = 0;
        while (mover)
        {
            n++;
            mover = mover->next;
        }
        return n;
    }

public:
    Solution(ListNode *head)
    {
        this->head = head;
        size = len(head);
    }

    int getRandom()
    {
        int move = rand() % size;
        ListNode *mover = head;
        while (move)
        {
            mover = mover->next;
            move--;
        }
        return mover->val;
    }
};