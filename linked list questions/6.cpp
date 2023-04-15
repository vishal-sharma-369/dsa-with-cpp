// The question is to remove all the duplicates from an unsorted linked list
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

// Approach1 : First approach would be to take a node and another iterator from node->next and look for the same elements and if found remove that element
// The time complexity of this solution is O(n^2) and the space complexity of this solution is O(1).
void removeDuplicates(Node *head)
{
    while (head && head->next)
    {
        Node *temp = head->next;
        Node *prev = head;
        while (temp)
        {
            if (temp->data == head->data)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = prev->next;
                temp = temp->next;
            }
        }
        head = head->next;
    }
    return;
}

// Approach2 : Second approach would be to use a map and store the map of all the elements which have been visited
// The time complexity of this solution is O(n) and the space complexity of this solution is O(n).
void removeDuplicatesUsingMap(Node *head)
{
    map<int, bool> visited;
    Node *curr = head;
    Node *prev = NULL;
    while (curr)
    {
        if (visited[curr->data])
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

// Approach3 : Third approach would be to sort the linked list first using O(nlogn) complexity and then remove the duplicates from the linked list using O(n) time complexity
// The overall time complexity of this solution is O(nlogn) and the space complexity of this solution is O(logn)
Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    Node *ans = new Node(-1);
    Node *tail = ans;
    while (left && right)
    {
        if (left->data < right->data)
        {
            tail->next = left;
            tail = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            tail = right;
            right = right->next;
        }
    }
    return ans->next;
}

Node *findMid(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeSort(Node *head)
{
    if (head == NULL)
        return NULL;
    // Step 1: break the linked list into two halves
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // Step 2: sort the left and the right halves
    left = mergeSort(left);
    right = mergeSort(right);
    Node *ans = merge(left, right);
    return ans;
}

void removeDuplicatesUsingSorting(Node *head)
{
    head = mergeSort(head);
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
}

int main()
{
    return 0;
}