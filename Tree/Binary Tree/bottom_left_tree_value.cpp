/*Given the root of a binary tree, return the leftmost value in the last row of the tree.*/

#include "binary_tree.h"

int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int ans = root->val;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
        else if (!temp->left)
            ans = temp->val;
    }
    return ans;
}