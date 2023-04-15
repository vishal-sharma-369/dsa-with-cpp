// Working with the conditionals and the loops
// conditionals

// #include<iostream>

// using namespace std;

// int main()
// {
//     int a,b;
//     cout<<"Enter two values for a and b"<<endl;
//     if(a>b)
//     {
//         cout<<"The answer is a"<<endl;
//     }
//     else
//     {
//         cout<<"The answer is b"<<endl;
//     }
//     return 0;
// }

// Program to print whether a number is positive or negative
#include<iostream>

using namespace std;

int main()
{
    int a;
    cout<<"Enter the value of a"<<endl;
    cin>>a;

    if(a<0)
    {
        cout<<"a is negative"<<endl;
    }
    else
    {
        cout<<"a is positive"<<endl;
    }
    return 0;
}