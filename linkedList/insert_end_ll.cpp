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

void insertNodeAtLast(Node *&head, int data)
{
    Node *newNode = new Node(data);

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
    insertNodeAtLast(head, 23);
    insertNodeAtLast(head, 33);
    insertNodeAtLast(head, 43);
    insertNodeAtLast(head, 3);
    insertNodeAtLast(head, 6);
    printLinkedList(head);
    return 0;
}