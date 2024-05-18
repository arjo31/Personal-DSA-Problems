/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/

#include "binary_tree.h"

bool check(TreeNode *r1, TreeNode *r2)
{
    if (!r1 || !r2)
        return r1 == r2;
    if (r1->val != r2->val)
        return false;
    return check(r1->left, r2->right) && check(r1->right, r2->left);
}

bool isSymmetric(TreeNode *root)
{
    TreeNode *root1 = root;
    TreeNode *root2 = root;
    return check(root1, root2);
}