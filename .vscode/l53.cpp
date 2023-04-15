// Sort a linked list using merge sort
// #include <iostream>

// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
//     ~Node()
//     {
//         if (this->next)
//         {
//             delete this->next;
//             this->next = NULL;
//         }
//     }
// };

// Node *findMid(Node *head)
// {
//     if (!head)
//         return head;
//     Node *slow = head;
//     Node *fast = head;
//     while (fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }

// Node *merge(Node *left, Node *right)
// {
//     if (!left)
//         return right;
//     if (!right)
//         return left;
//     Node *ans = new Node(-1);
//     Node *tail = ans;
//     while (left && right)
//     {
//         if (left->data < right->data)
//         {
//             tail->next = left;
//             tail = left;
//             left = left->next;
//         }
//         else
//         {
//             tail->next = right;
//             tail = right;
//             right = right->next;
//         }
//     }
//     return ans->next;
// }

// Node *mergeSort(Node *head)
// {
//     if (!head || !head->next)
//     {
//         return head;
//     }

//     // Step1 : break the list into two halves
//     Node *mid = findMid(head);
//     Node *left = head;
//     Node *right = mid->next;
//     mid->next = NULL;

//     // step2 : sort the left and the right half
//     left = mergeSort(left);
//     right = mergeSort(right);

//     // Step3: merge the sorted left and the right half
//     Node *result = merge(left, right);
//     return result;
// }

// int main()
// {
//     return 0;
// }

// // So this was the logic to find two sorted linked lists.
/*














*/

// Write a program to flatten a linked list using merge sort
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *down;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->down = NULL;
        this->right = NULL;
    }
    ~Node()
    {
        if (this->down)
        {
            delete this->down;
            this->down = NULL;
        }
        if (this->right)
        {
            delete this->right;
            this->right = NULL;
        }
    }
};

Node *merge(Node *down, Node *right)
{
    Node *ans = new Node(-1);
    Node *tail = ans;
    while (down && right)
    {
        if (down->data < right->data)
        {
            tail->right = down;
            tail = down;
            down = down->down;
        }
        else
        {
            tail->right = right;
            tail = right;
            right = right->right;
        }
    }
    while (down)
    {
        tail->right = down;
        tail = down;
        down = down->down;
    }
    while (right)
    {
        tail->right = right;
        tail = right;
        right = right->right;
    }
    return ans->right;
}

Node *flatten(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        Node *down = head;
        Node *right = head->right;
        down->right = NULL;
        right = flatten(right);
        Node *ans = merge(down, right);
        return ans;
    }
}

int main()
{
    return 0;
}