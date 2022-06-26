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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node *root, Node **first, Node **mid, Node **end, Node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calcPointers(root->left, first, mid, end, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *end = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, mid, end, prev);
}

void restoreBST(Node *root)
{
    Node *first = NULL, *mid = NULL, *end = NULL, *prev = NULL;
    calcPointers(root, &first, &mid, &end, &prev);
    if (first && end)
    {
        swap(&(first->data), &(end->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
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
    Node *root = new Node(4);
    root->left = new Node(9);
    root->left->right = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(8);
    root->right->left = new Node(6);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(7);
    root->right->right = new Node(2);
    inOrder(root);
    cout << endl;
    restoreBST(root);
    inOrder(root);
    cout << endl;
    return 0;
}