#include "binary_tree.h"

TreeNode *createTree(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1; // Start from index 1 since root is already created

    while (i < arr.size())
    {
        TreeNode *t = q.front();
        q.pop();

        if (i < arr.size())
        {
            TreeNode *left = new TreeNode(arr[i]);
            t->left = left;
            q.push(left);
            i++;
        }

        if (i < arr.size())
        {
            TreeNode *right = new TreeNode(arr[i]);
            t->right = right;
            q.push(right);
            i++;
        }
    }
    return root;
}
