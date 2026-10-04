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

void deleteValue(Node*& head, int value)
{
    // Remove matching nodes from the beginning
    while (head != NULL && head->data == value)
    {
        Node* temp = head;
        head = head->next;

        delete temp;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->next->data == value)
        {
            // Remove the matching node
            Node* temp = current->next;
            current->next = temp->next;

            delete temp;
        }
        else
        {
            current = current->next;
        }
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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(10);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(10);

    int value = 10;

    deleteValue(head, value);

    cout << "After deletion: ";
    display(head);

    return 0;
}
