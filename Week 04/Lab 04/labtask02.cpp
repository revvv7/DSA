#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

int josephus(Node* head, int k)
{
    Node* current = head;
    Node* previous = NULL;

    while (current->next != current)
    {
        for (int i = 1; i < k; i++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        delete current;
        current = previous->next;
    }

    int answer = current->data;
    delete current;

    return answer;
}

int main()
{
    Node* head = NULL;
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter counting number: ";
    cin >> k;

    for (int i = 1; i <= n; i++)
        insert(head, i);

    cout << "Survivor is: " << josephus(head, k);

    return 0;
}
