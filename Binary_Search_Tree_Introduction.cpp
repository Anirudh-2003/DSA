#include <iostream>
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

Node *inserBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = inserBST(root->left, val);
    }
    else
    {
        root->right = inserBST(root->right, val);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    root = inserBST(root, 3);
    inserBST(root, 1);
    inserBST(root, 2);
    inserBST(root, 7);
    inserBST(root, 6);
    inserBST(root, 4);
    inserBST(root, 5);
    inserBST(root, 8);
    inserBST(root, 9);
    inOrder(root);
    return 0;
}
