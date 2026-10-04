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

void pairSwap(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* previous = NULL;
    Node* current = head;

    // The second node will become the new head
    head = head->next;

    while (current != NULL && current->next != NULL)
    {
        Node* second = current->next;
        Node* nextPair = second->next;

        // Swap the two nodes by changing links
        second->next = current;

        if (previous != NULL)
            previous->next = second;

        current->next = nextPair;

        previous = current;
        current = nextPair;
    }
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    pairSwap(head);

    display(head);

    return 0;
}
