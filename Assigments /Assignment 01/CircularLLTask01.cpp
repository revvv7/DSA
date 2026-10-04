#include <iostream>
using namespace std;

// Node of Circular Linked List
struct Node
{
    int person;
    Node* next;
};

// Function to create a circular linked list
Node* createList(int n)
{
    Node* head = NULL;
    Node* last = NULL;

    // Create nodes for persons 1 to N
    for (int i = 1; i <= n; i++)
    {
        Node* newNode = new Node;

        newNode->person = i;
        newNode->next = NULL;

        // First node becomes the head
        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            // Add new node at the end
            last->next = newNode;
            last = newNode;
        }
    }

    // Make the linked list circular
    if (last != NULL)
    {
        last->next = head;
    }

    return head;
}


// Function to solve the Josephus Problem
int josephus(int n, int m)
{
    // Create circular linked list
    Node* head = createList(n);

    // Previous node is required for deletion
    Node* previous = NULL;
    Node* current = head;

    // Continue until only one person remains
    while (current->next != current)
    {
        // Move M-1 times
        // Mth person will be eliminated
        for (int count = 1; count < m; count++)
        {
            previous = current;
            current = current->next;
        }

        // Display the person who is eliminated
        cout << "Person " << current->person
             << " is eliminated." << endl;

        // Remove current node from the circular list
        previous->next = current->next;

        // Save the node that will be deleted
        Node* temp = current;

        // Move current to the next person
        current = current->next;

        // Delete eliminated node
        delete temp;
    }

    // The remaining node is the survivor
    int survivor = current->person;

    // Delete the last remaining node
    delete current;

    return survivor;
}


// Main Function
int main()
{
    int n, m;

    cout << "===== JOSEPHUS PROBLEM =====" << endl;

    // Input total number of persons
    cout << "Enter total number of persons (N): ";
    cin >> n;

    // Input number of persons to skip
    cout << "Enter M: ";
    cin >> m;

    // Validate input
    if (n <= 0 || m <= 0)
    {
        cout << "N and M must be greater than 0." << endl;
        return 0;
    }

    // Solve Josephus Problem
    int survivor = josephus(n, m);

    // Display final survivor
    cout << "\nThe surviving person is: "
         << survivor << endl;

    return 0;
}
