// Reverse a Linked List in K groups
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

Node *ReverseKGroups(Node *&head, int k)
{
    if (head == NULL)
        return NULL;
    Node *curr = head;
    Node *prev = NULL;
    for (int i = 0; i < k && curr; i++)
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    head->next = ReverseKGroups(curr, k);
    head = prev;
    return prev;
}

int main()
{
    return 0;
}