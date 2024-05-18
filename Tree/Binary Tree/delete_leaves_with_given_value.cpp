/*Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).*/

#include "binary_tree.h"

bool isLeaf(TreeNode *node)
{
    return (node->left == nullptr && node->right == nullptr);
}
void solve(TreeNode *node, int target)
{
    if (node == nullptr)
        return;
    solve(node->left, target);
    solve(node->right, target);

    if (node->left)
        if (isLeaf(node->left) && node->left->val == target)
        {
            node->left = nullptr;
        }
    if (node->right)
        if (isLeaf(node->right) && node->right->val == target)
        {
            node->right = nullptr;
        }
}
TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    solve(root, target);
    if (isLeaf(root) && root->val == target)
        return NULL;
    return root;
}