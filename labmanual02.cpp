
//GRADED LAB TASK 01
// Code 01:
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

// GRADED LAB TASK 02
// Code 02:
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


//GRADED LAB TASK 02
//Code 03:
#include <iostream>
using namespace std;
struct NodeT{
    int data;
    NodeT *next;
};
NodeT *first = NULL, *last = NULL;
void insert(int x){
    NodeT *p = new NodeT;
    p->data = x;
    p->next = NULL;
if(first == NULL)
        first = last = p;
    else
    {last->next = p;
        last = p;}}
int main(){
    insert(7);
    insert(12);
    insert(7);
    insert(25);
    insert(7);
    insert(18);
    int x = 7;
    int count = 0;
    NodeT *p = first;
    cout << "List: ";
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    p = first;
    while(p != NULL)
    {
        if(p->data == x)
            count++;
        p = p->next;
    }
    cout << "\n" << x << " occurs " << count << " times.";
    return 0;}
