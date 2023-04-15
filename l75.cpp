// questions on heaps

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// write a program to find the kth smallest element in an array
// approach1 : sort the given array and then return the kth element
// The time complexity of this solution will be O(nlogn)
// using heaps
// approach2 : store the first k elements in a max-heap and then return the root element of the heap
int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
// The space complexity of this solution is O(k)
// The time complexity of this solution is O()

// Write a program to check whether the given binary tree is a heap
// To solve this question we need to check whether the given bianry tree follows the condition of complete binary tree and the condition of maxheap or not
class Node
{
public:
    Node *left;
    Node *right;
    int data;
};
bool isCBT(Node *root, int i, int nodeCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (i >= nodeCount)
    {
        return false;
    }
    return isCBT(root->left, 2 * i + 1, nodeCount) && isCBT(root->left, 2 * i + 2, nodeCount);
}

bool isMaxOrder(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->right == NULL)
    {
        if (root->data > root->right->data)
        {
            return true;
        }
    }
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    if (left && right && root->data > root->left->data && root->data > root->right->data)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = countNode(root->left);
    int right = countNode(root->right);
    return left + right + 1;
}

bool isCBT(struct Node *root)
{
    int index = 0;
    int totalCount = countNode(root);
    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// The time complexity of this solution is O(n) + O(n) + O(n)

// Write a program to merge two binary max heaps
// first of all merge the given two arrays
// then takke the array through the heapfiy function
// Time complexity of this solution is O(n)

void heapify(vector<int> &arr, int index, int size)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, largest, size);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{

    vector<int> ans;
    ans.push_back(-1);
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    // build heap using merged array
    int n = ans.size();
    for (int i = n / 2; i > 0; i--)
    {
        heapify(ans, i, n);
    }
    return ans;
}

// Write a program to find the minimum cost of ropes

long long minimumCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }
    long long cost = 0;
    while (minHeap.size() != 1)
    {
        long long a = minHeap.top();
        minHeap.pop();
        long long b = minHeap.top();
        minHeap.pop();
        cost += a + b;
        minHeap.push(a + b);
    }
    return cost;
}
// The time complexity of this solution is O(nlogn)
// The space complexity of this solution is O(n)

// Write a program to convert a binary search tree into a minHeap. It is already given that the given binary search tree is a complete binary tree
void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// The below code is incomplete due to the power shortage
void fillHeap(Node *root, vector<int> inord, int index)
{
    if (root == NULL)
    {
        return;
    }
    root->data;
}

void convertToMinHeap(Node *root)
{
    vector<int> inord;
    inorder(root, inord);
}

int main()
{
    return 0;
}