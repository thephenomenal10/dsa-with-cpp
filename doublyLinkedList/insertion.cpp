#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data1)
    {
        prev = NULL;
        data = data1;
        next = NULL;
    }
};

void insertAtBeg(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *ptr = head;
    ptr->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
}

void printLinkedList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    insertAtBeg(head, 32);
    insertAtBeg(head, 4);
    insertAtBeg(head, 31);
    insertAtBeg(head, 62);
    insertAtBeg(head, 42);
    cout << "Linked list after adding data from beg" << endl;
    printLinkedList(head);

    insertAtEnd(head1, 32);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 31);
    insertAtEnd(head1, 62);
    insertAtEnd(head1, 42);
    cout << endl
         << "Linked list after adding data from end" << endl;
    printLinkedList(head1);
    return 0;
}