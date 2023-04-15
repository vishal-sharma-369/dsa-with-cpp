#include<iostream>

using namespace std;

int calculateMaximumElement(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        int count = 1;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] == arr[i])
            {
                count++;
                if(count>n/2)
                {
                    return arr[i];
                }
            }
        }   
    }
    return -1;
}

// using optimized solution technique
int calculatingMaximumElement(int arr[], int n)
{
    // first phase of moores voting algorithm
    int count = 1;
    int element = arr[0];
    for(int i = 1;i<n;i++)
    {
        if(arr[i]==element)
        {
            count++;
        }
        else
        {
            count--;
            if(count<0)
            {
                element = arr[i];
                count = 1;
            }
        }
    }

    // second phase of moores voting algorithm
    count = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == element)
        {
            count++;
        }
    }
    if(count>n/2)
    return element;
    else
    return -1;
}


// This question can also be solved using the binary search tree approach but i have not studied it yet you can see it later on on geeks for geeks youtube channel


int main()
{
    return 0;
}