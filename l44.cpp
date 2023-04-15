// Starting with linked lists

/*
Linked list is a type of data structure
it stores the data in the form of nodes
a node consist of data and the address for another node

Why do we need a linked list?
Arrays can be used but their size can't be changed at run time
vector can be used as it can double its size as per requirement but it creates a new array then copies the entire data to the new array so it not an optimal solution
there is no need to shift elements while insertion or deletion in case of linked lists
we don't need continuous memory in case of linked lists i.e. the data can be stored anywhere


Types of Linked Lists:
singly linked lists
doubly linked lists
circular linked lists
circular doubly linked lists
*/




/*
// Implementation
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next)
        {
            delete this->next;
        }
        this->next = NULL;
        cout<<"delete node with value "<<value<<endl;
    }
};

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    cout << node1->data << endl;
    cout << node1->next << endl;
}

// what are singly linked lists
// the lists whose node contains single data and a single pointer which stores the address of the next node is called singly linked lists

// Write a function to insert a node at head
void insertAtHead(int data, Node *&head)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// write a function to traverse and print all the elements of a linked list
void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printer(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// write a function to insert at tail
void insertAtTail(Node *&head, int data)
{
    if (!head)
    {
        insertAtHead(data, head);
        return;
    }
    Node *temp = new Node(data);
    Node *i = head;
    while (i->next)
    {
        i = i->next;
    }
    i->next = temp;
}

void insertAtTailUsingTail(Node *&tail, int data)
{
    if (!tail)
    {
        insertAtHead(data, tail);
        return;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

// write a program to insert in middle
void insertInMiddle(Node *&head,Node*&tail, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(data, head);
        return;
    }
    else
    {
        Node *i = new Node(data);
        Node *temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            if (temp->next)
                temp = temp->next;
        }
        if(temp->next==NULL)insertAtTail(tail,data);
        i->next = temp->next;
        temp->next = i;
    }
}


// write a program to delete a node from linked list
void deleteAtPosition(Node*&head,int position)
{
    if(position == 1)
    {
        Node*temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node*prev = NULL;
        Node*curr = head;
        for(int i = 0;i<position-1;i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
*/





// ------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------
// doubly linked lists:
/*
the type of list which consist of data and two pointers 
one pointing to the next and the other pointing to the previous data member
*/





/*
#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next)
        {
            delete this->next;
            this->next = NULL;
        }
        if(this->prev)
        {
            delete this->prev;
            this->prev = NULL;
        }
        cout<<"Delete node with value "<<value<<endl;
    }
};

void print(Node*head)
{
    Node*temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node*head)
{
    int length = 0;
    while(head)
    {
        length++;
        head = head->next;
    }
    return length;
}

void insertAtHead(Node*&head,Node*&tail,int data)
{
    if(head==NULL)
    {
        head = new Node(data);
        tail = head;
        return;
    }
    Node*temp = new  Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node*&head,Node*&tail,int data)
{
    if(tail==NULL)
    {
        tail = new Node(data);
        head = tail;
        return;
    }
    Node*temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node*&head,Node*&tail,int data,int position)
{
    if(position == 1)
    {
        insertAtHead(head,tail,data);
        return;
    }
    else
    {
        Node*x = head;
        for(int i = 0;i<position-2;i++)
        {
            x = x->next;
        }
        if(x->next == NULL)
        {
            insertAtTail(head,tail,data);
            return;
        }
        Node*temp = new Node(data);
        temp->next = x->next;
        temp->prev = x;
        x->next->prev = temp;
        x->next = temp;
    }
}

void deleteNode(Node*&head,Node*&tail,int position)
{
    if(position==1)
    {
        Node*temp = head;
        head->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node*curr = head;
        Node*prev = NULL;
        for(int i = 0;i<position-1;i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr->next==NULL)
        {
            prev->next = NULL;
            curr->prev = NULL;
            tail = prev;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }
}

int main()
{
    Node*head = new Node(10);
    Node*tail = head;

    return 0;
}
*/














// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// Circular Linked List:

/*
circular linkedlist is a single linked list except that the last node instead of pointing to null points to the first node
*/



#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data = data;
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

int main()
{
    return 0;
}





// Circular linked list portion is remaining okey vishal sharma