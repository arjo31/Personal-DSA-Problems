/*Given a Binary Tree and a reference to a root belonging to it. Return the path from the root node to the given leaf node.

No two nodes in the tree have the same data value.
It is assured that the given node is present and a path always exists.*/

#include "binary_tree.h"

bool getPath(TreeNode *root, vector<int> &arr, int x)
{
    if (!root)
    {
        return false;
    }
    arr.push_back(root->val);

    if (root->val == x)
    {
        return true;
    }
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode *A, int B)
{
    vector<int> arr;
    if (A == NULL)
    {
        return arr;
    }
    getPath(A, arr, B);
    return arr;
}