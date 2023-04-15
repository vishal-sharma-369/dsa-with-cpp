// finding the fixed point in an sorted array of ascending integers if present otherwise return -1
#include<iostream>

using namespace std;

// Using the brute force approach or the linear search 
int findFixedPoint(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==i)return i;
    }
    return -1;
}


// Using the binary search approach
int findFixedPointUsingBinarySearch(int arr[],int n)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] == mid)return arr[mid];
        else if(arr[mid] < mid)start = mid + 1;
        else end = mid-1;
    }
}


int main()
{
    return 0;
}