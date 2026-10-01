#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void deleteEvenPosition(Node*& head)
{
    if (head == NULL || head->next == head)
        return;

    Node* current = head;

    while (current->next != head)
    {
        Node* deleteNode = current->next;

        current->next = deleteNode->next;
        delete deleteNode;

        if (current->next == head)
            break;

        current = current->next;
    }
}

void display(Node* head)
{
    if (head == NULL)
        return;

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    insert(head, 60);

    cout << "Before deletion: ";
    display(head);

    deleteEvenPosition(head);

    cout << "\nAfter deleting even positions: ";
    display(head);

    return 0;
}
