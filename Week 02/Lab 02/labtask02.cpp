#include <iostream>
using namespace std;
struct NodeT{
    int data;
    NodeT *next;
};
NodeT *insert(NodeT *last, int x)
{
    NodeT *p = new NodeT;
    p->data = x;
    p->next = NULL;
    if(last != NULL)
        last->next = p;
    return p;
}
void display(NodeT *p)
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){
    NodeT *a = NULL, *b = NULL, *c = NULL;
    NodeT *last = NULL;
    a = insert(NULL, 12);
    last = a;
    last = insert(last, 5);
    last = insert(last, 21);

    b = insert(NULL, 8);
    last = b;
    last = insert(last, 17);
    last = insert(last, 3);
    NodeT *p = a;
    while(p != NULL)
    {
        if(c == NULL)
        {
            c = insert(NULL, p->data);
            last = c;
        }
        else
            last = insert(last, p->data);
        p = p->next;
    }
    p = b;
    while(p != NULL)
    {
        last = insert(last, p->data);
        p = p->next;
    }
    cout << "First list: ";
    display(a);
    cout << "\nSecond list: ";
    display(b);
    cout << "\nMerged list: ";
    display(c);
    return 0;}
