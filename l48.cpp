// Let us start with lecture number 48 of love babbar playlist


// Write a program to remove all the duplicates from a linked list
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


// Write a function to delete or remove all the duplicates from a sorted linked list
void removeDuplicates(Node*head)
{
    if(head==NULL)return;
    else
    {
        Node*temp = head;
        while(temp->next)
        {
            if(temp->data == temp->next->data)
            {
                Node*t = temp->next;
                temp->next = temp->next->next;
                t->next = NULL;
                delete t;
                continue;
            }
            t = t->next;
        }
    }
}




// Write a function to delete or remove all the duplicates from unsorted linked list
// The below solution is the Brute force approach to solve this problem and it takes a time complexity of O(n^2) and a space complexity of O(1).So it is space efficient solution but not a time efficient solution.
void removeDuplicatesInUnsortedLL(Node*head)
{
    if(!head)return;
    else
    {
        Node*temp = head;
        while(temp->next)
        {
            Node*t = temp->next;
            Node*prev = temp;
            while(t)
            {
                if(t->data == temp->data)
                {
                    prev->next = t->next;
                    t->next = NULL;
                    delete t;
                    t = prev->next;
                }
                else
                {
                    prev = t;
                    t = t->next;
                }
            }
        }
    }
}

// Approach2 : First sort the linked list and then remove the duplicates from the sorted linked list in O(n) time complexity.
// The overall time complexity of this solution will be O(nlogn) and the space complexity will be O(1).






// Approach3: Use a map to keep a count on all the elements which have been visited before and then the two pointers prev and curr to remove all the element entries that have already been visited or entered in the visited map.
// The time complexity of this solution will be O(n) and the space complexity in worst case would be O(n) as we have used a map.


// Homework question is to split a circular linked list into two halves



int main()
{
    return 0;
}