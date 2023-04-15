// Question is to find the intersection of two sorted linked lists
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
        if (this->next)
        {
            delete this->next;
            this->next = NULL;
        }
    }
};

Node *intersection(Node *first, Node *second)
{
    Node *ans = new Node(-1);
    Node *tail = ans;
    while (first && second)
    {
        if (first->data < second->data)
        {
            first = first->next;
        }
        else if (second->data < first->data)
        {
            second = second->next;
        }
        else
        {
            Node *newNode = new Node(first->data);
            tail->next = newNode;
            tail = newNode;
            first = first->next;
            second = second->next;
        }
    }
    Node *temp = ans;
    ans = ans->next;
    delete temp;
    return ans;
}

int main()
{
    return 0;
}