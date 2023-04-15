// Write a program to delete a loop in a linked list
#include <iostream>
#include <map>
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

// Using floyd's cycle detection algorithm or the tortoise and the hare algorithm
bool detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// Using the mapping algorithm
bool detectLoopUsingMap(Node *head)
{
    map<Node *, bool> visited;
    while (head)
    {
        if (visited[head])
        {
            return true;
        }
        visited[head] = true;
        head = head->next;
    }
    return false;
}

// Using the mapping algorithm
Node *detectLoopAndReturnUsingMap(Node *head)
{
    map<Node *, bool> visited;
    while (head)
    {
        if (visited[head])
        {
            return head;
        }
        visited[head] = true;
        head = head->next;
    }
    return NULL;
}

// Using floyd's cycle detection algorithm or the tortoise and the hare algorithm
Node *detectLoopAndReturn(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    else
    {
        Node *fast = head;
        Node *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }
        if (fast && fast->next)
        {
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
        else
        {
            return NULL;
        }
    }
}

void deleteLoopUsingMap(Node *head)
{
    map<Node *, bool> visited;
    Node *curr = head;
    Node *prev = NULL;
    while (curr)
    {
        if (visited[curr])
        {
            prev->next = NULL;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    return;
}

void deleteLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (fast && fast->next)
    {
        if (slow == head)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }
        slow = head;
        Node *prev = NULL;
        while (fast != slow)
        {
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = NULL;
        return;
    }
    else
    {
        return;
    }
}
int main()
{
}