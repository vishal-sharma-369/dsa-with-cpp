// Solving the leet code problems

// reverse the digits of an integer
// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of integer number"<<endl;
//     cin>>n;
//     int answer = 0;

//     while(n!=0)
//     {
//         int digit = n%10;
//         if(answer < (INT32_MAX/10) || answer >( INT32_MAX/10))
//         {
//             answer = 0;
//             break;
//         }
//         answer = (answer*10) + digit;
//         n/=10;
//     }

//     cout<<"The digits of the answer in reverse order are "<<answer<<endl;
//     return 0;
// }

// Finding the complement of a given number
// #include <iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the number" << endl;
//     cin >> n;

//     int m = n;
//     int count = 0;
//     int mask = 0;
//     while (m != 0)
//     {
//         count++;
//         m = m >> 1;
//     }
//     while (count != 0)
//     {
//         count--;
//         mask = mask << 1;
//         mask = mask | 1;
//     }

//     // Now we have made the mask
//     int answer;
//     if (n == 0)
//     {
//         answer = 1;
//     }
//     else
//     {
//         answer = ~n;
//         answer = answer & mask;
//     }
//     cout << "The complement of the given number is " << answer << endl;
//     return 0;
// }








// Program to check whether a given number is a power of 2 or not
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number"<<endl;
//     cin>>n;

//     int count = 0;
//     while(n!=0)
//     {
//         if(n&1)
//         {count++;}
//         n = n>>1;
//     }
//     if(count==1)
//     {
//         cout<<"The number is a power of 2"<<endl;
//     }
//     else
//     {
//         cout<<"The number is not a power of 2"<<endl;
//     }
//     return 0;
// }



// method 2 to check whether the given number is a power of 2 or not
// #include<iostream>
// #include<math.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number"<<endl;
//     cin>>n;
//     int check = false;

//     for(int i = 0;i<=30;i++)
//     {
//         int ans = pow(2,i);
//         if(n == ans)
//         {
//             check = true;
//         }
//     }
//     if(check)cout<<"The given number is a power of 2"<<endl;
//     else cout<<"The given number is not a power of 2"<<endl;
//     return 0;
// }



// Optimizing method 2
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    bool check = false;

    int ans = 1;
    for(int i = 0;i<=30;i++)
    {
        if(ans == n)
        {
            check = true;
        }
        if(ans < INT32_MAX/2)
        ans = ans * 2;
    }
    if(check)cout<<"YES\n";
    else cout<<"NO"<<endl;
    return 0;
}