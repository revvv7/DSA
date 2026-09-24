#include <iostream>
using namespace std;
struct NodeT{
    int data;
    NodeT *next;
};
NodeT *first = NULL, *last = NULL;
void insert(int x)
{
    NodeT *p = new NodeT;
    p->data = x;
    p->next = NULL;
    if(first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        last = p;
    }
}
void reverse(NodeT *p)
{
    if(p == NULL)
        return;
    reverse(p->next);
    cout << p->data << " ";
}
int main()
{
    insert(14);
    insert(27);
    insert(6);
    insert(19);
    insert(33);
    cout << "List: ";
    NodeT *p = first;
   while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\nReverse: ";
    reverse(first);
    return 0;
}
