// Today we are going to learn about binary search
// Conditions: the array should be either in ascending order or in descending order

#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        // int mid = (start + end) / 2;            This formula will only work if the value of start and end are very small . What if the values of start and end are very large like 2^31-1 both , in that case this formula will fail . so the new formula becomes
        int mid = start + (end - start)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int n;
    cout<<"Enter the key to search for in the array"<<endl;
    cin>>n;

    int ans = binarySearch(arr,9,n);
    if(ans == -1)
    {
        cout<<"The key was not found in the array"<<endl;
    }
    else
    {
        cout<<"The key "<<n<<" was found in the array at index "<<ans<<endl;
    }
    return 0;
}


// The time complexity of the binary search algorithm is O(logn)
// n/2^k = 1;
// so at the end the value of k comes out to be equal to Logn with the base of 2