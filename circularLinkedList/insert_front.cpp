#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

void insertAtFront(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *ptr = head;
    if (ptr == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    newNode->next = head;
    ptr->next = newNode;
    head = newNode;
}

void printLinkedList(Node *head)
{
    Node *ptr = head;
    while (ptr->next != head)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << ptr->data << " ";
}

int main()
{
    Node *head = NULL;

    insertAtFront(head, 12);
    insertAtFront(head, 14);
    insertAtFront(head, 2);
    insertAtFront(head, 54);
    insertAtFront(head, 23);
    printLinkedList(head);

    return 0;
}