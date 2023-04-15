// finding the peak element in an array
#include<iostream>
#include<vector>

using namespace std;

// Using the brute force approach by checking each and every element
vector<int> findPeaksest(int arr[],int n)
{
    vector<int> ans;
    for(int i = 0;i<n;i++)
    {
        bool ispeak = true;
        for(int j = i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                ispeak = false;
            }
        }
        for(int j = i-1;j>=0;j--)
        {
            if(arr[i]<arr[j])
            {
                ispeak = false;
            }
        }
        if(ispeak)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}




// Using the array preprocessing method
vector<int> findPeakest(int arr[],int n)
{
    vector<int> ans;
    int *lmax = new int[n];
    int *rmax = new int[n];
    int maximum = arr[0];
    for(int i = 0;i<n;i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }
        lmax[i] = maximum;
    }

    maximum = arr[n-1];
    for(int i = n-1;i>=0;i--)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }
        rmax[i] = maximum;
    }

    for(int i = 0;i<n;i++)
    {
        bool isPeak = true;
        if(arr[i] < lmax[i])
        {
            isPeak = false;
        }
        if(arr[i] < rmax[i])
        {
            isPeak = false;
        }
        if(isPeak) ans.push_back(arr[i]);
    }
    return ans;
}




// finding any single peak element in the array
// using the brute force approach with the time complexity of O(n) and space complexity of O(1)
int findPeak(int arr[],int n)
{
    if(n==1)return arr[0];
    for(int i = 0;i<n;i++)
    {
        bool isPeak = true;
        if(i-1 >= 0 && arr[i-1] > arr[i])
        {
            isPeak = false;
        }
        if(i+1 < n && arr[i+1] < arr[i])
        {
            isPeak = false;
        }
        if(isPeak) return arr[i];
    }
    return -1;
}

// Using the binary search approach with the time complexity of O(log n) and space complexity of O(1)
// this approach is using the divide and conquer rule in behind so have a watch on it too
int findPeakUsingBinarySearch(int arr[],int n)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(mid-1 >= 0 && arr[mid] < arr[mid-1])
        {
            end = mid-1;
        }
        else if(mid + 1 < n && arr[mid] < arr[mid + 1])
        {
            start = start+1;
        }
        else
        {
            return arr[mid];
        }
    }
    return -1;
}

int main()
{
    return 0;
}