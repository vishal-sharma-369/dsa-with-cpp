// finding the number occuring odd number of times in an array
#include<iostream>
#include<map>

using namespace std;


// Using the brute force approach
int findOdd(int arr[],int n)
{
    if(n&1)return -1;
    for(int i = 0;i<n;i++)
    {
        int count = 1;
        if(arr[i]<0)
        {continue;}
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] == arr[i])
            {
                count++;
                arr[j] = -1;
            }
        }
        if(count&1)
        {
            return arr[i];
        }
        arr[i] = -1;
    }
}


// A better solution would be to use hashing
int findOddUsingHashing(int arr[],int n)
{
    if(n&1)return -1;
    map<int,int> counter;
    for(int i = 0;i<n;i++)
    {
        counter[arr[i]]++;
    }
    for(auto i:counter)
    {
        if(i.second&1)
        {
            return i.first;
        }
    }
    return -1;
}

// The best solution would be to use the xor operator on all the elements of the array
int findOddUsingXorOperation(int arr[],int n)
{
    int xoor = 0;
    for(int i = 0;i<n;i++)
    {
        xoor = xoor ^ arr[i];
    }
    return xoor;
}


int amin()
{
    return 0;
}