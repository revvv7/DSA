#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void reverseList(Node*& head)
{
    Node* previous = NULL;
    Node* current = head;
    Node* nextNode;

    while (current != NULL)
    {
        nextNode = current->next;

        // Change the direction of the link
        current->next = previous;

        previous = current;
        current = nextNode;
    }

    head = previous;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before reversing: ";
    display(head);

    reverseList(head);

    cout << "\nAfter reversing: ";
    display(head);

    return 0;
}
