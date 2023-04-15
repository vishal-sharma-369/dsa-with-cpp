// Detect a loop in a linked list using floyd's cycle detection algorithm
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
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

Node *giveLoopPresent(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *fast = head;
        Node *slow = head;
        while (fast->next != NULL && fast != slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next == NULL)
        {
            return NULL;
        }
        if (fast == slow)
        {
            return slow;
        }
    }
}

Node *getStartingNode(Node *head)
{
    Node *intersection = giveLoopPresent(head);
    if (intersection)
    {
        Node *fast = intersection;
        Node *slow = head;
        while (slow != intersection)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    else
    {
        return NULL;
    }
}

void removeLoop(Node *head)
{
    Node *intersection = giveLoopPresent(head);
    if (intersection)
    {
        Node *fast = intersection;
        Node *slow = head;
        Node *prev = NULL;
        while (fast != slow)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}

int main()
{
    return 0;
}


// To detect a loop in a linked list -> there are two algorithms either you can use the map or you can use the floyd's cycle detection  algorithm
// Okey vishal sharma


// There are 5 ways to remove a loop from a linked list ---> You have been taught only one way so it is your homework to see and learn the other 4 ways okey vishal sharma