#include <iostream>
#include <stack>
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

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
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
    zigzagTraversal(root);
    return 0;
}