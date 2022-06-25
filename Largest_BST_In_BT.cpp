#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL, right = NULL;
    }
};

struct Info
{
    int size, max, min, ans;
    bool isBST;
};

Info largestBSTinBT(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);
    Info current;
    current.size = (1 + leftInfo.size + rightInfo.size);
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        current.min = min(leftInfo.min, root->data);
        current.max = max(root->data, rightInfo.max);
        current.ans = current.size;
        current.isBST = true;
        return current;
    }
    current.ans = max(leftInfo.ans, rightInfo.ans);
    current.isBST = true;
    return current;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(8);
    root->right->left = new Node(6);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(7);
    root->right->right = new Node(9);
    cout << largestBSTinBT(root).ans << endl;
    return 0;
}