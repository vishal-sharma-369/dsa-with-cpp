// The question is to reverse a linked list

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

// Code to iteratively reverse a linked list
void reverseList(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr)
        {
            Node *fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        head = prev;
    }
}

// Code to recursively reverse a linked list
void reverseList(Node *&head, Node *prev, Node *curr)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    else
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        reverseList(head, prev, curr);
    }
}
int main()
{
    return 0;
}