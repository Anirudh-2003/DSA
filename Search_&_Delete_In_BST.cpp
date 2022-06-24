#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val, left = NULL, right = NULL;
    }
};

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        searchInBST(root->right, key);
    }
    searchInBST(root->right, key);
}

int main()
{
    /*  BST Structure
                4
             /     \
            2        8
          /  \     /  \
        1     3   5    9
                /  \
               4    6
    */
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(8);
    root->right->left = new Node(5);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);
    root->right->right = new Node(9);
    if (searchInBST(root, 6) == NULL)
    {
        cout << "Key Doesn't exist" << endl;
    }
    else
    {
        cout << "Key Exist" << endl;
    }
    return 0;
}