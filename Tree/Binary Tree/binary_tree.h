#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode()
    {
        this->val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};