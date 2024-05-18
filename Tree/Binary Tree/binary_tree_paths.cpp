/*Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.*/

#include "binary_tree.h"

void path(vector<string> &res, string cur, TreeNode *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        cur += to_string(root->val);
        res.push_back(cur);
        cur.pop_back();
        return;
    }
    cur += to_string(root->val);
    cur += "->";

    if (root->left)
        path(res, cur, root->left);
    if (root->right)
        path(res, cur, root->right);

    cur.pop_back();
    cur.pop_back();
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string cur;
    path(ans, cur, root);
    return ans;
}

// Another method
bool getPath(TreeNode *root, vector<vector<int>> &ans, vector<int> &a) // Get path from root to leaf node
{
    if (root == nullptr)
    {
        return true;
    }

    a.push_back(root->val);

    bool left = getPath(root->left, ans, a);
    bool right = getPath(root->right, ans, a);

    if (left && right)
    {
        ans.push_back(a);
    }
    a.pop_back();
    return false;
}

vector<string> allRootToLeaf(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> a;
    getPath(root, ans, a);

    vector<string> st;
    for (auto it : ans)
    {
        stringstream ss;
        copy(it.begin(), it.end(), ostream_iterator<int>(ss, " "));
        string s = ss.str();
        s = s.substr(0, s.length() - 1);
        st.push_back(s);
    }
    return st;
}