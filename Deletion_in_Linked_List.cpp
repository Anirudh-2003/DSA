#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void InsertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletetation(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteathead(head);
        return;
    }
    node *n = head;
    while (n->next->data != val)
    {
        n = n->next;
    }
    node *todelete = n->next;
    n->next = n->next->next;
    delete todelete;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtHead(head, 4);
    display(head);
    // cout << search(head, 4) << endl;
    deletetation(head, 3);
    deleteathead(head);
    display(head);
    return 0;
}