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

// Tortoise- hare algo to find out the middle node of linked list
void printMiddle(Node *head)
{
    Node *ptr = head->next;
    Node *preptr = head;

    while (ptr != NULL && ptr->next != NULL)
    {
        ptr = ptr->next->next;
        preptr = preptr->next;
    }

    cout << "Middle Node" << preptr->data;
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
    insertAtFront(head, 5);
    insertAtFront(head, 14);
    insertAtFront(head, 13);
    insertAtFront(head, 12);
    insertAtFront(head, 9);
    insertAtFront(head, 33);
    insertAtFront(head, 13);
    // insertAtFront(head, 54);
    printLinkedList(head);
    printMiddle(head);
    return 0;
}