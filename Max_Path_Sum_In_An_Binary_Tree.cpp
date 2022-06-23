#include <iostream>
#include <climits>
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

int MaxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = MaxPathSumUtil(root->left, ans);
    int right = MaxPathSumUtil(root->right, ans);
    int nodemax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodemax);
    int singlepath = max(root->data, max(root->data + left, root->data + right));
    return singlepath;
}

int MaxPathSum(Node *root)
{
    int ans = INT_MIN;
    MaxPathSumUtil(root, ans);
    return ans;
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
    cout << MaxPathSum(root);
    return 0;
}