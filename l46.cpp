// Questions on linked lists
// lecture 26 started

// reverse a linked list in k groups
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

Node *reverseInGroups(Node *head, int k)
{
    if (head == NULL || k == 1 || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        for (int i = 0; i < k && curr; i++)
        {
            Node *fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        head->next = reverseInGroups(curr, k);
        return prev;
    }
}

// Write a function to check whether the linked list given to you is circular or not
bool isCircular(Node *head)
{
    if (head == NULL)
        return true;
    Node *temp = head;
    temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    else if (temp == NULL)
    {
        return false;
    }
}

// Delecting a cycle in a linked list using hashing or using maps
bool isCircularUsingMaps(Node *head)
{
    if (head == NULL)
        return true;
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp)
    {
        if (visited[temp])
        {
            return false;
        }
        else
        {
            visited[temp] = true;
        }
    }
    return false;
}

// Write a function to check if there is a loop in a linked list
bool isLoopPresent(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        Node *temp = head;
        map<Node *, bool> visited;
        while (temp)
        {
            if (visited[temp])
            {
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
        }
    }
    return false;
}

int main()
{
    return 0;
}

// H.W. : Study floyd's cycle detection algorithm