/*Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.*/

#include "binary_tree.h"

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newRoot = new TreeNode(val, root, nullptr);
        return newRoot;
    }
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;
    while (true)
    {
        int size = q.size();
        while (size--)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (level == depth - 1)
            {
                TreeNode *tempLeft = nullptr;
                TreeNode *tempRight = nullptr;
                if (temp->left)
                    tempLeft = temp->left;
                if (temp->right)
                    tempRight = temp->right;
                TreeNode *newLeft = new TreeNode(val, tempLeft, nullptr);
                TreeNode *newRight = new TreeNode(val, nullptr, tempRight);
                temp->left = newLeft;
                temp->right = newRight;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (level == depth - 1)
            break;
        level++;
    }
    return root;
}