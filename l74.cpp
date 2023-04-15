// Today we are gonna work with the heaps
// heaps is a data structure
// today we are going to talk about heapfy and heap sort algorithm

// what is a heap
// heap is  a complete binary tree that comes with a heap order property
// complete binary tree: the type of tree in which every level is completely filled except the  last level and the nodes are always lean or are added from the left.
// teh levels are always filled from the left side.

// There are two types of heap orders : min-heap and the max-heap
// the min-heap is the type of heap in which the top most element is the smallest element and its children are greater than it
// the max-heap is the type of heap in which the top most element is the greatest element and its children are smaller than it

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Write a program for insertion in a heap

// We will implement a heap using an array

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
        arr[0] = -1;
    }
    void insert(int data)
    {
        arr[size + 1] = data;
        size++;
        int iterator = size;
        while (iterator > 1)
        {
            int parent = iterator / 2;
            if (arr[iterator] > arr[parent])
            {
                swap(arr[iterator], arr[parent]);
                iterator = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "heap is empty i.e. nothing to delete" << endl;
            return;
        }
        else
        {
            arr[1] = arr[size];
            size--;

            // take root node to its correct position
            int iterator = 1;
            int temp = iterator;
            while (iterator < size)
            {
                int left = 2 * temp;
                int right = 2 * temp + 1;
                if (left <= size && arr[temp] < arr[left])
                {
                    temp = left;
                }
                if (right <= size && arr[temp] < arr[right])
                {
                    temp = right;
                }
                if (temp != iterator)
                {
                    swap(arr[temp], arr[iterator]);
                    iterator = temp;
                }
                else
                {
                    return;
                }
            }
        }
    }
};

// The time complexity of insertion in a heap is O(logn)
// Write a program for deletion in a heap
// The time complexity of deletion in a heap is O(logn)

// What is heapify algorithm?
// This algorithm places a node to its correct position in a heap.
// The given index of the node is given and you have  to place it at the correct position.

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest < arr[right]])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// Write a program to sort an array using Heap sort
void heapSort(int arr[], int size)
{
    int size = size;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 56};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Printing the array now " << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // take the array
    // create the heap for the given array
    // use the heap sort algorithm for the created heap
    // the resulting heap is a sorted array
    // The time complexity of heap sort algorithm is O(nlogn)
    return 0;
}

// The data structure priority queue is  used to implement the max-heap by default
// The data structure priority queue by some modifications is used to implement the min-heap