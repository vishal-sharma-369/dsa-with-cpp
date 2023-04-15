// The question is to find the middle element of the linkedlist
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

// Approach1 : First find the length of the linked list and then find the middle of the length of the linkedlist

Node *findMiddleFirst(Node *head)
{
    int length = 0;
    Node *iterator = head;
    while (iterator)
    {
        length++;
        iterator = iterator->next;
    }
    int mid = length / 2;
    for (int i = 0; i < mid; i++)
    {
        head = head->next;
    }
    return head;
}

// Appraoch2 : Use a fast and a slow pointer i.e. tortoise and the hare algorithm to find the middle element of the linked list
Node *findMiddle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    return 0;
}