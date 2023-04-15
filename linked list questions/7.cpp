// Add One to a number represented by a linkedlist
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

void reverseList(Node *&head)
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

Node *addOne(Node *head, int k)
{
    reverseList(head);
    int carry = 0;
    Node *temp = head;
    temp->data += k;
    carry = temp->data / 10;
    temp->data = temp->data % 10;
    temp = temp->next;
    while (carry && temp)
    {
        temp->data += carry;
        carry = temp->data / 10;
        temp->data = temp->data % 10;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        reverseList(head);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        reverseList(head);
    }
    return head;
}

// Write a function to add two numbers represented by a linked list
Node *addTwoNumbers(Node *firstList, Node *secondList)
{
    Node *first = firstList;
    Node *second = secondList;
    reverseList(first);
    reverseList(second);
    int carry = 0;

    Node *ans = new Node(-1);
    Node *tail = ans;
    while (first || second || carry)
    {
        int sum = first ? first->data : 0 + second ? second->data
                                                   : 0 + carry;
        carry = sum / 10;
        sum = sum % 10;
        Node *newNode = new Node(sum);
        tail->next = newNode;
        tail = newNode;
        first = first ? first->next : NULL;
        second = second ? second->next : NULL;
    }
    Node *temp = ans;
    ans = ans->next;
    delete temp;
    first = firstList;
    second = secondList;
    reverseList(first);
    reverseList(second);
    reverseList(ans);
    return ans;
}

int main()
{
    return 0;
}