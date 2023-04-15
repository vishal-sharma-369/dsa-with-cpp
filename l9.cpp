// Introducing the arrays
// #include<iostream>

// using namespace std;

// int main()
// {
//     // learning to initialize an array
//     // int arr[3] = {1,2,3};
//     // int arr[3];              // this will be initialized by any garbage value but most of the times it is zero
//     // int arr[1000] = {0};

//     // int arr[1000] = {1};     // this will initialize only the first element of the array to 1 and rest are all 0's
//     // for(int i = 0;i<1000;i++)
//     // {
//     //     cout<<arr[i];
//     // }
//     // cout<<endl;

//     return 0;
// }

// // How to initialize the entire array with a given value

// #include <iostream>

// using namespace std;

// int main()
// {
//     int number[15];
//     cout << "Value at 1 index is " << number[1] << endl;
//     cout << endl
//          << "Everything is fine" << endl
//          << endl;

//     return 0;
// }

// if you want to access the 20th index element of an array , you need to create an array of size atleast 21.  Okey vishal sharma


// Print all the elements of an array
// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[3] = {1,2,3};
//     for(int i = 0;i<3;i++)
//     {
//         cout<<arr[i]<<endl;
//     }
//     cout<<endl;
//     return 0;
// }

// if you initialize only a few elements of the array , then the rest of the elements will be initialized to 0
// Arrays with functions

// #include<iostream>

// using namespace std;


// // Not a good practice : because we won't be able to define the useful number of elements in the array
// // int printArray(int arr[15])
// // {

// // }

// void printArray(int arr[],int size)
// {
//     cout<<"Printing the array"<<endl;
//     for(int i = 0;i<size;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return;
// }

// void printArray(char arr[],int size)
// {
//     cout<<"Printing the array"<<endl;
//     for(int i = 0;i<size;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return;
// }

// int main()
// {
//     int arr[100] = {11,2,3};
//     printArray(arr,3);

//     // Making an array of characters
//     char charr[5] = {'a','b','c','d','e'};
//     printArray(charr,5);
//     return 0;
// }



// #include<iostream>
// using namespace std;

// int findMax(int arr[],int size)
// {
//     int max = INT32_MIN;
//     for(int i = 0; i<size;i++)
//     {
//         if(max<arr[i]) max = arr[i];
//     }
//     return max;
// }

// int findMin(int arr[],int size)
// {
//     int min = INT32_MAX;
//     for(int i = 0;i<size;i++)
//     {
//         if(min>arr[i]) min = arr[i];
//     }
//     return min;
// }

// int main()
// {
//     int arr[5];
//     cout<<"Enter the five elemnts of array"<<endl;
//     for(int i = 0;i<5;i++)
//     {
//         cin>>arr[i];
//     }
//     int max = findMax(arr,5);
//     int min = findMin(arr,5);
//     cout<<"Maximum element of the array is "<<max<<endl;
//     cout<<"Minimum element of the array is "<<min<<endl;
//     return 0;
// }





// whenever you pass an array to a function , always the address of the first element is sent to the function. So any later updations in the elements of the passed array will also update the original array.
// Remember that okey.


// Make a function to print the sum of all the elements of an array
// #include<iostream>
// using namespace std;

// void printSum(int arr[], int size)
// {
//     int sum = 0;
//     for(int i = 0;i<size;i++)
//     {
//         sum += arr[i];
//     }
//     cout<<"The sum of all the elements of the array is "<<sum<<endl;
//     return;
// }

// int main()
// {
//     int arr[6];
//     cout<<"Enter the six elements of array"<<endl;
//     for(int i = 0;i<6;i++)
//     {
//         cin>>arr[i];
//     }

//     printSum(arr,6);
//     return 0;
// }




// Working with the linear search in an array
// #include<iostream>
// using namespace std;

// bool linearSearch(int arr[],int size,int key)
// {
//     for(int i = 0;i<size;i++)
//     {
//         if(arr[i] == key)
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     int arr[10];
//     cout<<"Enter the ten elements of an array"<<endl;
//     for(int i = 0;i<10;i++)
//     {
//         cin>>arr[i];
//     }

//     if(linearSearch(arr,10,10))
//     {
//         cout<<"10 is present in the array"<<endl;
//     }
//     else
//     {
//         cout<<"10 is not present in the array"<<endl;
//     }
//     return 0;
// }






// Write a program to reverse an array
// #include<iostream>

// using namespace std;
// void reverseArray(int arr[],int size)
// {
//     for(int i = 0;i<=size/2;i++)
//     {
//         int temp = arr[i];
//         arr[i] = arr[size-1-i];
//         arr[size - 1- i] = temp;
//     }
//     return;
// }
// int main()
// {
//     int arr[5];
//     cout<<"Enter the elements of array"<<endl;
//     for(int i = 0;i<5;i++)
//     {
//         cin>>arr[i];
//     }
//     reverseArray(arr,5);
//     for(int i = 0;i<5;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }





#include<iostream>

using namespace std;

void reverse(int arr[],int n)
{
    int start = 0;
    int end = n-1;
    while(start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return;
}

int main()
{
    int arr[4] = {1,2,3,4};
    reverse(arr,4);
    for(int i = 0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}