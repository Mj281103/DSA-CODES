#include <iostream>

using namespace std;

/*
1.Create
2.Display
3.Length
4.Inserting
5.
*/

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct node *temp, *last;

    first = new node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first; // most recent node

    for (int i = 1; i < n; i++)
    {
        temp = new node;         // creating node
        temp->data = A[i];       // adding data tp node
        temp->next = last->next; // pointing to next
        temp->prev = last;       // back link
        last->next = temp;       // last nodes next is temp
        last = temp;             // making last = new node
    }
}

void Display(struct node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(struct node *p)
{
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

void Insert(struct node *p, int index, int x)
{
    struct node *t;
    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = new node;
        t->data = x;     // adding data to newnode
        t->prev = NULL;  // new node's prev null
        t->next = first; // new node's next is old first
        if (first)
            first->prev = t; // old first's previous is newnode
        first = t;           // newnode is first now
        return;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t = new node;
        t->data = x;
        t->prev = p;       // newnodes prev is p
        t->next = p->next; // new nodes next is p's next (q)
        if (p->next)
            p->next->prev = t;
        // if p->next is not null
        // i.e q's prev will be t
        p->next = t;
    }
}

int Delete(struct node *p, int index)
{
    int x = -1, i;
    if (index < 1 || index > Length(p))
        return -1;
    if (index == 1)
    {
        first = first->next; // move first to next noce
        if (first)
            first->prev = NULL; // if still first make prev as NULL
        x = p->data;
        delete p;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        // previous of p will now point to next of p, i.e p is removed
        if (p->next)
            p->next->prev = p->prev;
        // p->next's previous will point to p->prev
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    cout << "1.Create \n2.Insert\n3.Delete\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Length: " << Length(first) << endl;
        Display(first);
        break;
    case 2:
        cout << "Inserting" << endl;
        Insert(first, 2, 25);
        Display(first);
        break;
    case 3:
        cout << "Deleting" << endl;
        cout << "Element Removed: " << Delete(first, 5) << endl;
        Display(first);
        break;
    }
    return 0;
}
