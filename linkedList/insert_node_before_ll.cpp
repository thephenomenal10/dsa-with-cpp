#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtFront(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertNodeBefore(Node *&head, int target, int data)
{
    Node *newNode = new Node(data);
    Node *ptr = head;
    Node *prePtr = ptr;
    while (ptr->data != target)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
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
    insertAtFront(head, 2);
    insertAtFront(head, 44);
    insertAtFront(head, 3);
    insertAtFront(head, 8);
    insertAtFront(head, 12);

    cout << "LL before insertion" << endl;
    printLinkedList(head);

    insertNodeBefore(head, 3, 66);

    cout << "LL after insertion" << endl;
    printLinkedList(head);

    return 0;
}