/*You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.*/

#include "binary_tree.h"

int ans = 0;
string number = "";
void traverse(TreeNode *root)
{
    if (!root->left && !root->right)
    {
        string num = to_string(root->val);
        char const *n_char = num.c_str();
        number.push_back(*n_char);
        ans += stoi(number);
        number.pop_back();
        return;
    }
    string num = to_string(root->val);
    char const *n_char = num.c_str();
    number.push_back(*n_char);
    if (root->left)
        traverse(root->left);
    if (root->right)
        traverse(root->right);
    number.pop_back();
    return;
}

int sumNumbers(TreeNode *root)
{
    if (!root)
        return 0;
    traverse(root);
    return ans;
}