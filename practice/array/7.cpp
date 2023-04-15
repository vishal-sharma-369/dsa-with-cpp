// replacing all the elements with the greatest element on the right side
#include<iostream>

using namespace std;

// Using the brute force solution to solve the problem with the time complexity of O(n^2) and space complexity of O(1)
void replacer(int arr[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int maximum = arr[i+1];
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] > maximum)
            {
                maximum = arr[j];
            }
        }
        arr[i] = maximum;
    }
    arr[n-1] = -1;
}


// using the best approach to solve this problem in a time complexity of O(n) and a space complexity of O(1)
void bestReplacer(int arr[],int n)
{
    int maximum = -1;
    for(int i = n-1;i>=0;i--)
    {
        if(arr[i] > maximum)
        {
            int temp = arr[i];
            arr[i] = maximum;
            maximum = temp;
        }
        else
        {
            arr[i] = maximum;
        }
    }
}

int main()
{
    return 0;
}