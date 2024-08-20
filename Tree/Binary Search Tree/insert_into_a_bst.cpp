/*You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.*/

#include "binary_search_tree.h"

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *newNode = new TreeNode(val);
    TreeNode *curr = root;
    TreeNode *parent;
    if (root == NULL)
        return newNode;
    while (curr)
    {
        if (val > curr->val)
        {
            parent = curr;
            curr = curr->right;
        }
        else if (val < curr->val)
        {
            parent = curr;
            curr = curr->left;
        }
    }
    if (parent->val > val)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}