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

void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *ptr = head;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
        return;
    }

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
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

    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    insertAtEnd(head, 2);
    insertAtEnd(head, 54);
    insertAtEnd(head, 23);
    printLinkedList(head);
    return 0;
}