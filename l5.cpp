// Operators and For loops:
// operators : & , | , ~ , ^
// leftshifting a number by a number i is equal to no * 2^i ? this is only valid for smalller numbers
// in some cases it also forms a negative number if the original number is very large
// in left shift or in the right shift operator , the padding is always done with 0

// i++ is the post increment operator
// ++i is the preincrement operator
// 1 stage2 - inside if 0 3 100 1 3   viva voice questions

// Working with the operators
// #include<iostream>

// using namespace std;

// int main()
// {
//     int a = 4 , b = 6 ;
//     int bit = a & b;
//     cout<< " the bitwise and operator is " << bit << endl;
//     bit = a| b;
//     cout<<"The bitwise or operator is "<<bit<<endl;
//     bit = ~a;
//     cout<<"The bitwise not operator is "<<bit<<endl;
//     bit = a^b;
//     cout<<"The bitwise xor operator is "<<bit<<endl;
//     bit = a<<1;
//     cout<<"The bitwise leftshift operator of a is "<<bit<<endl;
//     return 0;
// }

// Working with the for loops
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     cout<<"Printing the count from 1 to n:"<<endl;
//     for(int i = 1;i<=n;i++)
//     {
//         cout<<i<<endl;
//     }
//     return 0;
// }

// Working with the break keyword
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the value of n" << endl;
//     cin >> n;

//     int i = 1;
//     for (;;)
//     {
//         if (i <= n)
//         {
//             cout << i << endl;
//         }
//         else
//         {
//             break;
//         }
//         i++;
//     }
//     return 0;
// }

// Find the sum of all positive integers from 1 to n
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the value of n" << endl;
//     cin >> n;
//     int sum = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         sum += i;
//     }
//     cout << "The sum is " << sum << endl;
// }

// Finding the nth term of fibonacci series using for loop
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the term number"<<endl;
//     cin>>n;

//     int f = 0;
//     int s = 1;
//     int curr;
//     for(int i = 3;i<=n;i++)
//     {
//         curr = f + s;
//         f = s;
//         s = curr;
//     }
//     cout<<"The "<<n<<"th term of the fibonacci series is "<<curr<<endl;
// }

// Check whether a number is prime or not
// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number"<<endl;
//     cin>>n;

//     for(int i= 2;i<n;i++)
//     {
//         if(n%i==0)
//         {
//             cout<<"The number is not prime"<<endl;
//             break;
//         }
//     }
// }

// Working with the continue statement : It is used to skip a particular iteration
// #include<iostream>
// using namespace std;
// int main()
// {
//     for(int i = 0;i<=5;i--)
//     {
//         cout<< i <<" ";
//         i++;;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//     for(int i = 0;i<=15;i+=2)
//     {
//         cout<<i<<" ";
//         if(i&1)
//         {
//             continue;
//         }
//         i++;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//     for(int i = 0;i<5;i++)
//     {
//         for(int j = i;j<=5;j++)
//         {
//             if(i+j == 10)
//             {
//                 break;
//             }
//             cout<<i<<" "<<j<<endl;
//         }
//     }
//     return 0;
// }

// Working with the operator precedence

// Finding the sum and product of the digits of a given number
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number"<<endl;
//     cin>>n;
//     int sum = 0;
//     int product = 1;
//     while(n!=0)
//     {
//         sum+= n%10;
//         product *= n%10;
//         n/=10;
//     }
//     cout<<"The sum of the digits of the number is "<<sum<<endl;
//     cout<<"The product of the digits of the number is "<<product<<endl;
//     return 0;
// }

// Find the number of 1 bits in the binary representation of a given number
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    int count = 0;

    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    cout << "The total number of 1 bits in the binary representation of the given number is " << count << endl;
    return 0;
}