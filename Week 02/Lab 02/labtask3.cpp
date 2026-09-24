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
