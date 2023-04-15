// Convert a circular linked list into two halves
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

void splitter(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != head && fast->next != head)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (fast->next == head)
    {
        prev = slow;
        slow = slow->next;
    }
    prev->next = head;
    prev = slow;
    while (prev->next != head)
    {
        prev = prev->next;
    }
    prev->next = slow;

    // the answer will be head and the slow pointer okey vishal sharma
}

int main()
{
    return 0;
}