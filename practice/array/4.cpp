// finding the leaders in an array
#include<iostream>

using namespace std;

int countLeaders(int arr[],int n)
{
    int count = 0;
    int maxElement = INT32_MIN;
    for(int i = n-1;i>=0;i++)
    {
        if(arr[i] >= maxElement)
        {
            maxElement = arr[i];
            count++;
        }
    }
    return count;
}

int countLeadersUsingAuxiliarySpace(int arr[],int n)
{
    int *temp = new int[n];
    int maxElement = INT32_MIN;
    for(int i = n-1;i>=0;i++)
    {
        if(arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
        temp[i] = maxElement;
    }

    int count = 0;

    for(int i = 0;i<n;i++)
    {
        if(arr[i] >= temp[i])
        {
            count++;
        }
    }
    return count;
}


// Using the bruteforce approach
int findtheleader(int arr[],int n)
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        bool leader = true;
        for(int j = i+1;j<n;j++)
        {
            if(arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if(leader) count++;
    }
    return count;
}

int main()
{
    return 0;
}