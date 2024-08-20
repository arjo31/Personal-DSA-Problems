#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode()
    {
        this->val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

// //Ceil in a BST (Any value >= key)
// int findCeil(TreeNode* root, int key)
// {
//     int ceil = -1;
//     while(root)
//     {
//         if (root->val==key)
//         {
//             ceil = root->val;
//             return ceil;
//         }
//         if (key > root->val)
//         {
//             root = root->right;
//         }
//         else
//         {
//             ceil = root->val;
//             root = root->left;
//         }
//     }
//     return ceil;
// }

// //Floor in a BST (Any value<=key)
// int findFloor(TreeNode* root, int key)
// {
//     int floor = -1;
//     while (root)
//     {
//         if (root->val==key)
//         {
//             floor = root->val;
//             return floor;
//         }
//         if (key > root->val)
//         {
//             floor = root->val;
//             root = root->right;
//         }
//         else
//         {
//             root = root->left;
//         }
//     }
//     return floor;
// }

// //Kth smallest/largest element in binary tree
// void inorderTraversal(TreeNode* root, int k, int &count, int&ans)
// {
//     if (root==nullptr) return;
//     inorderTraversal(root->left,k,count,ans);
//     count++;
//     if (count==k) ans = root->val;
//     inorderTraversal(root->right, k,count,ans);
// }
// int kthSmallest(TreeNode* root, int k)
// {
//     int ans = 0,count = 0;
//     inorderTraversal(root,k,count,ans);
//     return ans;
// }


// //Construct BST from preorder traversal
// TreeNode* build(vector<int>&preOrder, int &i, int bound)
// {
//     if (i==preOrder.size() || preOrder[i] > bound) return NULL;
//     TreeNode* root = new TreeNode(preOrder[i++]);
//     root->left = build(preOrder,i,root->val);
//     root->right = build(preOrder,i,bound);
//     return root;
// }
// TreeNode* createBSTFromPreOrder(vector<int>&preOrder)
// {
//     int i = 0;
//     return build(preOrder,i,INT_MAX);
// }

// //Inorder successor/ predecessor in BST
// pair<TreeNode*,TreeNode*> inorderSuccessorPredecessor(TreeNode* root, TreeNode* p)
// {
//     TreeNode* successor = NULL;
//     TreeNode* predecessor = NULL;
//     TreeNode* dummy = root;
//     while (root)
//     {
//         if (p->val >= root->val)
//         {
//             root = root->right;
//         }
//         else
//         {
//             successor = root;
//             root = root->left;
//         }
//     }
//     root = dummy;
//     while (root)
//     {
//         if (p->val <= root->val)
//         {
//             root = root->left;
//         }
//         else
//         {
//             predecessor = root;
//             root = root->right;
//         }
//     }
//     return make_pair(successor,predecessor);
// }

// //Implement a BST Iterator
// class BSTIterator
// {
//     private:
//         stack<TreeNode*> myStack;

//         void pushAll(TreeNode* node)
//         {
//             for (; node!=NULL; myStack.push(node), node = node->left);
//         }

//     public:
//         BSTIterator(TreeNode* root)
//         {
//             pushAll(root);
//         }

//         bool hasNext()
//         {
//             return !myStack.empty();
//         }

//         int next()
//         {
//             TreeNode* tmpNode = myStack.top();
//             myStack.pop();
//             pushAll(tmpNode->right);
//             return tmpNode->val;
//         }
// };

// //Two Sum in BST
// bool findTarget(TreeNode* root, int k)
// {
//     return dfs(root, root,  k);
// }

// bool dfs(TreeNode* root,  TreeNode* cur, int k)
// {
//     if(cur == NULL)return false;
//     return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
// }

// bool search(TreeNode* root, TreeNode *cur, int value)
// {
//     if(root == NULL)return false;
//     return (root->val == value) && (root != cur)
//         || (root->val < value) && search(root->right, cur, value)
//             || (root->val > value) && search(root->left, cur, value);
// }