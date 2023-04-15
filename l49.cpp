// Questions on Linked Lists:

#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if(this->next)
        {
            delete this->next;
            this->next = NULL;
        }
    }
};

// Write a function to sort 0's 1's and 2's in a Linked List

// Approach1 : Firstly count the number of 0's  1's and 2's in the linked list and then fill the linked list node data according to the count of the respective elements in the counts
void sortElements(Node*head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node*temp = head;
    while(temp)
    {
        if(temp->data == 0)
        {
            count0++;
        }
        else if(temp->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp)
    {
        if(count0)
        {
            temp->data = 0;
            count0--;
        }
        else if(count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
}

// Sort the given linked list of 0's 1's and 2's in ascending order without replacing the data i.e. you are only allowed to change the links
// The time complexity of this solution is O(n) and the space complexity of this solution is O(1) okey vishal sharma
void insertAtTail(Node*&tail,Node*curr)
{
    tail->next = curr;
    tail = curr;
}

void sortLinkedList(Node*head)
{
    Node*zeroHead = new Node(0);
    Node*zeroTail = zeroHead;
    Node*oneHead = new Node(1);
    Node*oneTail = oneHead;
    Node*twoHead = new Node(2);
    Node*twoTail = twoTail;

    Node*curr = head;
    while(curr)
    {
        int value = curr->data;
        if(value == 0)
        {
            insertAtTail(zeroTail,curr);
        }
        else if(value ==1)
        {
            insertAtTail(oneTail,curr);
        }
        else
        {
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }


    // The next step is to merge all the three Linked lists
    if(oneHead->next)
    {
        zeroTail->next = oneHead->next;
        oneHead->next = twoHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}


// Write a function to merge two sorted linked lists
void mergeLinkedLists(Node*head1,Node*head2)
{
    Node*ans = new Node(0);
    Node*ansTail = ans;
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            ansTail->next = head1;
            ansTail = head1;
            head1 = head1->next;
        }
        else
        {
            ansTail->next = head2;
            ansTail = head2;
            head2 = head2->next;
        }
    }
    if(head1)
    {
        ansTail->next = head1;
    }
    else if(head2)
    {
        ansTail->next = head2;
    }
}


Node* solve(Node*first,Node*second)
{
    if(first->next==NULL)return second;
    Node*curr = first;
    Node*next = first->next;
    Node*curr2 = second;
    while(next && curr2)
    {
        if(curr->data <= curr2->data && curr2->data <= next->data)
        {
            curr->next = curr2;
            Node*temp = curr2->next;
            curr2->next = next;
            curr = curr2;
            curr2 = temp;
        }
        else
        {
            next = next->next;
            curr = curr->next;
            if(next==NULL)
            {
                curr->next = curr2;
            }
        }
    }
    return first;
}

Node* mergeTwoLinkedLists(Node*head1,Node*head2)
{
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    if(head1->data<=head2->data)
    {
        solve(head1,head2);
    }
    else
    {
        solve(head2,head1);
    }
}

int main()
{
    return 0;
}