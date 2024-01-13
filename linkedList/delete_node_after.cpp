#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtFront(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void deleteNodeAfter(Node *&head, int target)
{
    if (head == NULL)
    {
        return;
    }
    Node *ptr = head;
    Node *prePtr = ptr;
    while (prePtr->data != target)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }

    prePtr->next = ptr->next;
    delete ptr;
}

void printLinkedList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = NULL;
    // sample linked list creation
    for (int i = 1; i <= 6; i++)
    {
        insertAtFront(head, i * 4);
    }

    cout << "Linked list before deletion" << endl;
    printLinkedList(head);

    deleteNodeAfter(head, 12);
    cout << "Linked list after deletion" << endl;
    printLinkedList(head);

    return 0;
}