// finding the missing element in the array

#include<iostream>
using namespace std;

long long nSum(int n)
{
    long long sum = 0;
    for(int i = 1;i<=n;i++)
    {
        sum+= i;
    }
    return sum;
}

long long aSum(int arr[],int n)
{
    long long sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
    }
    return sum;
}

// using the xor method
int xorsolution(int arr[],int n)
{
    int xoor = 0;
    for(int i = 1;i<=n+1;i++)
    {
        xoor = xoor ^ i;
    }
    for(int i = 0;i<n;i++)
    {
        xoor = xoor ^ arr[i];
    }
    return xoor;
}

int missingElement(int arr[],int n)
{
    int nsum = nSum(n);
    int asum = aSum(arr,n);
    return nsum- asum;
}

int main()
{
    return 0;
}