/*Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, val value must be equal to the sum of val values in left and right children. Consider val value as 0 for NULL child.  Also, leaves are considered to follow the property.*/

#include "binary_tree.h"

bool isLeaf(TreeNode *node)
{
    return (!node->left && !node->right);
}
int isSumProperty(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            if (isLeaf(t))
                continue;
            int ls = 0, rs = 0;
            if (t->left)
            {
                ls += t->left->val;
                q.push(t->left);
            }
            if (t->right)
            {
                rs += t->right->val;
                q.push(t->right);
            }
            if (t->val != (ls + rs))
                return 0;
        }
    }
    return 1;
}