#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
    Node* previous;

    Node(string value)
    {
        data = value;
        next = NULL;
        previous = NULL;
    }
};

void swapFromBothEnds(Node* head)
{
    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && left->previous != right)
    {
        // Swap the data of both end nodes
        string temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->previous;
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
    Node* head = new Node("Alice");
    Node* second = new Node("Bob");
    Node* third = new Node("Charlie");
    Node* fourth = new Node("Dana");
    Node* fifth = new Node("Eva");
    Node* sixth = new Node("Frank");

    head->next = second;
    second->previous = head;

    second->next = third;
    third->previous = second;

    third->next = fourth;
    fourth->previous = third;

    fourth->next = fifth;
    fifth->previous = fourth;

    fifth->next = sixth;
    sixth->previous = fifth;

    swapFromBothEnds(head);

    display(head);

    return 0;
}
