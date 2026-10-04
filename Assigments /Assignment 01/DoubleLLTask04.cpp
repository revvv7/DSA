#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* previous;

    Node(int value)
    {
        data = value;
        next = NULL;
        previous = NULL;
    }
};

// Create the required special arrangement
void specialPattern(Node* head)
{
    Node* left = head->next;
    Node* right = head;

    // Move right pointer to the last node
    while (right->next != NULL)
        right = right->next;

    // Keep the last node fixed
    right = right->previous;

    while (left != right && left->previous != right)
    {
        // Swap the values from both sides
        int temp = left->data;
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
    // Create the nodes
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);

    // Connect nodes in both directions
    head->next = n2;
    n2->previous = head;

    n2->next = n3;
    n3->previous = n2;

    n3->next = n4;
    n4->previous = n3;

    n4->next = n5;
    n5->previous = n4;

    n5->next = n6;
    n6->previous = n5;

    n6->next = n7;
    n7->previous = n6;

    n7->next = n8;
    n8->previous = n7;

    n8->next = n9;
    n9->previous = n8;

    // Apply the required arrangement
    specialPattern(head);

    display(head);

    return 0;
}
