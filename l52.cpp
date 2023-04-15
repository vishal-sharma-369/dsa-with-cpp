// Solving linked list hard level question
// Clone a linked list with all its next pointers and its random pointers

// Approach 1: Create a clone linked list using the simple nodes and the next pointers of the origianl list
// Then traverse through the original list and for each node find the position of the node from the first node where its random pointer is pointing to . then for each node clone the random pointer in the new linked list
// The time complexity of this approach will be O(n^2) as for simple node copying using next pointers will take O(n) and then traversing the radom pointer and findind its position and then updating the new list will take O(n^2) time.

// Approach2: In this approach we will first make the simple clone linked list using the next pointers of the original list
// then we will map the corresponding nodes of the original list with the new nodes of the new linked list then we will traverse teh origianl linked list and set the random pointer of new nodes to the maapped values of the original linked list values.
// Matlab samajh me aa gaya
// The time complexity of this approach will be O(n).
// But the space complexity of this approach is also O(n).

// Implementation of 2nd approach
#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
    ~Node()
    {
        if (this->next)
        {
            delete this->next;
            this->next = NULL;
        }
        if (this->random)
        {
            delete this->random;
            this->random = NULL;
        }
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *cloneLinkedList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *originalIterator = head;
    while (originalIterator)
    {
        insertAtTail(cloneHead, cloneTail, originalIterator->data);
        originalIterator = originalIterator->next;
    }
    Node *cloneIterator = cloneHead;
    originalIterator = head;
    map<Node *, Node *> mapping;
    while (originalIterator)
    {
        mapping[originalIterator] = cloneIterator;
        originalIterator = originalIterator->next;
        cloneIterator = cloneIterator->next;
    }

    originalIterator = head;
    cloneIterator = cloneHead;
    while (originalIterator)
    {
        cloneIterator->random = mapping[originalIterator->random];
        originalIterator = originalIterator->next;
        cloneIterator = cloneIterator->next;
    }
    return cloneHead;
}

int main()
{
    return 0;
}

// Approach 3: How to optimize the previous approach
// create the clone linked list using the next pointers of the original list
// insert the clone list in between the orignal list
// for each node in original linked list set temp->next->random = temp->random->next and update temp as temp = temp->next->next until temp becomes null
// No reverse back the changes made in the step 2 of the appraoch
// Time complexity of this appraoch is O(n) and the space complexity of this appraoch is O(1).

Node *cloneLinkedListBetter(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *originalIterator = head;

    // Step1 : cloning the original linked list using the simple next pointers
    while (originalIterator)
    {
        insertAtTail(cloneHead, cloneTail, originalIterator->data);
        originalIterator = originalIterator->next;
    }
    Node *cloneIterator = cloneHead;
    originalIterator = head;

    // Step2 : Inserting the cloned linked list in between the original linked list
    while (originalIterator)
    {
        Node *temp = originalIterator->next;
        originalIterator->next = cloneIterator;
        cloneIterator->next = temp;
        originalIterator = temp;
    }

    // Step3 : Setting the random pointers of the cloned linked list using the random ponters of the original linked list
    originalIterator = head;
    while (originalIterator)
    {
        if (originalIterator->random)
        {
            originalIterator->next->random = originalIterator->random->next;
            originalIterator = originalIterator->next->next;
        }
        else
        {
            originalIterator->next = originalIterator->random;
        }
    }

    // Step4: Reversing the changes made in the step2
    Node *temp = NULL;
    originalIterator = head;
    while (originalIterator)
    {
        temp = originalIterator->next->next;
        if (temp)
        {
            originalIterator->next->next = temp->next;
            originalIterator->next = temp;
            originalIterator = temp;
        }
        else
        {
            originalIterator->next->next = NULL;
            originalIterator->next = NULL;
            originalIterator = temp;
        }
    }

    // Step5: return the answer
    return cloneHead;
}