#include "binary_tree.h"

// Requirements needed to construct a unique binary tree
bool isPossibleToCreateAUniqueBT(int a, int b) // 1 - pre, 2 - in, 3 - post
{
    // If one travesal is inorder and other is not, then return 'true'.
    if ((a == 2 && b != 2) || (a != 2 && b == 2))
    {
        return true;
    }
    return false;
}