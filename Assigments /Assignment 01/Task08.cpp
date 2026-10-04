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

void removeDuplicates(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        Node* previous = current;
        Node* temp = current->next;

        while (temp != NULL)
        {
            if (temp->data == current->data)
            {
                previous->next = temp->next;
                delete temp;
                temp = previous->next;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        current = current->next;
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
    Node* head = new Node(5);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(8);

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    display(head);

    return 0;
}
