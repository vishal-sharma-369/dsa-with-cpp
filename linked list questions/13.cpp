// Write a program to reverse a doubly linked list
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
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
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
    }
};

void reverseDoubleList(Node *&head)
{
    Node *temp = NULL;
    Node *prev = NULL;
    while (head)
    {
        temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        prev = head;
        head = temp;
    }
    head = prev;
}

int main()
{
    return 0;
}