#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// implement a heap using simple array
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
        int index = size + 1;
        arr[index] = data;
        size++;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteFromHeap()
    {
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int temp = i;
            int left = 2 * i;
            int right = 2 * i + 1;
            if (left <= size && arr[left] > arr[temp])
            {
                temp = left;
            }
            if (right <= size && arr[right] > arr[temp])
            {
                temp = right;
            }
            if (temp != i)
            {
                swap(arr[temp], arr[i]);
                i = temp;
            }
            else
            {
                return;
            }
        }
    }
};

// Implementing the max and min heap using the stl library
// implementing the max heap
void maxHeap()
{
    priority_queue<int> maxHeap;
}
void minHeap()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
}

// Write a progrma to find the kth smallest element in an array
int kthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}

// Write a program to find the kth largest element in an array
int kthLargestElement(int arr[], int n, int k)
{
    priority_queue<int> minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}
// The space complexity of this solution is O(k)
// The time complexity of this solution is O(nlogk)

// Write a program to sort a k sorted array
// Approach1 : the first approach will be to simply sort the given array.
// The time complexity of this solution is O(nlogn) and the space complexity of this solution depends on the merge sort algorithm

// approach2 : we will be using a heap to solve this question
void sortKSorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(arr[i]);
    }

    int i = k;

    while (i < n)
    {
        arr[i - k] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i++]);
    }

    while (!minHeap.empty())
    {
        arr[i - k] = minHeap.top();
    }
}
// // The time complexity of this solution will be O(nlogk)
// // The space ccomplexity of this solution will be O(k)
// #include <algorithm>
// // Write a program to find the k closest numbers to the given number n
// vector<int> kClosest(vector<int> arr, int k, int n)
// {
//     priority_queue<pair<int, int>> maxHeap;
//     for (int i = 0; i < k; i++)
//     {
//         maxHeap.push(make_pair(abs(arr[i], n), arr[i]));
//     }
//     for (int i = k; i < arr.size(); i++)
//     {
//         if (arr[i] - n < maxHeap.top().first)
//         {
//             maxHeap.pop();
//             maxHeap.push(make_pair(abs(arr[i] - n), arr[i]));
//         }
//     }
//     vector<int> ans;
//     while (!maxHeap.empty())
//     {
//         ans.push_back(maxHeap.top().second);
//         maxHeap.pop();
//     }
//     return ans;
// }

// Write a program to find  top k frequent numbers
// vector<int> topKFrequent(vector<int> arr, int k)
// {
//     unordered_map<int, int> mp;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//     vector<int> ans;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         mp[arr[i]]++;
//     }
//     for (auto i = mp.begin(); i != mp.end(); i++)
//     {
//         minHeap.push(make_pair(i->second, i->first));
//         if (minHeap.size() > k)
//         {
//             minHeap.pop();
//         }
//     }
//     while (!minHeap.empty())
//     {
//         ans.push_back(minHeap.top().second);
//     }
//     return ans;
// }

// Write a program to sort an array based on the frequency of elements occuring in the array
// vector<int> sortUsingFrequency(vector<int> arr)
// {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         mp[arr[i]]++;
//     }
//     priority_queue<pair<int, int>> maxHeap;
//     for (auto i = mp.begin(); i != mp.end(); i++)
//     {
//         maxHeap.push(make_pair(i->second, i->first));
//     }
//     int i = 0;
//     while (!maxHeap.empty())
//     {
//         pair<int, int> temp = maxHeap.top();
//         maxHeap.pop();
//         while (temp.first)
//         {
//             arr[i] = temp.second;
//             temp.first--;
//         }
//     }
//     return arr;
// }

// Write a program to print all the first k elements that are closest to the origin. Remember the points are given in an 2D plane

// vector<pair<int, int>> kclosestPointToOrigin(vector<vector<int>> arr, int k)
// {
//     priority_queue<pair<int, pair<int, int>>> maxHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         maxHeap.push(make_pair(arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], make_pair(arr[i][0], arr[i][1])));
//         if (maxHeap.size() > k)
//         {
//             maxHeap.pop();
//         }
//     }
//     vector<pair<int, int>> ans;
//     while (!maxHeap.empty())
//     {
//         ans.push_back(maxHeap.top().second);
//         maxHeap.pop();
//     }
//     return ans;
// }

// Write a program to connect two ropes such that the cost is minimum
// int minimumCost(vector<int> arr)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push(arr[i]);
//     }
//     int cost = 0;
//     while (minHeap.size() > 1)
//     {
//         int a = minHeap.top();
//         minHeap.pop();
//         int b = minHeap.top();
//         minHeap.pop();
//         int sum = a + b;
//         cost += sum;
//         minHeap.push(sum);
//     }
//     return cost;
// }

// Write a program to get the sum of elements between k1 smallest and k2 smallest numbers
int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < arr.size(); i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int sumElementsBetweenRange(vector<int> arr, int k1, int k2)
{
    int firstSmallest = kthSmallest(arr, k1);
    int secondSmallest = kthSmallest(arr, k2);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > firstSmallest && arr[i] < secondSmallest)
        {
            sum += arr[i];
        }
    }
    return sum;
}

// The concept of perfect binary tree : all the levels are completely filled
// Almost complete binary tree concept: until second last level it follows the perfect binary tree concept and for the last level it follows that all the leaf nodes should be present either on both sices or they should lean on the left side of the parent node
// Complete binary tree follows two concepts : 1. perfect binary tree until the second last level 2. almost complete binary tree concept in which the last level nodes are always filled from left to right side.

// Heap data structure follows the three concepts:
// 1. tree ds
// 2. complete binary tree
// 3. heap property

// Some special type of heaps:
// Binomial heap
// Fibonacci heap
// Leftist heap

// Write a program to implement a heap using an array
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        // this is gonna be a 0 indexing heap
        size = 0;
    }
    void insert(int data)
    {
        int index = size;
        size++;
        arr[index] = data;
        while (index > 0)
        {
            int parent = (index + 1) / 2 - 1;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        arr[0] = arr[size - 1];
        size--;
        int index = 0;
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int temp = index;
            if (left < size && arr[left] > arr[temp])
            {
                temp = left;
            }
            if (right < size && arr[right] > arr[temp])
            {
                temp = right;
            }
            if (temp != index)
            {
                swap(arr[temp], arr[index]);
                index = temp;
            }
            else
            {
                return;
            }
        }
    }
};

/*
For a 0 based indexing heap
parent -> i then left -> 2i+1 and right->2*i+2
child -> i then parent = ceil(i/2) + 1
heap is  a complete binary tree and be sorted in array
max array size = (2^(h+1) - 1) for a perfect binary tree
max nodes at height h = 2^h
max nodes at entire tree of height h = 2^(h+1) - 1 for a perfect binary tree
range of leaves -> floor(n/2) + 1 to n
range of interanl nodes -> 1 to floor(n/2)
note: log base 2 is taken for binary tree
*/

// Now we are going to learn about the heapify algorithm
// this is also known as the percolate down algorithm
// Heap implementation
// max-heapfiy and the min-heapify

/*
for 0 based indexing
if heap size = n
then range of leaves = floor(n/2) to (n-1)
range of internal nodes = 0 to floor(n/2)-1
*/

// heapify is an algorithm in which the ith node needs to be rearranged to  maintain heap property
// node: except ith node, entire tree is a heap
// --> rearrange recursively

// The time complexity of heapify algorithm is O(logn)

void heapify(vector<int> arr, int n, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = -1;
    if (left <= arr.size() && arr[left] > arr[index])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }
    if (right <= arr.size() && arr[right] > arr[largest])
    {
        largest = right;
    }
    else
    {
        largest = index;
    }
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Write a program to build a heap from a given array using the heapify algorithm
// The time complexity of this algorithm is O(n)
// The time complexity to delete the maximum element from the maxHeap is O(logn) and the space complexity is O(1)

// increasing key or the addition of elemets to the heap follows the percolate up algorithm
// decreasing key or the removing of elements to the heap follows the percolate down algorithm .
// inserting an elements follows the percolate up algorithm

// Write down all the steps for the heap sort algorithm
// 1. first of all build the heap from the given array
// 2. fill the array from the heap elements and correspondingly delete the top root elements from the min or max heaps.
// The time complexity of this solution is O(nlogn)
// The space complexity of this solution is O(logn)

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void Heapify(vector<int> &heap, int curr, int size)
// {
//     int largest = curr;
//     int l = 2 * curr + 1;
//     int r = 2 * curr + 2;
//     if (l < size && heap[l] > heap[largest])
//     {
//         largest = l;
//     }
//     if (r < size and heap[r] > heap[largest])
//     {
//         largest = r;
//     }
//     if (largest != curr)
//     {
//         int temp = heap[curr];
//         heap[curr] = heap[largest];
//         heap[largest] = temp;

//         Heapify(heap, largest, size);
//     }
// }

// void heapSort(vector<int> &heap)
// {
//     for (int i = heap.size() / 2 - 1; i >= 0; i--)
//     {
//         Heapify(heap, i, heap.size());
//     }
//     for (int i = heap.size() - 1; i > 0; --i)
//     {
//         int temp = heap[0];
//         heap[0] = heap[i];
//         heap[i] = temp;

//         Heapify(heap, 0, i);
//     }
// }

// #include <bits/stdc++.h>
// #include <iostream>

// #define size 1001

// int heap[size];
// int heapSize;

// // void heap_push(int val)
// // {
// //     if (heapSize >= size)
// //     {
// //         cout << "heap overflow" << endl;
// //         return;
// //     }

// //     heap[heapSize] = val;
// //     int curr = heapSize;
// //     // percolate up
// //     while (curr > 0 and heap[(curr - 1) / 2] < heap[curr])
// //     {
// //         int temp = heap[(curr - 1) / 2];
// //         heap[(curr - 1) / 2] = heap[curr];
// //         heap[curr] = temp;

// //         curr = (curr - 1) / 2;
// //     }
// //     heapSize += 1;
// // }

// void heap_push(int val)
// {
//     if (heapSize >= size)
//     {
//         cout << "heap overflow" << endl;
//         return;
//     }
//     heap[heapSize] = val;
//     int curr = heapSize;
//     // percolate up
//     while (curr > 0 and heap[(curr - 1) / 2] < heap[curr])
//     {
//         swap(heap[(curr - 1) / 2], heap[curr]);
//         curr = (curr - 1) / 2;
//     }
//     heapSize += 1;
// }

// int heap_pop()
// {
//     if (heapSize <= 0)
//     {
//         cout << "heap underflow" << endl;
//         return -1;
//     }
//     int curr = 0;
//     int popped = heap[0];
//     heap[0] = heap[heapSize - 1];
//     heapSize -= 1;
//     // Max heapify
//     while ((2 * curr + 1) < heapSize)
//     {
//         int child;
//         if ((2 * curr + 2 == heapSize))
//         {
//             child = 2 * curr + 1;
//         }
//         else
//         {
//             if (heap[2 * curr + 1] > heap[2 * curr + 2])
//             {
//                 child = 2 * curr + 1;
//             }
//             else
//             {
//                 child = 2 * curr + 2;
//             }
//         }
//         if (heap[curr] < heap[child])
//         {
//             int temp = heap[curr];
//             heap[curr] = heap[child];
//             heap[child] = temp;
//             curr = child;
//         }
//         else
//             break;
//     }
//     return popped;
// }

// Write a program to return the last stone weight
// int lastStoneWeight(vector<int> arr)
// {
//     priority_queue<int> maxHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         maxHeap.push(arr[i]);
//     }
//     while (maxHeap.size() > 1)
//     {
//         int x = maxHeap.top();
//         maxHeap.pop();
//         int y = maxHeap.top();
//         maxHeap.pop();
//         if (x - y)
//         {
//             maxHeap.push(x - y);
//         }
//     }
//     if (maxHeap.empty())
//     {
//         return 0;
//     }
//     else
//     {
//         return maxHeap.top();
//     }
// }
// The time complexity of this solution  is O(nlogn)
// The space complexity of this solution is O(n)

// Write a program to find the kth largest or the kth smallest element in an array

// the first approach will be to simply sort the array and return the kth element
// the time complexity of this solution is O(nlogn)
// int kthLargestElement(vector<int> arr, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push(arr[i]);
//         if (minHeap.size() > k)
//         {
//             minHeap.pop();
//         }
//     }
//     return minHeap.top();
// }

// // The time complexity of this solution is O(nlogk)
// // The space complexity of this solution is O(k)

// int kthSmallestElement(vector<int> arr, int k)
// {
//     priority_queue<int> maxHeap;
//     for (auto i : arr)
//     {
//         maxHeap.push(i);
//         if (maxHeap.size() > k)
//         {
//             maxHeap.pop();
//         }
//     }
//     return maxHeap.top();
// }

// The third approach to solve this question will be by using the quick select problem

// Write a program to return the first k frequent elements in an array
// vector<int> kFrequent(vector<int> &arr, int k)
// {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         mp[arr[i]]++;
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//     for (auto i : mp)
//     {
//         minHeap.push(make_pair(i.second, i.first));
//         if (minHeap.size() > k)
//         {
//             minHeap.pop();
//         }
//     }
//     vector<int> ans;
//     while (minHeap.size() > 0)
//     {
//         pair<int, int> temp = minHeap.top();
//         minHeap.pop();
//         while (temp.first)
//         {
//             ans.push_back(temp.second);
//             temp.first--;
//         }
//     }
//     return ans;
// }

// Write a program to sort a k sorted array
// appraoch1 : the simplest approach to solve this problem would be to sort the given array
// The time complexity of this solution will be O(nlogn)
// vector<int> sortKSorted(vector<int> arr, int k)
// {
//     for (int i = k - 1; i < arr.size(); i++)
//     {
//         for (int j = i; j > 0; j--)
//         {
//             if (arr[j] < arr[j - 1])
//             {
//                 swap(arr[j], arr[j - 1]);
//             }
//         }
//     }
//     return arr;
// }
// // the time complexity of this solution is O(n*k)

// // appraoch2 : the second approach to solve this problem will be to use a heap
// vector<int> sortKSortedUsingHeaps(vector<int> arr, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     vector<int> ans;
//     for (int i = 0; i < k; i++)
//     {
//         minHeap.push(arr[i]);
//     }
//     for (int i = k; i < arr.size(); i++)
//     {
//         ans.push_back(minHeap.top());
//         minHeap.pop();
//         minHeap.push(arr[i]);
//     }
//     while (minHeap.size() > 0)
//     {
//         ans.push_back(minHeap.top());
//         minHeap.pop();
//     }
//     return ans;
// }
// // The time complexity of this solution is O(nlogk)

// class Node
// {
// public:
//     int data;
//     Node *right;
//     Node *next;
//     Node()
//     {
//     }
// };
// // Write a program to sort a k sorted linked lists
// class compare
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->data > b->data;
//     }
// };

// vector<int> sortKSortedLists(vector<Node *> arr)
// {
//     priority_queue<Node *, vector<Node *>, greater<Node *>> minHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push(arr[i]);
//     }
//     vector<int> ans;
//     while (!minHeap.empty())
//     {
//         Node *temp = minHeap.top();
//         minHeap.pop();
//         ans.push_back(temp->data);
//         if (temp->next)
//         {
//             minHeap.push(temp->next);
//         }
//     }
//     return ans;
// }

// Write a program to find the median in a given data stream
// class solution
// {
// public:
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     int median = -1;

//     int signum()
//     {
//         return maxHeap.size() - minHeap.size();
//     }

//     void insert(int val)
//     {
//         switch (signum())
//         {
//         case 0:
//             median = val;
//             maxHeap.push(val);
//             break;

//         case 1:
//             if (val > median)
//             {
//                 minHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             else
//             {
//                 minHeap.push(maxHeap.top());
//                 maxHeap.pop();
//                 maxHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             break;
//         case -1:
//             if (val > median)
//             {
//                 maxHeap.push(minHeap.top());
//                 minHeap.pop();
//                 minHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             else
//             {
//                 maxHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             break;

//         default:
//             break;
//         }
//     }
// };
// // The time complexity of this solution is O(nlogn)

// // Now we will try to solve some hashmap questions
// vector<int> getcommonelement(vector<int> arr1, vector<int> arr2)
// {
//     unordered_map<int, int> map;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         map[arr1[i]]++;
//     }
//     vector<int> ans;
//     for (int i = 0; i < arr2.size(); i++)
//     {
//         if (map.find(arr2[i]) != map.end())
//         {
//             ans.push_back(arr2[i]);
//             map.erase(arr2[i]);
//         }
//     }
//     return ans;
// }

// // get the common elements between the two arrays along with the count of elements in the first element
// vector<int> getCommonElement(vector<int> arr1, vector<int> arr2)
// {
//     unordered_map<int, int> map;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         map[arr1[i]]++;
//     }
//     vector<int> ans;
//     for (int i = 0; i < arr2.size(); i++)
//     {
//         if (map.find(arr2[i]) != map.end())
//         {
//             ans.push_back(arr2[i]);
//             map[arr2[i]]--;
//             if (map[arr2[i]] == 0)
//             {
//                 map.erase(arr2[i]);
//             }
//         }
//     }
//     return ans;
// }

// Longest consecutive sequence of elements
int longestConsecutiveSequenceOfElements(vector<int> arr)
{
    unordered_map<int, bool> map;
    unordered_map<int, bool> containingMap;
    // step1 : check all the elements of the array to be true
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]] = true;
    }

    // extra step : checking all the elements that are present in the array
    for (int i = 0; i < arr.size(); i++)
    {
        containingMap[arr[i]] = true;
    }

    // step2 : uncheck all the elements of the array that can't be the starting elements of the sequences
    for (auto i : map)
    {
        if (map[i.first - 1])
        {
            map[i.first] = false;
        }
    }

    // step3 : calculate the sequence with the maximum count of consecutive elements present in the map
    int longestCount = INT_MIN;
    for (auto i : map)
    {
        int count = 0;
        int key = i.first;
        if (map[i.first] == true)
        {
            while (containingMap[key])
            {
                count++;
                key++;
            }
            if (count > longestCount)
            {
                longestCount = count;
            }
        }
        else
        {
            continue;
        }
    }
    return longestCount;
}

// Now we are going to work with the priority queue
// add remove peek
// add -> TC == O(logn)
// remove -> TC == O(logn)
// peek -> TC == O(1)

// Write a program to print all the elements of an array in sorted order
// void printSorted(vector<int> arr)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push(arr[i]);
//     }
//     while (!minHeap.empty())
//     {
//         cout << minHeap.top() << " ";
//         minHeap.pop();
//     }
//     cout << endl;
//     return;
// }

// // Write a program to print the first k largest elements in an array
// void printKLargest(vector<int> arr, int k)
// {
//     priority_queue<int> maxHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         maxHeap.push(arr[i]);
//     }
//     for (int i = 0; i < k; i++)
//     {
//         cout << maxHeap.top() << " ";
//         maxHeap.pop();
//     }
//     cout << endl;
//     return;
// }
// // rather use a minheap to solve this question

// // Write a program to sort a k sorted array
// // approach1: the first approach will be to use insertion sort to solve this question

// // approach2: the second approach will be to use the minHeaps to solve this question
// vector<int> sortKSorted(vector<int> arr, int k)
// {
//     // step1: fill the heap with the first k elemenst
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     for (int i = 0; i <= k; i++)
//     {
//         minHeap.push(arr[i]);
//     }
//     vector<int> ans;
//     for (int i = k + 1; i < arr.size(); i++)
//     {
//         ans.push_back(minHeap.top());
//         minHeap.pop();
//         minHeap.push(arr[i]);
//     }
//     while (!minHeap.empty())
//     {
//         ans.push_back(minHeap.top());
//         minHeap.pop();
//     }
//     return ans;
// }
// // The time complexity of this solution will be O(nlogk)

// class solution
// {
// public:
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     int median = -1;
//     int signum()
//     {
//         return maxHeap.size() - minHeap.size();
//     }

//     void insert(int val)
//     {
//         switch (signum())
//         {
//         case 0:
//             maxHeap.push(val);
//             median = val;
//             break;
//         case 1:
//             if (val > median)
//             {
//                 minHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             else
//             {
//                 minHeap.push(maxHeap.top());
//                 maxHeap.pop();
//                 maxHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             break;
//         case -1:
//             if (val < median)
//             {
//                 maxHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             else
//             {
//                 maxHeap.push(minHeap.top());
//                 minHeap.pop();
//                 minHeap.push(val);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             break;
//         }
//     }

//     int getMedian()
//     {
//         return median;
//     }

//     int size()
//     {
//         return maxHeap.size() + minHeap.size();
//     }
// };

// Write a program to merge the k sorted lists
// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// class compare
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->data > b->data;
//     }
// };

// vector<int> mergeKSorted(vector<Node *> arr)
// {
//     priority_queue<Node *, vector<Node *>, compare> minHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push(arr[i]);
//     }

//     vector<int> ans;
//     while (!minHeap.empty())
//     {
//         Node *temp = minHeap.top();
//         minHeap.pop();
//         ans.push_back(temp->data);
//         if (temp->next)
//         {
//             minHeap.push(temp->next);
//         }
//     }
//     return ans;
// }

// We implement the priority queue data structure using heaps
// we can also implement them using hte linked list but the total time complexity for adding or removing becomes O(n^2) in case of linked lists which is not a good implementation of the concept

// implementation of priority queue using heaps
/*
step1 : build a heap from the given array
*/

// Binary tree is a complete binary tree
// we implement it in the form of an array
// all the levels  are completely filled until the second last level
// the last level is filled from left to right
// All binary heap is either min-heap or max-heap

// Working with the binary heap implementation

class minHeap
{
public:
    int *arr;
    int size;
    int capacity;
    minHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
};

// While implementing an insertion into a heap remember the two stop conditions
// the parent node is smaller than the child node
// the current node is at the root node

class minHeap
{
public:
    int *arr;
    int size;
    int capacity;
    minHeap(int c)
    {
        arr = new int[100];
        size = 0;
        capacity = 100; // assuming the value of c is given to be 100 // replace 100 with c in running code implementation
    }

    // there are only 2 stopping conditions while inserting a node into a minHeap
    // first one is that the parent node data is smaller than the child node data
    // second condition is that the current node is at the root node . i.e. it can't have any parent
    // The time complexity of insertion into a minHeap is O(logn)

    void insert(int data)
    {
        if (size >= capacity)
        {
            cout << "heap overflow" << endl;
            return;
        }
        else
        {
            int index = size;
            size++;
            arr[index] = data;
            // implementing the second condition
            while (index > 0)
            {
                int parent = (index - 1) / 2;
                if (arr[parent] > arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                // implementing the first condition
                else
                {
                    return;
                }
            }
        }
    }

    // implementing the get min function
    int getMin()
    {
        if (size <= 0)
        {
            cout << "heap underflow" << endl;
            return;
        }
        return arr[0];
    }
    // the time complexity of this function is O(1)

    // implementing the extract min function
    /*
    step1 : swap the last element with the first element
    step2 : delete the last element
    step3 : prioritise down the first element of the array i.e. the last element which is taken up or you can simply implement the heapify function on index 0 of the heap
    */
    int extractMin()
    {
        if (size <= 0)
        {
            cout << "heap underflow" << endl;
            return;
        }
        else
        {
            int min = arr[0];
            arr[0] = arr[size - 1];
            size--;
            // heapify(arr, size, 0);
            // or implementing the same code here
            int index = 0;
            while (index < size)
            {
                int leftChild = (2 * index + 1);
                int rightChild = (2 * index + 2);
                int smallest = index;
                if (leftChild < size && arr[leftChild] < arr[smallest])
                {
                    smallest = leftChild;
                }
                if (rightChild < size && arr[rightChild] < arr[smallest])
                {
                    smallest = rightChild;
                }
                if (smallest != index)
                {
                    swap(arr[smallest], arr[index]);
                    index = smallest;
                }
                else
                {
                    return min;
                }
            }
            return min;
        }
    }
    // The time complexity of extractMin function is O(logn)

    // implementing the decrease key function
    void decreaseKey(int index, int data)
    {
        if (index < 0 || index >= size)
        {
            cout << "index out of range" << endl;
            return;
        }
        else
        {
            arr[index] = data;
            // as the data is decreased and it is a minheap the node now has the chance to be bubbled up
            // this also follows the conditions of insertion of a new node into the heap
            // implementing the second condition
            while (index > 0)
            {
                int parent = (index - 1) / 2;
                if (arr[parent] > arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                // implementing the frst condition
                else
                {
                    return;
                }
            }
        }
    }

    // Write the delete key function which delete a node at a particular index
    /*
    There are 2 steps to solve this question:
    step1 : put the INT_MIN value at the given node index so that it bubbles up to the top of the heap
    step2 : use the extractMin function so that the first or the minimum element is popped out from the heap
    The time complexity of this solution is O(logn)
    */
    void deleteKey(int index)
    {
        decreaseKey(index, INT_MIN);
        extractMin();
    }
};

// Implement the heapfiy algorithm to build a minheap
// heapify algorithm is used to fix the single violating node in a minheap
// heapify is an inbuild operation used in many processes

// we assume that all the elements after the given index are alreay in the correct order of minHeap
void heapify(int *arr, int size, int index)
{
    if (index >= size)
    {
        return;
    }
    else
    {
        int leftChild = (2 * index + 1);
        int rightChild = (2 * index + 2);
        int smallest = index;
        if (leftChild < size && arr[leftChild] < arr[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < size && arr[rightChild] < arr[smallest])
        {
            smallest = rightChild;
        }
        if (smallest != index)
        {
            swap(arr[smallest], arr[index]);
            heapify(arr, size, smallest);
        }
        else
        {
            return;
        }
    }
}

// Write a function to build a minHeap from a given random array
/*
we assume that the single nodes are already a minheap
i.e. the leaf nodes of the heap are already implementing the concept of minHeap
so we  find the first node from the last which is a parent i.e. it has some childrens
the formula to find that parent is n/2 - 1 : this formula is coming from the concept that  we are calculating the parent of the last node using the formula (i-1)/2 where i is the index of the last node of the complete binary tree and here i = n-1
so putting the value of i = n-1 in the formula
i-1/2 => ((n-1)-1)/2 => (n-2)/2 => n/2 - 1

Incorrect : The time complexity of this solution is (nlogn)
Correct : The time complexity of this solution is O(n). There are many theories to prove this. Don't go to the detail.
so the time complexity to implement the build heap function is O(n).
Remember it . It is important!
*/
void buildHeap(vector<int> arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// ------------------------------------------------------------------------------------------------------------------------

// Working with the logic of heap sort
/*
Heap sort is based on the concept of selection sort
// The time complexity to implement the selection sort algorithm on an array is O(n^2)
steps to implement the heap sort algorithm:
step1 : build a max Heap from the given array

*/

void maxHeapify(vector<int> &arr, int size, int index)
{
    if (index >= size)
    {
        cout << "Index out of range" << endl;
        return;
    }
    else
    {
        int leftChild = (2 * index + 1);
        int rightChild = (2 * index + 2);
        int largest = index;
        if (leftChild < size && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }
        if (rightChild < size && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            maxHeapify(arr, size, largest);
        }
        else
        {
            return;
        }
    }
}

void buildHeap(vector<int> arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, size, i);
    }
}

// Implementing the heap sort algorithm
// step1 : build the max heap  from the given array
// step2 : traverse the array from the last and put the largest element at the last block of array reduce the size by 1 and call the maxHeapify function for the index 0 and passing the reduced size.

void heapSort(vector<int> arr, int size)
{
    buildHeap(arr, size);               // Time complexity : O(n)
    for (int i = size - 1; i >= 0; i--) // Time complexity : O(nlogn)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}
// Time complexity of this solution is O(nlogn) whereas the time complexity of selection sort is O(n^2)

// ----------------------------------------------------------------------------------------------------------------------

/*
Working with the priority queue
priority queue is a data structure which is implemented using heap data structure
priority queue implements max heap by default
*/

// int main()
// {
//     return 0;
// }

/*
 */

// Implementing priority queue with maximum at top i.e. a max heap
// #include <iostream>

// using namespace std;

// int main()
// {
//     priority_queue<int> pq;
//     pq.push(10);
//     pq.push(15);
//     pq.push(5);
//     cout << pq.size() << endl;
//     cout << pq.top() << endl;
//     while (!pq.empty())
//     {
//         cout << pq.top() << " "; // This will print all the inserted elements in descending order
//         pq.pop();
//     }
// }

// Implementing priority queue with minimum at top i.e. a min heap
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     minHeap.push(10);
//     minHeap.push(15);
//     minHeap.push(5);
//     cout << minHeap.size() << endl;
//     cout << minHeap.top() << endl;

//     while (!minHeap.empty())
//     {
//         cout << minHeap.top() << " "; // This will print all the inserted elements in ascending order
//         minHeap.pop();
//     }
// }

// Implementing a priority  queue from an existing array
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int arr[] = {15, 10, 20};
// //  This will take O(n) time to build heap from array
//     priority_queue<int> pq(arr, arr + 3);       // here 3 is the size or the number of elements present in the array
//     while (!pq.empty())
//     {
//         cout << pq.top() << " "; // This will print all the array elements in descending order
//         pq.pop();
//     }
//     cout << endl;
// }

// Implementing a priority queue from an existing vector
// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     vector<int> vec = {15, 10, 20};
//     priority_queue<int> pq(vec.begin(), vec.end());
// }

// The push and the pop method in priority queue takes O(logn) time to implement
// The empty , size and the top method in priority queue takes O(1) time to implement

// the above code implements only for maxHeap
// to implement the above code for minHeap you can multiply all the elements of the array or the vector with -1 and then push them into the minHeap and while using the elements you can again switch the sign of the top or the popped element from the minHeap

// priority queue is also a container
// by default c++ creates a maxHeap for the priority queue

// Implement heap sort
// step1 : build maxHeap
// step2 : traverse the array from end to front and place the maximum element at the end and reduce the size by 1 and correspondingly call the maxHeapify function for the 0th index and reduced size array

// void maxHeapify(vector<int> &arr, int size, int i)
// {
//     if (i >= size)
//     {
//         return;
//     }
//     else
//     {
//         int leftChild = (2 * i) + 1;
//         int rightChild = (2 * i) + 2;
//         int largest = i;
//         if (leftChild < size && arr[leftChild] > arr[largest])
//         {
//             largest = leftChild;
//         }
//         if (rightChild < size && arr[rightChild] > arr[largest])
//         {
//             largest = rightChild;
//         }
//         if (largest != i)
//         {
//             swap(arr[largest], arr[i]);
//             maxHeapify(arr, size, largest);
//         }
//         else
//         {
//             return;
//         }
//     }
// }

// void BuildHeap(vector<int> &arr, int size)
// {
//     for (int i = size / 2 - 1; i >= 0; i--)
//     {
//         maxHeapify(arr, size, i);
//     }
// }

// void heapSort(vector<int> &arr)
// {
//     BuildHeap(arr, arr.size());
//     for (int i = arr.size() - 1; i >= 0; i--)
//     {
//         swap(arr[i], arr[0]);
//         maxHeapify(arr, i, 0);
//     }
// }

// write a program to find the kth largest element in an array
// int kthLargest(vector<int> arr, int size, int k)
// {
//     // priority_queue<int, vector<int>, greater<int>> minHeap;
//     // for (int i = 0; i < size; i++)
//     // {
//     //     minHeap.push(arr[i]);
//     //     if (minHeap.size() > k)
//     //     {
//     //         minHeap.pop();
//     //     }
//     // }
//     // return minHeap.top();

//     // let's do it in O(n) time complexity
//     priority_queue<int> maxHeap(arr.begin(), arr.end()); // Time complexity : O(n) to build the heap
//     for (int i = 1; i < k; i++)                          // Time complexity : O(klogn)
//     {
//         maxHeap.pop();
//     }
//     return maxHeap.top();
//     // so the overall time complexity becomes O(n).
// }

// Write a program to find the kth largest element in a given array stream after inserting elemnts
// int insert(vector<int> arr, priority_queue<int, vector<int>, greater<int>> &minHeap, int element, int k)
// {
//     arr.push_back(element);
//     if (element > minHeap.top() || minHeap.size() < k)
//     {
//         if (minHeap.size() == k)
//             minHeap.pop();
//         minHeap.push(element);
//     }
//     return minHeap.top();
// }

// Write a program to print top k frequent elements
// vector<int> kTopFrequent(vector<int> arr, int k)
// {
//     unordered_map<int, int> map;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         map[arr[i]]++;
//     }
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//     for (auto i : map)
//     {
//         minHeap.push(make_pair(i.second, i.first));
//         if (minHeap.size() > k)
//         {
//             minHeap.pop();
//         }
//     }
//     vector<int> ans;
//     while (!minHeap.empty())
//     {
//         pair<int, int> temp = minHeap.top();
//         minHeap.pop();
//         ans.push_back(temp.second);
//     }
//     return ans;
// }

// Write a program to find the minimum cost of ropes
// int minimumCost(vector<int> arr)
// {
//     // priority_queue<int, vector<int>, greater<int>> minHeap;
//     // for (int i = 0; i < arr.size(); i++) // time complexity O(n) : build heap time complexity
//     // {
//     //     minHeap.push(arr[i]);
//     // }

//     priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
//     int cost = 0;
//     while (minHeap.size() > 1) // time complexity O(nlogn)
//     {
//         int a = minHeap.top();
//         minHeap.pop();
//         int b = minHeap.top();
//         minHeap.pop();
//         int sum = a + b;
//         cost += sum;
//         minHeap.push(sum);
//     }
//     return cost;
// }
// The time complexity of this solution comes  out to be O(nlogn)

// Write a program to find the top k closest elements to the given element x
#include <algorithm>
#include <bits/stdc++.h>
int absolute(int x)
{
    if (x < 0)
    {
        return -1 * x;
    }
    else
    {
        return x;
    }
}
vector<int> kClosestElements(vector<int> arr, int size, int x, int k)
{
    priority_queue<pair<int, int>> maxHeap;
    for (int i = 0; i < size; i++)
    {
        maxHeap.push(make_pair(absolute(arr[i] - x), arr[i]));
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    vector<int> ans;
    while (!maxHeap.empty())
    {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
// you could also have done the above question using minHeap

// Write a program to merge k sorted arrays
// the first approach will be to put all the elements in a resulting array and then sort the resulting array
// the time complexity of that solution will be O(nk log (nk))

// The second approach will be to use the heap concept
// class node
// {
// public:
//     int data;
//     int i;
//     int j;
// };

// class compare
// {
// public:
//     bool operator()(node a, node b)
//     {
//         return a.data > b.data;
//     }
// };

// vector<int> mergeKArrays(vector<vector<int>> arr, int k)
// {
//     priority_queue<node, vector<node>, compare> minHeap;
//     for (int i = 0; i < k; i++)
//     {
//         node temp;
//         temp.data = arr[i][0];
//         temp.i = i;
//         temp.j = 0;
//         minHeap.push(temp);
//     }
//     vector<int> ans;
//     while (!minHeap.empty())
//     {
//         node temp = minHeap.top();
//         minHeap.pop();
//         ans.push_back(temp.data);
//         if (temp.j + 1 < arr[temp.i].size())
//         {
//             node n;
//             n.data = arr[temp.i][temp.j + 1];
//             n.i = temp.i;
//             n.j = temp.j + 1;
//             minHeap.push(n);
//         }
//     }
//     return ans;
// }

// Write a program to find the median in a stream
// the median in a stream is the middle element of the stream
// class solution
// {
// public:
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     int median;

//     int signum()
//     {
//         return maxHeap.size() - minHeap.size();
//     }

//     void insert(int key)
//     {
//         switch (signum())
//         {
//         case 0:
//             maxHeap.push(key);
//             median = key;
//             break;
//         case 1:
//             if (key > median)
//             {
//                 minHeap.push(key);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             else
//             {
//                 minHeap.push(maxHeap.top());
//                 maxHeap.pop();
//                 maxHeap.push(key);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             break;
//         case -1:
//             if (key < median)
//             {
//                 maxHeap.push(key);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             else
//             {
//                 maxHeap.push(minHeap.top());
//                 minHeap.pop();
//                 minHeap.push(key);
//                 median = (minHeap.top() + maxHeap.top()) / 2;
//             }
//             break;
//         default:
//             return;
//         }
//     }

//     int getSize()
//     {
//         return minHeap.size() + maxHeap.size();
//     }

//     int getMedian()
//     {
//         if (getSize() == 0)
//         {
//             return -1;
//         }
//         else
//         {
//             return median;
//         }
//     }
// };

// ------------------------------------------------------------------------------------------------------------------
// write a program to implement a minheap using arrays
// #include <algorithm>
// #include <bits/stdc++.h>
// class minHeap
// {
// public:
//     int arr[100];
//     int capacity;
//     int size;
//     minHeap()
//     {
//         capacity = 100;
//         size = 0;
//     }

//     // there are 2 braeking conditions for implementing the insert functionalify in a heap
//     // 1. the parent node data is already smaller than the child node data
//     // 2. the current node is the root node
//     // The time complexity of insertion in a minHeap is O(logn)
//     void insert(int val)
//     {
//         if (size >= capacity)
//         {
//             cout << "heap overflow" << endl;
//             return;
//         }
//         else
//         {
//             int index = size;
//             size++;
//             arr[index] = val;
//             // implementing the second condition
//             while (index > 0)
//             {
//                 int parent = (index - 1) / 2;
//                 if (arr[parent] > arr[index])
//                 {
//                     swap(arr[parent], arr[index]);
//                     index = parent;
//                 }
//                 // implementing the first condition
//                 else
//                 {
//                     return;
//                 }
//             }
//         }
//     }

//     int getMin()
//     {
//         if (size <= 0)
//         {
//             return -1;
//         }
//         else
//         {
//             return arr[0];
//         }
//     }

//     // there are 3 steps for implementing the extract min functionality
//     // 1. swap the element at index 0 with the last element
//     // 2. decrease the size of the heap by 1
//     // 3. prioritise down the resulting element at 0 index
//     // The time complexity of removing the top element from the minHeap is O(logn)
//     int extractMin()
//     {
//         if (size <= 0)
//         {
//             cout << "heap underflow" << endl;
//             return;
//         }
//         else
//         {
//             int minimum = arr[0];
//             arr[0] = arr[size - 1];
//             size--;
//             int index = 0;
//             while (index < size)
//             {
//                 int leftChild = (2 * index + 1);
//                 int rightChild = (2 * index + 2);
//                 int temp = index;
//                 if (leftChild < size && arr[leftChild] < arr[temp])
//                 {
//                     temp = leftChild;
//                 }
//                 if (rightChild < size && arr[rightChild] < arr[temp])
//                 {
//                     temp = rightChild;
//                 }
//                 if (temp != index)
//                 {
//                     swap(arr[temp], arr[index]);
//                     index = temp;
//                 }
//                 else
//                 {
//                     return minimum;
//                 }
//             }
//             return minimum;
//         }
//     }

//     void decreaseElement(int index, int data)
//     {
//         if (index < 0 or index >= size)
//         {
//             cout << "Index out of range" << endl;
//             return;
//         }
//         else
//         {
//             arr[index] = data;
//             // Now this data has to be bubbled up right
//             // this is also implemented using the insertion algo
//             // implementing the second condition
//             while (index > 0)
//             {
//                 int parent = (index - 1) / 2;
//                 if (arr[parent] > arr[index])
//                 {
//                     swap(arr[parent], arr[index]);
//                     index = parent;
//                 }
//                 // implementing the first condition
//                 else
//                 {
//                     return;
//                 }
//             }
//         }
//     }

//     // implementing the delete element from the minheap
//     // this operation performs two operations
//     // 1. decrease the element at the given index to the most minimum value
//     // 2. remove the top element from the heap which if shuffled after decrementing the value of the given index element
//     void deleteElement(int index)
//     {
//         if (index < 0 or index >= size)
//         {
//             cout << "Invalid index" << endl;
//             return;
//         }
//         else
//         {
//             decreaseElement(index, INT_MIN);
//             extractMin();
//         }
//     }
// };

// void minHeapify(vector<int> &arr, int size, int index)
// {
//     if (index >= size)
//     {
//         return;
//     }
//     else
//     {
//         int leftChild = (2 * index + 1);
//         int rightChild = (2 * index + 2);
//         int smallest = index;
//         if (leftChild < size && arr[leftChild] < arr[smallest])
//         {
//             smallest = leftChild;
//         }
//         if (rightChild < size && arr[rightChild] < arr[smallest])
//         {
//             smallest = rightChild;
//         }
//         if (smallest != index)
//         {
//             swap(arr[smallest], arr[index]);
//             minHeapify(arr, size, smallest);
//         }
//     }
// }

// void buildHeap(vector<int> &arr)
// {
//     for (int i = (arr.size() / 2 - 1); i >= 0; i--)
//     {
//         minHeapify(arr, arr.size(), i);
//     }
// }

// -------------------------------------------------------------------------------------------------------------------------

// Write a program to find the kth largest value in a given array
// the first approach to solve this problem will be to sort the array : Time complexity : O(nlogn) + O(k)
// int kthLargest(vector<int> &arr, int k)
// {
//     // priority_queue<int, vector<int>, greater<int>> minHeap;
//     // for (int i = 0; i < arr.size(); i++)
//     // {
//     //     minHeap.push(arr[i]);
//     //     if (minHeap.size() > k)
//     //     {
//     //         minHeap.pop();
//     //     }
//     // }
//     // return minHeap.top();

//     // // The time complexity of this solution is O(klogk) + O((n-k)logk)
// }

// find teh kth largest in stream of numbers
// int getKthLargest(priority_queue<int, vector<int>, greater<int>> &minHeap, int element, int k)
// {
//     if (minHeap.size() < k)
//     {
//         minHeap.push(element);
//         if (minHeap.size() == k)
//         {
//             return minHeap.top();
//         }
//         else
//         {
//             return -1;
//         }
//     }
//     else
//     {
//         if (element > minHeap.top())
//         {
//             minHeap.pop();
//             minHeap.push(element);
//         }
//     }
//     return minHeap.top();
//     // The time complexity of this solution is O(klogk) + O((n-k)log(k)). for the whole stream
//     // for adding a single element the time complexity of this solution is O(logk).
// }

// Write a program to find the kth smallest element in the given array

// Write a program to find the kth smallest element in a given stream
// int kthSmallestInStream(priority_queue<int> &maxHeap, int element, int k)
// {
//     if (maxHeap.size() < k)
//     {
//         maxHeap.push(element);
//         return maxHeap.size() == k ? maxHeap.top() : -1;
//     }
//     else
//     {
//         if (element < maxHeap.top())
//         {
//             maxHeap.pop();
//             maxHeap.push(element);
//         }
//         return maxHeap.top();
//     }

//     // The time complexity of this solution is O(logk).
// }

// Write a program to get the top k largest element in a given array
// vector<int> kLargest(vector<int> &arr, int k)
// {
//     priority_queue<int> maxHeap;

//     // step1 : fill elements in the max heap : TC: O(n)
//     for (int i = 0; i < arr.size(); i++)
//     {
//         maxHeap.push(arr[i]);
//     }

//     vector<int> ans;
//     // step2 : fill the first k elements of the heap into the array
//     for (int i = 0; i < k; i++)
//     {
//         ans.push_back(maxHeap.top());
//         maxHeap.pop();
//     }
//     return ans;
// }

// vector<int> kLargest(vector<int> &arr, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push(arr[i]);
//         if (minHeap.size() > k)
//         {
//             minHeap.pop();
//         }
//     }
//     vector<int> ans;
//     while (!minHeap.empty())
//     {
//         ans.push_back(minHeap.top());
//         minHeap.pop();
//     }
//     return ans;
//     // The space complexity of this solution is O(k)
//     // The time complexity of this solution is O(klogk) + O((n-k)logk)
// }

// Write a program to implement the heap sort algorithm

/*
there are 2 steps required to implement the heap sort algorithm
step1 : build the maxHeap from the given array
step2 : traverse the array from the back to the front and place the largest element from the heap to the last index and accordingly maxHeapify the 0th index and the reduced size heap/array.
*/

// void maxHeapify(vector<int> &arr, int size, int index)
// {
//     if (index >= size)
//     {
//         return;
//     }
//     else
//     {
//         int leftChild = (2 * index + 1);
//         int rightChild = (2 * index + 2);
//         int largest = index;
//         if (leftChild < size && arr[leftChild] > arr[largest])
//         {
//             largest = leftChild;
//         }
//         if (rightChild < size && arr[rightChild] > arr[largest])
//         {
//             largest = rightChild;
//         }
//         if (largest != index)
//         {
//             swap(arr[largest], arr[index]);
//             maxHeapify(arr, size, largest);
//         }
//     }
// }

// void BuildHeap(vector<int> &arr, int size)
// {
//     for (int i = (size / 2 - 1); i >= 0; i--)
//     {
//         maxHeapify(arr, size, i);
//     }
// }

// // heap sort is based on the concept of selection sort
// void heapSort(vector<int> &arr)
// {
//     buildHeap(arr, arr.size());
//     for (int i = arr.size() - 1; i >= 0; i--)
//     {
//         swap(arr[0], arr[i]);
//         maxHeapify(arr, i, 0);
//     }
// }

// Write a program to find the top k frequent numbers in the given array

// Write a program for frequency sorting i.e. sort the elements as per frequency
// vector<char> frequencySort(vector<char> &arr)
// {
//     // step1 : place all the elements in a map and count the frequency of all the characters
//     unordered_map<char, int> map;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         map[arr[i]]++;
//     }
//     priority_queue<pair<int, char>> maxHeap;

//     // step2: palce all the entries of the map into a maxHeap according to their frequencies
//     for (auto i : map)
//     {
//         maxHeap.push(make_pair(i.second, i.first));
//     }

//     // step3: place all the characters into the ans array according to the frequency of the characters i.e. the priority order
//     vector<char> ans;
//     while (!maxHeap.empty())
//     {
//         pair<int, char> temp = maxHeap.top();
//         maxHeap.pop();
//         while (temp.first)
//         {
//             ans.push_back(temp.second);
//             temp.first--;
//         }
//     }
//     return ans;
// }

// Write a program to print the k closest elements near to the origin
// the elemnts lie in a 2D plane
// vector<pair<int, int>> kClosestToOrigin(vector<pair<int, int>> &arr, int k)
// {
//     priority_queue<pair<int, pair<int, int>>> maxHeap;
//     for (auto i : arr)
//     {
//         maxHeap.push(make_pair(i.first * i.first + i.second * i.second, make_pair(i.first, i.second)));
//         if (maxHeap.size() > k)
//         {
//             maxHeap.pop();
//         }
//     }

//     vector<pair<int, int>> ans;
//     while (!maxHeap.empty())
//     {
//         ans.push_back(maxHeap.top().second);
//         maxHeap.pop();
//     }
//     return ans;
// }

// Write a program to connect two ropes using minimum cost
// The first appraoch will be to sort the given array and add the first two elements of the array and push the result into the array and sort the array again until the total number of elements in the array becomes equal to 1
// The time complexity of this solution is O(n^2 logn)

// The second approach will be to use a minHeap to solve this question
// int minimumCost(vector<int> &arr, int size)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     for (int i = 0; i < size; i++)
//     {
//         minHeap.push(arr[i]);
//     }

//     int cost = 0;
//     while (minHeap.size() > 1)
//     {
//         int a = minHeap.top();
//         minHeap.pop();
//         int b = minHeap.top();
//         minHeap.pop();
//         int sum = a + b;
//         cost += sum;
//         minHeap.push(sum);
//     }
//     return cost;
// }
// The time complexity of this solution is O(nlogn)
// The space complexity of this solution is O(n) as we are using a heap

// Write a program to sort characters by frequency
// vector<char> sortFrequency(vector<char> &arr)
// {
//     unordered_map<char, int> map;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         map[arr[i]]++;
//     }

//     priority_queue<pair<int, char>> maxHeap;
//     for (auto i : map)
//     {
//         maxHeap.push(make_pair(i.second, i.first));
//     }

//     vector<char> ans;
//     while (!maxHeap.empty())
//     {
//         pair<int, char> temp = maxHeap.top();
//         maxHeap.pop();
//         ans.push_back(temp.second);
//     }
//     return ans;
// }

// Write a program to return the k closest points to origin
// vector<pair<int, int>> kClosestToOrigin(vector<pair<int, int>> &arr, int k)
// {
//     priority_queue<pair<int, pair<int, int>>> maxHeap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         maxHeap.push(make_pair(arr[i].first * arr[i].first + arr[i].second * arr[i].second, make_pair(arr[i].first, arr[i].second)));
//         if (maxHeap.size() > k)
//         {
//             maxHeap.pop();
//         }
//     }

//     vector<pair<int, int>> ans;
//     while (!maxHeap.empty())
//     {
//         ans.push_back(maxHeap.top().second);
//         maxHeap.pop();
//     }
//     return ans;
// }

// Write a program to print the top k frequent elements
// vector<int> topKFrequent(vector<int> &arr, int k)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//     unordered_map<int, int> map;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         map[arr[i]]++;
//     }

//     for (auto i : map)
//     {
//         minHeap.push(make_pair(i.second, i.first));
//         if (minHeap.size() > k)
//         {
//             minHeap.pop();
//         }
//     }

//     vector<int> ans;
//     while (!minHeap.empty())
//     {
//         ans.push_back(minHeap.top().second);
//         minHeap.pop();
//     }
//     return ans;

//     // this is just a demo to show you the implementation of the lambda function in c++ okey vishal sharma
//     auto compare = [](int x, int y)
//     {
//         return x > y;
//     };
// }
