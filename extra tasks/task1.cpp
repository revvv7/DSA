#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Find duplicates without using sets
void findDuplicates(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        Node* temp = current->next;

        while (temp != NULL)
        {
            if (current->data == temp->data)
            {
                cout << "Duplicate value: " << current->data << endl;
                break;
            }

            temp = temp->next;
        }

        current = current->next;
    }
}

// Detect loop using slow and fast pointers
bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Create linked list
    Node* head = new Node{10, NULL};

    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{20, NULL};
    head->next->next->next->next = new Node{40, NULL};
    head->next->next->next->next->next = new Node{10, NULL};

    // Find duplicates
    findDuplicates(head);

    // Create a loop
    head->next->next->next->next->next->next =
        head->next->next;

    // Detect loop
    if (detectLoop(head))
    {
        cout << "Loop exists" << endl;
    }
    else
    {
        cout << "No loop" << endl;
    }

    return 0;
}
