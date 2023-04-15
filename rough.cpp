// This is a simple text file and nothing more than that okey vishal sharma haina vishal sharma this is so cool right now we don't even have to wait for the computer or need an extra space for the keyboard to use it with my laptop and even it is more friendly to my hands also right yeah


// Write a program to find the cross product of two or more sets
// #include<iostream>
// #include<vector>
// using namespace std;

// void solver(vector<vector<int>> &arr,int s,vector<int>&instance,vector<vector<int>>&ans)
// {
//     if(s>=arr.size())
//     {
//         ans.push_back(instance);
//     }
//     else
//     {
//         for(int i = 0;i<arr[s].size();i++)
//         {
//             instance.push_back(arr[s][i]);
//             solver(arr,s+1,instance,ans);
//             instance.pop_back();
//         }
//     }
// }

// void printer(vector<vector<int>> arr)
// {
//     cout<<"{ ";
//     for(int row = 0;row<arr.size();row++)
//     {
//         cout<<"{";
//         for(int col = 0;col<arr[row].size();col++)
//         {
//             if(col==arr[row].size()-1)
//             {
//                 cout<<arr[row][col];
//             }
//             else
//             {
//             cout<<arr[row][col]<<", ";
//             }
//         }
//         if(row==arr.size()-1)
//         {
//             cout<<"} ";
//         }
//         else
//         {
//             cout<<"} , ";
//         }
//     }
//     cout<<"}"<<endl;
// }

// int main()
// {
//     vector<vector<int>> arr = {{1,2},{1,2},{1,2}};
//     vector<int>instance;
//     vector<vector<int>>ans;
//     cout<<"The original array sets were :"<<endl;
//     printer(arr);
//     solver(arr,0,instance,ans);
//     cout<<"The resultant cross multiplication of sets is "<<endl;
//     printer(ans);
//     return 0;
// }














#include<iostream>
#include<vector>
using namespace std;

void solver(vector<int>&arr,int s,vector<vector<int>>&ans,vector<int>&instance)
{
    if(s>=arr.size())
    {
        ans.push_back(instance);
    }
    else
    {
        solver(arr,s+1,ans,instance);
        instance.push_back(arr[s]);
        solver(arr,s+1,ans,instance);
        instance.pop_back();
        return;
    }
}

void printer(vector<vector<int>> arr)
{
    cout<<"{ ";
    for(int row = 0;row<arr.size();row++)
    {
        cout<<"{";
        for(int col = 0;col<arr[row].size();col++)
        {
            if(col==arr[row].size()-1)
            {
                cout<<arr[row][col];
            }
            else
            {
            cout<<arr[row][col]<<", ";
            }
        }
        if(row==arr.size()-1)
        {
            cout<<"} ";
        }
        else
        {
            cout<<"} , ";
        }
    }
    cout<<"}"<<endl;
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>>ans;
    vector<int>instance;
    solver(arr,0,ans,instance);
    cout<<"The power set of {1,2,3} is "<<endl;
    printer(ans);
    return 0;
}