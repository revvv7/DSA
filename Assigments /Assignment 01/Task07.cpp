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

Node* reverseList(Node* head)
{
    Node* previous = NULL;
    Node* current = head;

    while (current != NULL)
    {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

void reverseHalves(Node*& head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* firstHalf = head;
    Node* secondHalf = slow;

    // Find the last node of the first half
    Node* temp = firstHalf;

    while (temp->next != secondHalf)
        temp = temp->next;

    temp->next = NULL;

    firstHalf = reverseList(firstHalf);
    secondHalf = reverseList(secondHalf);

    head = firstHalf;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = secondHalf;
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
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    reverseHalves(head);

    display(head);

    return 0;
}
