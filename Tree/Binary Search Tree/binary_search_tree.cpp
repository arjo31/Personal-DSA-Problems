#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode()
    {
        this->data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int data, TreeNode* left, TreeNode* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

//Search in a BST
TreeNode* searchBST(TreeNode*  root, int val)
{
    while (root && root->data!=val)
    {
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

//Ceil in a BST (Any value >= key)
int findCeil(TreeNode* root, int key)
{
    int ceil = -1;
    while(root)
    {
        if (root->data==key)
        {
            ceil = root->data;
            return ceil;
        }
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

//Floor in a BST (Any value<=key)
int findFloor(TreeNode* root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->data==key)
        {
            floor = root->data;
            return floor;
        }
        if (key > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

//Insert a given node in a BST
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    TreeNode* newNode = new TreeNode(val);
    TreeNode* curr = root;
    TreeNode* parent;
    if (root==NULL) return newNode;
    while (curr)
    {
        if (val > curr->data)
        {
            parent = curr;
            curr = curr->right;
        }
        else if (val < curr->data)
        {
            parent = curr;
            curr = curr->left;
        }
    }
    if (parent->data > val) parent->left = newNode;
    else parent->right = newNode;
    return root;
}

//Delete a node in a BST
TreeNode* findLastRight(TreeNode* root)
{
    if (root->right==nullptr) return root;
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root)
{
    if (root->left==NULL) return root->right;
    else if (root->right==nullptr) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if (root==NULL) return root;
    if (root->data==key) return helper(root);
    TreeNode* dummy = root;
    while (root)
    {
        if (root->data > key)
        {
            if (root->left && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}

//Kth smallest/largest element in binary tree
void inorderTraversal(TreeNode* root, int k, int &count, int&ans)
{
    if (root==nullptr) return;
    inorderTraversal(root->left,k,count,ans);
    count++;
    if (count==k) ans = root->data;
    inorderTraversal(root->right, k,count,ans);
}
int kthSmallest(TreeNode* root, int k)
{
    int ans = 0,count = 0;
    inorderTraversal(root,k,count,ans);
    return ans;
}

//Check if tree is BST or BT
bool isValidBST(TreeNode* root, long minVal, long maxVal)
{
    if (root==nullptr) return true;
    if (root->data >= maxVal || root->data <= minVal) return false;
    return (isValidBST(root->left, minVal,root->data) && isValidBST(root->right,root->data,maxVal));

}
bool isBST(TreeNode* root)
{
    return isValidBST(root,LONG_MIN, LONG_MAX);
}

//LCA of two nodes
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) //Iterative
{
    if (root==nullptr) return root;
    TreeNode* curr = root;
    
    while (curr)
    {
        int currVal = curr->data;
        if (p->data < currVal && q->data < currVal) //Go left subtree
        {
            curr = curr->left;
        }
        else if (p->data > currVal && q->data > currVal) //Go right subtree
        {
            curr = curr->right;
        }
        else 
        {
            break;
        }
    }
    return curr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) //Recursive
{
    if (root==nullptr) return root;
    int curr = root->data;
    if (curr < p->data && curr < q->data)
    {
        return lowestCommonAncestor(root->right,p,q);
    }
    if (curr > p->data && curr > q->data)
    {
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
}

//Construct BST from preorder traversal
TreeNode* build(vector<int>&preOrder, int &i, int bound)
{
    if (i==preOrder.size() || preOrder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preOrder[i++]);
    root->left = build(preOrder,i,root->data);
    root->right = build(preOrder,i,bound);
    return root;
}
TreeNode* createBSTFromPreOrder(vector<int>&preOrder)
{
    int i = 0;
    return build(preOrder,i,INT_MAX);
}

//Inorder successor/ predecessor in BST
pair<TreeNode*,TreeNode*> inorderSuccessorPredecessor(TreeNode* root, TreeNode* p)
{
    TreeNode* successor = NULL;
    TreeNode* predecessor = NULL;
    TreeNode* dummy = root;
    while (root)
    {
        if (p->data >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    root = dummy;
    while (root)
    {
        if (p->data <= root->data)
        {
            root = root->left;
        }
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return make_pair(successor,predecessor);
}

//Implement a BST Iterator
class BSTIterator
{
    private:
        stack<TreeNode*> myStack;

        void pushAll(TreeNode* node)
        {
            for (; node!=NULL; myStack.push(node), node = node->left);
        }

    public:
        BSTIterator(TreeNode* root)
        {
            pushAll(root);
        }

        bool hasNext()
        {
            return !myStack.empty();
        }

        int next()
        {
            TreeNode* tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->data;
        }
};

//Two Sum in BST 
bool findTarget(TreeNode* root, int k)
{
    return dfs(root, root,  k);
}

bool dfs(TreeNode* root,  TreeNode* cur, int k)
{
    if(cur == NULL)return false;
    return search(root, cur, k - cur->data) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
}

bool search(TreeNode* root, TreeNode *cur, int value)
{
    if(root == NULL)return false;
    return (root->data == value) && (root != cur) 
        || (root->data < value) && search(root->right, cur, value) 
            || (root->data > value) && search(root->left, cur, value);
}