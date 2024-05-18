/*You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.*/

#include "binary_tree.h"

int moves = 0;
int dfs(TreeNode *node)
{
    if (!node)
        return 0;
    int left_excess = dfs(node->left);
    int right_excess = dfs(node->right);
    moves += abs(left_excess) + abs(right_excess);
    return node->val - 1 + left_excess + right_excess;
}
int distributeCoins(TreeNode *root)
{
    dfs(root);
    return moves;
}