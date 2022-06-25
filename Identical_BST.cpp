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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool condition1 = (root1->data == root2->data);
        bool condition2 = isIdentical(root1->left, root2->left);
        bool condition3 = isIdentical(root1->right, root2->right);
        if (condition1 && condition2 && condition3)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->left->right = new Node(3);
    root2->left->left = new Node(1);
    root2->right = new Node(8);
    root2->right->left = new Node(6);
    root2->right->left->left = new Node(5);
    root2->right->left->right = new Node(7);
    root2->right->right = new Node(9);
    if (isIdentical(root1, root2))
    {
        cout << "BST's Are Identical" << endl;
    }
    else
    {
        cout << "BST's Are Not Identical" << endl;
    }
    return 0;
}