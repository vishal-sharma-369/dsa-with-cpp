// Solving array leet code questions
// #include<iostream>

// using namespace std;

// void swapAlternate(int arr[],int size)
// {
//     for(int i = 0;i<size;i+=2)
//     {
//         if(i+1<size)
//         {
//             swap(arr[i],arr[i+1]);
//         }
//     }
// }

// int main()
// {
//     int arr[5] = {1,2,3,4,5};
//     for(int i = 0;i<5;i+= 2)
//     {
//         int temp = arr[i];
//         arr[i] = arr[i+1];
//         arr[i+1] = temp;
//     }
//     cout<<"The elements of array after swapping are"<<endl;
//     for(int i = 0;i<5;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }




// find the element with the single entry in the arryay in which m elements appear twice and 1 element appear only once
// Method 1: use the map and map each element with its number of counts in the array , then print the element with the single count
// #include<iostream>
// #include<map>
// using namespace std;

// int singleElement(int arr[],int size)
// {
//     map<int,int> elemCount;
//     for(int i = 0;i<size;i++)
//     {
//         elemCount[arr[i]] = elemCount[arr[i]]++;
//     }
//     // iterator<elemCount> i = elemCount;
// }

// int main()
// {
    
//     return 0;
// }


// Method 2: for every element subtract its corresponding equal element and the result will be the only single element of the array
// concept : xor of two same numbers is 0 and xor of a number with 0 is the same number
// #include<iostream>

// using namespace std;

// int main()
// {
//     int arr[5] = {1,2,2,3,3};
//     int ans = 0;
//     for(int i = 0;i<5;i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     cout<<"The only single element present in the array is "<<ans<<endl;
// }


















// write a program to find the duplicate element in an array where if the no. of elements is n then 1 to n-1 elements are atleast present once in that array

// Mehtod 1: simply make a map where you count the occurances of each element and the element with a count of 2 is the answer

// Method 2: calculate the sum of elements from 1 to n-1 and calculate the sum of all the elements of the array and finally subtract the sum of n-1 elements from the total sum of array elements . this gives you the required answer.

#include<iostream>
using namespace std;

int nSum(int n)
{
    int sum = 0;
    for(int i = 0;i<=n;i++)
    {
        sum+= i;
    }
    return sum;
}

int Asum(int arr[],int size)
{
    int sum = 0;
    for(int i = 0;i<size;i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[5] = {1,2,3,4,2};
    cout<<"The only duplicate element present in the array is "<<Asum(arr,5) - nSum(4)<<endl;
    return 0;
}