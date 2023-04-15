// finding the sum of array elements using recursion
#include<iostream>

using namespace std;

int findSum(int arr[],int n)
{
    if(n==0) return 0;
    return arr[n-1] + findSum(arr,n-1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    cout<<"The sum of all the elements of the array is "<<findSum(arr,5)<<endl;
    return 0;
}