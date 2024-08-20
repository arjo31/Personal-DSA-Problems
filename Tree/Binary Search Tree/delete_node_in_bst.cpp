/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.*/

#include "binary_search_tree.h"

TreeNode *findLastRight(TreeNode *root)
{
    if (root->right == nullptr)
        return root;
    return findLastRight(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == nullptr)
        return root->left;
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->val == key)
        return helper(root);
    TreeNode *dummy = root;
    while (root)
    {
        if (root->val > key)
        {
            if (root->left && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}