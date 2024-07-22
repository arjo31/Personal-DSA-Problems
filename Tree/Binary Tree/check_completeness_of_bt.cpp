/*Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.*/

#include "binary_tree.h"
using namespace std;

bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool flag = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                if (flag)
                    return false;
                q.push(temp->left);
            }
            else
                flag = 1;

            if (temp->right)
            {
                if (flag)
                    return false;
                q.push(temp->right);
            }
            else
                flag = 1;
        }
    }
    return true;
}