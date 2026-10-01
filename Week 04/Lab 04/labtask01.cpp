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

void deleteEven(Node*& head)
{
    if (head == NULL)
        return;

    Node* current = head;
    Node* previous = NULL;

    do
    {
        Node* nextNode = current->next;

        if (current->data % 2 == 0)
        {
            if (current == head)
            {
                Node* last = head;
                while (last->next != head)
                    last = last->next;

                if (head->next == head)
                {
                    delete head;
                    head = NULL;
                    return;
                }

                head = head->next;
                last->next = head;
                delete current;
                current = head;
                continue;
            }
            else
            {
                previous->next = nextNode;
                delete current;
            }
        }
        else
        {
            previous = current;
        }

        current = nextNode;

    } while (current != head);
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
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);

    cout << "Before deletion: ";
    display(head);

    deleteEven(head);

    cout << "\nAfter deleting even values: ";
    display(head);

    return 0;
}
