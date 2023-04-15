// Check whether a linked list is a palindrome or not
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

// Approach1 : first i will reverse the linked list then save the reverse list in a new linked list and then reverse back the original linked list and then traverse both the lists and check whether all the elements are same or not
// If they are equal then the given linked list is a plaindrome otherwise it is not a palindrome
// Time complexity : O(n)
// Space complexity : O(n)
void reverseList(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = head;
    while (temp)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool checkPalindrome(Node *head)
{
    reverseList(head);
    Node *newList = new Node(-1);
    Node *tail = newList;
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->data);
        tail->next = newNode;
        tail = newNode;
        temp = temp->next;
    }

    reverseList(head);

    while (head && newList)
    {
        if (head->data != newList->data)
        {
            return false;
        }
        head = head->next;
        newList = newList->next;
    }
    return true;
}

Node *getMiddle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast)
    {
        slow = slow->next;
    }
    return slow;
}

bool checkPalindromeOptimized(Node *head)
{
    Node *middle = getMiddle(head);
    reverseList(middle);
    while (head && middle)
    {
        if (head->data != middle->data)
        {
            return false;
        }
        head = head->next;
        middle = middle->next;
    }
    return true;
}

int main()
{
    return 0;
}