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

int calculateHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = calculateHeight(root->left);
    int rightheight = calculateHeight(root->right);
    return (max(leftheight, rightheight) + 1);
}

// Less Optimized Function To Calculate Diameter As Its Time Complexity = O(N2)
int calculateDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = calculateHeight(root->left);
    int rightheight = calculateHeight(root->right);
    int currentDiameter = leftheight + rightheight + 1;
    int leftdiameter = calculateDiameter(root->left);
    int rightdiameter = calculateDiameter(root->right);
    return max(leftdiameter, max(rightdiameter, currentDiameter));
}

// More Optimized Function To Calculate Diameter As Its Time Complexity = O(N)
int OCalculateDiameter(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int leftdiameter = OCalculateDiameter(root->left, &lh);
    int rightdiameter = OCalculateDiameter(root->right, &rh);
    int currentDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currentDiameter, max(rightdiameter, leftdiameter));
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
    cout << calculateHeight(root) << endl;
    int height = 0;
    cout << OCalculateDiameter(root, &height) << endl;
    return 0;
}