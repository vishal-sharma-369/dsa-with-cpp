// Finding the  Intersection point of two linked lists
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

// Approach1 : I will use a map and store all the visited nodes in the map and on iterating the second list the first common visited node will be the intersection point
Node *findIntersectionPoint(Node *first, Node *second)
{
    map<Node *, bool> visited;
    while (first)
    {
        visited[first] = true;
        first = first->next;
    }
    while (second)
    {
        if (visited[second])
        {
            return second;
        }
        second = second->next;
    }
    return NULL;
}

int getLength(Node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

Node *findIntersection(Node *first, Node *second)
{
    int firstLength = getLength(first);
    int secondLength = getLength(second);
    int position = 0;
    if (firstLength > secondLength)
    {
        position = firstLength - secondLength;
        for (int i = 0; i < position; i++)
        {
            first = first->next;
        }
    }
    else
    {
        position = secondLength - firstLength;
        for (int i = 0; i < position; i++)
        {
            second = second->next;
        }
    }
    while (first != second)
    {
        first = first->next;
        second = second->next;
    }
    return first ? first : NULL;
}

int main()
{
    return 0;
}