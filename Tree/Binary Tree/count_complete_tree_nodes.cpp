/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.*/

#include "binary_tree.h"

// O(n)
int F(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = F(root->left);
    int right = F(root->right);
    return (left + 1 + right + 1);
}

int countNodes(TreeNode *root)
{
    return F(root) / 2;
}

// O(logn^2)
int findHeightLeft(TreeNode *root)
{
    int hgt = 0;
    while (root)
    {
        hgt++;
        root = root->left;
    }
    return hgt;
}

int findHeightRight(TreeNode *root)
{
    int hgt = 0;
    while (root)
    {
        hgt++;
        root = root->right;
    }
    return hgt;
}

int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
        return (pow(2, lh) - 1); // pow(2,lh) = (1<<lh)

    return 1 + countNodes(root->left) + countNodes(root->right);
}