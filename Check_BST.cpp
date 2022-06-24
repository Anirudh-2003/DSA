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

bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftvalid = isBST(root->left, min, root);
    bool rightvaild = isBST(root->right, root, max);
    return leftvalid and rightvaild;
}

int main()
{
    /*  BST Structure
                4
             /     \
            2        8
          /  \     /  \
        1     3   6    9
                /  \
               5    7
    */
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(8);
    root->right->left = new Node(6);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(7);
    root->right->right = new Node(9);
    cout << isBST(root, NULL, NULL);
    return 0;
}