typedef long long ll;
#include <bits/stdc++.h>
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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
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

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *&head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteNode(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->data == val)
    {
        node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Node with value " << val << " not found." << endl;
        return;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 10);

    cout << "Original List: ";
    display(head);

    cout << "Searching for 3: " << (search(head, 3) ? "Found" : "Not Found") << endl;

    deleteNode(head, 3);

    cout << "After Deleting 3: ";
    display(head);

    deleteNode(head, 10);

    cout << "After Deleting 10 (Head Node): ";
    display(head);

    return 0;
}
