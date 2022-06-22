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

int findDistance(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }
    int left = findDistance(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findDistance(root->right, k, dist + 1);
}

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);
    if (leftLCA && rightLCA)
    {
        return root;
    }
    if (leftLCA == NULL && rightLCA == NULL)
    {
        return NULL;
    }
    if (leftLCA != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int DistanceBtwNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);
    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);
    return d1 + d2;
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
    cout << DistanceBtwNodes(root, 5, 6);
    return 0;
}