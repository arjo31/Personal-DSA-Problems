#include "binary_tree.h"

//Right Side View
void rightRecursion(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(root->val);
    rightRecursion(root->right, level + 1, res);
    rightRecursion(root->left, level + 1, res);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    rightRecursion(root, 0, res);
    return res;
}

//Left Side View
void leftRecursion(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(root->val);
    leftRecursion(root->left, level + 1, res);
    leftRecursion(root->right, level + 1, res);
}

vector<int> leftSideView(TreeNode *root)
{
    vector<int> res;
    leftRecursion(root, 0, res);
    return res;
}