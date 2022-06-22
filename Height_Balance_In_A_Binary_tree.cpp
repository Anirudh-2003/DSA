#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return (max(leftheight, rightheight) + 1);
}

// Less Optimized Function To Calculate Diameter As Its Time Complexity = O(N2)
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if (abs(leftheight - rightheight) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// More Optimized Function To Calculate Diameter As Its Time Complexity = O(N)
bool isBalancedO(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int leftheight = 0, rightheight = 0;
    if (isBalancedO(root->left, &leftheight) == false)
    {
        return false;
    }
    if (isBalancedO(root->right, &rightheight) == false)
    {
        return false;
    }
    *height = max(leftheight, rightheight) + 1;
    if (abs(leftheight - rightheight) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout << isBalancedO(root,&height);
    return 0;
}