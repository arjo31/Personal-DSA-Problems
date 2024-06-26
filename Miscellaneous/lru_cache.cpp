#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    public:
        class node {
            public:
                int key;
                int val;
                node* next;
                node* prev;
            node(int _key, int _val)
            {
                key = _key;
                val = _val;
            }
        };
        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);

        int cap;
        unordered_map<int,node*>m;

        LRUCache(int capacity)
        {
            cap = capacity;
            head->next = tail;
            tail->prev=head;
        }

        void addNode(node* newNode)
        {
            node* temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
        }

        void deleteNode(node * delNode)
        {
            node * delprev = delNode->prev;
            node * delnext = delNode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
        }

        int get(int key_)
        {
            if (m.find(key_)!=m.end())//Key found
            {
                node * resnode = m[key_];
                int res = resnode->val;
                m.erase(key_);
                deleteNode(resnode);
                addNode(resnode);
                m[key_] = head->next;
                return res;
            }
            return -1;
        }

        void put(int key_, int value)
        {
            if (m.find(key_)!=m.end())
            {
                node * existingNode = m[key_];
                m.erase(key_);
                deleteNode(tail->prev);
            }
            if (m.size()==cap)
            {
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            addNode(new node(key_,value));
            m[key_] = head->next;
        }
};