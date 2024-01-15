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

void printLinkedList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *findMiddle(Node *start)
{
    Node *fastPtr = start->next;
    Node *slowPtr = start;

    if (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    return slowPtr;
}

Node *mergeLinkedLists(Node *left, Node *right)
{
    Node *dummyNode = new Node(-1);
    // Created another node pointer so that we can traverse through list
    Node *temp = dummyNode;

    while (left != NULL && right != NULL)
    {

        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if (left)
    {
        temp->next = left;
    }
    else
    {
        temp->next = right;
    }

    return dummyNode->next;
}
// using merge sort technique to sort the linked list
Node *sortLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *left = head;
    Node *mid = findMiddle(head);
    Node *right = mid->next;
    mid->next = NULL;
    left = sortLinkedList(left);
    right = sortLinkedList(right);
    return mergeLinkedLists(left, right);
}

int main()
{
    Node *head = NULL;
    insertAtFront(head, 5);
    insertAtFront(head, 13);
    insertAtFront(head, 14);
    insertAtFront(head, 12);
    insertAtFront(head, 9);

    Node *newHead = sortLinkedList(head);

    printLinkedList(newHead);
    return 0;
}