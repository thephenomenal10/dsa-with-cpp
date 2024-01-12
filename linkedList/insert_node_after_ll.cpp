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

void insertNodeAfter(Node *&head, int target, int value)
{
    Node *newNode = new Node(value);
    Node *ptr = head;
    while (ptr->data != target)
    {
        cout << "print ";
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
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
    // Insert node after value of 3
    insertNodeAfter(head, 3, 88);

    cout << "LL after insertion" << endl;
    printLinkedList(head);

    return 0;
}