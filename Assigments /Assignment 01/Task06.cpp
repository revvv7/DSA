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

void separateEvenOdd(Node* head)
{
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* current = head;

    while (current != NULL)
    {
        Node* nextNode = current->next;
        current->next = NULL;

        if (current->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = current;
                evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = current;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = current;
                oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = nextNode;
    }

    cout << "Even list: ";
    current = evenHead;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\nOdd list: ";
    current = oddHead;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head->next->next->next->next = new Node(30);

    separateEvenOdd(head);

    return 0;
}
