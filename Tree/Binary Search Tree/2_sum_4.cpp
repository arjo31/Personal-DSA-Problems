/*Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.*/

#include "binary_search_tree.h"
using namespace std;

unordered_set<int> mySet;

bool findTarget(TreeNode *root, int k)
{
    if (!root)
        return false;
    if (mySet.count(k - root->val))
        return true;
    mySet.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
}