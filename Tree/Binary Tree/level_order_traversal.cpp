/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/

#include "binary_tree.h"

void levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == nullptr)
        return;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
        cout << t->data << " ";
    }
}

vector<vector<int>> levelOrderNumbers(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> res;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            res.push_back(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        ans.push_back(res);
    }
    return ans;
}