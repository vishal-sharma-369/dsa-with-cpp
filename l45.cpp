// Questions on linked  lists

// Reversing a linked list
// Iterative approach
/*
#include<iostream>

using namespace std;


// implementing the node structure
class Node
{
    public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data= data;
        next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next)
        {
            delete this->next;
            this->next = NULL;
        }
        cout<<"Deleted node with value "<<value<<endl;
    }
};


// Reversing a linked list using iteration
void reverse(Node*&head)
{
    if(!head)return;
    if(head->next==NULL)return;
    else
    {
        Node*prev = NULL;
        Node*curr = head;
        Node*next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
}


// Reversing a linked list using two pointers approach
void reverseUsingRecursion(Node*&head,Node*prev,Node*curr)
{
    if(curr==NULL)
    {
        head = prev;
        return;
    }
    else
    {
        Node*fwd =   curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        return reverseUsingRecursion(head,prev,curr);
    }
}


// Reversing a linked list using a single head pointer
Node*reverse1(Node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    else
    {
        Node*chotaHead = reverse1(head->next);
        head->next->next = head;
        head->next = NULL;
        return chotaHead;
    }
}

int main()
{
    return 0;
}
*/

// Doing the Homework i.e. reversing a doubly linked list

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next)
        {
            delete this->next;
            this->next = NULL;
        }
        if (this->prev)
        {
            delete this->prev;
            this->prev = NULL;
        }
        cout << "Deleted node with value " << value << endl;
    }
};

void reverse(Node *&head)
{
    Node *temp;
    Node *x = head;
    Node *t;
    while (x)
    {
        temp = x->next;
        t = x->prev;
        x->prev = x->next;
        x->next = t;
        x = temp;
    }
    head = t->prev;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
}

int getLength(Node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

int findMiddleElement(Node *head)
{
    int length = getLength(head);
    int position = length / 2 + 1;
    for (int i = 0; i < position - 1; i++)
    {
        head = head->next;
    }
    return head->data;
}

// find the middle element of linked list
int findMiddle(Node *head)
{
    if (head == NULL)
        return -1;
    Node *fast = head;
    Node *slow = head;
    while (fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}