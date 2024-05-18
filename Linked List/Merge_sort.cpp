#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
Node* middleNode(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* mergeHalves(Node* h1, Node* h2)
{
    if (h1==nullptr || h2==nullptr)
    {
        return (h1==nullptr) ? h2 : h1;
    }
    Node* p = h1;
    Node* q = h2;
    Node* ans = new Node(0);
    Node* curr = ans;
    while (p && q)
    {
        if (p->data < q->data)
        {
            curr->next = p;
            p = p->next;
        }
        else
        {
            curr->next = q;
            q = q->next;
        }
        curr = curr->next;
    }
    if (p!=nullptr || q!=nullptr)
    {
        curr->next = (p!=nullptr) ? p : q;
    }
    return ans->next;
}

Node* sortList(Node* head){
    if (head==nullptr || head->next==nullptr)
    {
        return head;
    }
    Node* mid = middleNode(head);
    Node* newHead = mid->next;
    mid -> next = nullptr;
    Node* leftHalf = sortList(head);
    Node* rightHalf = sortList(newHead);
    return mergeHalves(leftHalf,rightHalf);
}

