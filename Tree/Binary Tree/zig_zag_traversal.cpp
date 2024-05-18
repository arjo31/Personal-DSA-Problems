/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).*/

#include "binary_tree.h"

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true; // true = L->R, false = R->L
    while (!q.empty())
    {
        int size = q.size();
        vector<int> a(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *t = q.front();
            q.pop();

            int index = (flag) ? i : (size - i - 1);
            a[index] = t->val;

            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        flag = !flag;
        ans.push_back(a);
    }
    return ans;
}