/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

#include "binary_tree.h"

// Method 1
void flatten(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

// Method 2
TreeNode *p = NULL;
void flatten(TreeNode *root) // recursive
{
    if (root == nullptr)
        return;
    flatten(root->right);
    flatten(root->left);

    root->right = p;
    root->left = nullptr;
    p = root;
}