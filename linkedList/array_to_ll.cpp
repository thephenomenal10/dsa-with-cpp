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

void insertNewNode(Node *&head, int data)
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

Node *convertArrayToList(int arr[], int size)
{
    Node *head = NULL;

    for (int i = 0; i < size; i++)
    {
        insertNewNode(head, arr[i]);
    }
    return head;
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
    int arr[7] = {32, 12, 32, 43, 32, 5, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrayToList(arr, arrSize);
    printLinkedList(head);
    return 0;
}