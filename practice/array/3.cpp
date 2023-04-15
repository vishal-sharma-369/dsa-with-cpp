// find the minimum distance between two given numbers in an array
#include<iostream>
#include<math.h> 

using namespace std;


int findMinDistanceUsingBruteForce(int arr[],int n,int x,int y)
{
    int minDistance = INT32_MAX;
    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;i<n;j++)
        {
            if(arr[i] == x && arr[j] == y || arr[i] == y && arr[j] == x && j - i < minDistance)
            {
                minDistance = j - i;
            }
        }
    }
    return minDistance;
}

int findMinDistance(int arr[],int n,int x,int y)
{
    int xindex = -1;
    int yindex = -1;
    int minDistance = INT32_MAX;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == x)
        {
            xindex = i;
            if(yindex>=0)
            {
                int z = xindex - yindex;
                if(z<minDistance)minDistance = z;
            }
        }
        if(arr[i] == y)
        {
            yindex = i;
            if(xindex>=0)
            {
                int z = yindex - xindex;
                if(z<minDistance) minDistance = z;
            }
        }
    }
    return minDistance;
}

int main()
{
    return 0;
}