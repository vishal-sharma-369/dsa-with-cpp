// In this lecture we are going to study about Selection sort
#include<iostream>

using namespace std;

void selectionSort(int arr[],int size)
{
    for(int i = 0;i<size-1;i++)
    {
        int min = i;
        for(int j = i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }

        // It will also run without using the if condition and simply swappping the arr[min] with arr[i]

        if(min!=i)
        {
            swap(arr[i],arr[min]);
        }
    }
    return;
}

void printArray(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[10] = {1,4,5,7,9,2,3,0,2,4};
    cout<<"The original array is "<<endl;
    printArray(arr,10);
    selectionSort(arr,10);
    cout<<"The array after applying selection sort is "<<endl;
    printArray(arr,10);
    return 0;
}




// The space complexity of selection sort is O(1)
// The time complexity of selection sort is O(n^2)
// Best case complexity : O(n^2)
// Worst case complexity : O(n^2)
// Used when the size of the array is small because it is space efficient(memory constraints)


// Homework:
// Check whether it is a stable algo or unstable algo
// Make the flow chart of selection sort algo