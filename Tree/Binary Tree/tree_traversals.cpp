#include "binary_tree.h"

void postOrderTraversalRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrderTraversalRecursive(root->left);
    postOrderTraversalRecursive(root->right);
    cout << root->data << " ";
}

void preOrderTraversalRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrderTraversalRecursive(root->left);
    preOrderTraversalRecursive(root->right);
}

void inOrderTraversalRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrderTraversalRecursive(root->left);
    cout << root->data << " ";
    inOrderTraversalRecursive(root->right);
}

// Iterative
void preOrderTraversalIterative(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *t = st.top();
        cout << t->data << " ";
        st.pop();
        if (t->right)
        {
            st.push(t->right);
        }
        if (t->left)
        {
            st.push(t->left);
        }
    }
}

void inOrderTraversalIterative(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top();
            cout << curr->data << " ";
            st.pop();
            curr = curr->right;
        }
    }
}

void PostOrderTraversalIterative1(TreeNode *root) // Using two stacks
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left)
        {
            s1.push(curr->left);
        }
        if (curr->right)
        {
            s1.push(curr->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void PostOrderTraversalIterative2(TreeNode *root) // using one stack
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (curr != nullptr || !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
}