// Write a program to detect a loop in a linked list
// I will use a map and store the addresses of all the nodes that have already been visited , if the iterator points to the same node again then the linked list contains a loop otherwise if the iterator becomes null then it does not contain a loop
// I will use the fast and the slow pointer approach to check whether the linked list contains a loop or not

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

int main()
{
    return 0;
}