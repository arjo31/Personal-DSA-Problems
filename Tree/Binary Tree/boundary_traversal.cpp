/*Given a Binary Tree, perform the boundary traversal of the tree. The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.*/

#include "binary_tree.h"

bool isLeaf(TreeNode *root)
{
    return (root->left == nullptr && root->right == nullptr);
}

void leftBoundary(TreeNode *root, vector<int> &ans)
{
    TreeNode *t = root->left;
    while (t)
    {
        if (!isLeaf(t))
            ans.push_back(t->val);
        if (t->left)
            t = t->left;
        else
            t = t->right;
    }
}

void rightBoundary(TreeNode *root, vector<int> &ans)
{
    TreeNode *t = root->right;
    vector<int> temp;
    while (t)
    {
        if (!isLeaf(t))
            temp.push_back(t->val);
        if (t->right)
            t = t->right;
        else
            t = t->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void addLeaf(TreeNode *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->val);
        return;
    }
    if (root->left)
        addLeaf(root->left, ans);
    if (root->right)
        addLeaf(root->right, ans);
}

vector<int> traverseBoundary(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    if (isLeaf(root) == false)
        ans.push_back(root->val);
    leftBoundary(root, ans);
    addLeaf(root, ans);
    rightBoundary(root, ans);
    return ans;
}