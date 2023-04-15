// The question is to remove all the duplicates from a sorted linked list
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

void removeDuplicates(Node *head)
{
    while (head && head->next)
    {
        if (head->data == head->next->data)
        {
            Node *temp = head->next;
            head->next = head->next->next;
            delete temp;
        }
        else
        {
            head = head->next;
        }
    }
    return;
}

int main()
{
    return 0;
}