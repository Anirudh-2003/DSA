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

void printSubTree(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    printSubTree(root->left, k - 1);
    printSubTree(root->right, k - 1);
}

int nodeatdistanceK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubTree(root, k);
        return 0;
    }
    int dl = nodeatdistanceK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTree(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = nodeatdistanceK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTree(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
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
    nodeatdistanceK(root, root->left->right, 2);
    return 0;
}