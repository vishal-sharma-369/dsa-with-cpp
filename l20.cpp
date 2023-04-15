// The first question is to reverse an array
// #include<iostream>

// using namespace std;
// void reverseArray(int arr[],int size)
// {
//     for(int i = 0;i<size/2;i++)
//     {
//         int temp = arr[i];
//         arr[i] = arr[size-1-i];
//         arr[size-1-i] = temp;
//     }
// }


// // Using the 2 pointer approach
// void reverseArrayUsingPointer(int arr[],int size)
// {
//     int start = 0;
//     int end = size-1;
//     while(start<=end)
//     {
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }
// }

// void printArray(int arr[],int n)
// {
//     for(int i = 0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main()
// {
//     int arr[5] = {1,2,3,4,5};
//     cout<<"The original array is "<<endl;
//     printArray(arr,5);
//     reverseArray(arr,5);
//     cout<<"The reversed array is "<<endl;
//     printArray(arr,5);
//     return 0;
// }



// Using the vector stl library
// #include<iostream>
// #include<vector>

// using namespace std;

// vector<int> reverseArray(vector<int> v)
// {
//     int start = 0;
//     int end = v.size() -1 ;
//     while(start<=end)
//     {
//         swap(v[start],v[end]);
//         start++;
//         end--;
//     }
//     return v;
// }

// void printVector(vector<int> v)
// {
//     for(auto i:v)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }


// // Reversing an array after a specified index
// vector<int> reverseFromSpecifiedIndex(vector<int> v,int m)
// {
//     int start = m+1;
//     int end = v.size() - 1;
//     while(start<=end)
//     {
//         swap(v[start],v[end]);
//         start++;
//         end--;
//     }
//     return v;
// }

// int main()
// {
//     vector<int> v;
//     v.push_back(11);
//     v.push_back(7);
//     v.push_back(3);
//     v.push_back(12);
//     v.push_back(4);

//     printVector(v);
//     vector<int> ans = reverseArray(v);
//     printVector(v);
//     printVector(ans);
//     return 0;
// }








// merge two sorted arrays into a single sorted array
// #include<iostream>
// #include<vector>

// using namespace std;

// vector<int> mergeSort(vector<int> v1,vector<int> v2)
// {
//     vector<int> res;
//     int s1 = 0;
//     int s2 = 0;
//     while(s1<v1.size() && s2<v2.size())
//     {
//         if(v1[s1]<v2[s2])
//         {
//             res.push_back(v1[s1]);
//             s1++;
//         }
//         else if(v1[s1]>v2[s2])
//         {
//             res.push_back(v2[s2]);
//             s2++;
//         }
//         else
//         {
//             res.push_back(v1[s1]);
//             s1++;
//         }
//     }
//     if(s1<v1.size())
//     {
//         while(s1<v1.size())
//         {
//             res.push_back(v1[s1++]);
//         }
//     }
//     else if(s2<v2.size())
//     {
//         while(s2<v2.size())
//         {
//             res.push_back(v2[s2++]);
//         }
//     }
//     return res;
// }

// void printVector(vector<int> v)
// {
//     for(auto i:v)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     // vector<int> v1 = {1,3,5,7,9};
//     // vector<int> v2 = {2,4,6,8};
//     // vector<int> ans = mergeSort(v1,v2);
//     // printVector(ans);

//     int arr[4] = {1,2,3,4};
//     // for(auto i:arr)
//     // {
//     //     cout<<i<<" ";
//     // }
//     // cout<<endl;

//     //  This will also run using the int as 
//     for(int i:arr)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     return 0;
// }








#include<iostream>

using namespace std;
void Sort(int arr[],int size)
{
    int i = 0;
    int j = size-1;
    while(i<j)
    {
        while(arr[j] == 0)
        {
            j--;
        }
        while(arr[i] != 0)
        {
            i++;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
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
    int arr[10] = {0,3,2,0,0,5,6,2,0,1};
    printArray(arr,10);
    Sort(arr,10);
    printArray(arr,10);
    return 0;

}