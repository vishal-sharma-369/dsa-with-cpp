// Write a program to check whether the linked list is a palindrome or not

#include<iostream>
#include<vector>

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
        }
    }
};


// Approach1 : place all the elements of the linked list into an array and then use the simple methods to check whether the elements in the array are in plaindrome or not.

bool isPalindrome(Node*head)
{
    vector<int> array;
    while(head)
    {
        array.push_back(head->data);
        head = head->next;
    }

    int start = 0;
    int end = array.size()-1;
    while(start<=end)
    {
        if(array[start] != array[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}



// Approach2: first find the middle element of the linked list and then reverse the list that is beyond the middle element and then compare the element of the first list with the elements of the second list to check whether the list is in palindrome or not. Okey vishal sharma
Node*reverse(Node*head)
{
    Node*curr = head;
    Node*prev = NULL;
    while(curr)
    {
        Node*fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}
bool isPalindromeUsingBetterApproach(Node*head)
{
    if(head == NULL || head->next == NULL)return true;
    Node*slow = head;
    Node*fast = head;
    while(fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast)
    {
        fast = slow->next;
        fast = reverse(fast);
        slow = head;
        while(fast)
        {
            if(fast->data != slow->data)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        fast = slow;
        fast = reverse(fast);
        slow = head;
        while(fast)
        {
            if(fast->data != slow->data)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    return 0;
}