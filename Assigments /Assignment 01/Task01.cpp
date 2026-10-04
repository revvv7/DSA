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

void displayReverse(Node* head)
{
    if (head == NULL)
        return;

    // First go to the end, then print while returning
    displayReverse(head->next);
    cout << head->data << " ";
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Reverse order: ";
    displayReverse(head);

    return 0;
}
