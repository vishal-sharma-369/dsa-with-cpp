// Count all the triplets with a given sum in a given linked list
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

// Approach1 : Use the brute force approach and check all the triplets to check whether their sum == given sum or not and return the result
// Time complexity of this solution is O(n^3)
// Space complexity of this solution is O(1)
int countTriplets(Node *head, int sum)
{
    int count = 0;
    Node *first = head;
    while (first && first->next && first->next->next)
    {
        Node *second = first->next;
        while (second && second->next)
        {
            Node *third = second->next;
            while (third)
            {
                if (first->data + second->data + third->data == sum)
                {
                    count++;
                }
                third = third->next;
            }
            second = second->next;
        }
        first = first->next;
    }
    return count;
}

int main()
{
    return 0;
}