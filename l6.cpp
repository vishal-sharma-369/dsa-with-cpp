// first logic is to just divide the number by 2 and each time just save the reaminder in a storage from where you can access it again and then reverse the stored string format to represent the number in the binary decimal format.
// second logic is to use the bitwise and operator and checking for just one specific bit at a time and then right shifting the original number by one bit and this will be done until the number doesn't become zero.
// after that you also have to use the formula answer = 10*i * digit + answer alright
// To find the reverse of a number using the given array of digits you can use the formula answer = (10 ^ i * digit ) + answer
// To find the number using the given array of digits in the same flow use the formula answer = ( anser * 10 ) + digit;
// so these are the methods to find the elements from the given elements of array

// Method 1 implementation

// #include<iostream>

// using namespace std;

// int main()
// {
//     int arr[3];
//     cout<<"Enter the three elements of array"<<endl;
//     int answer = 0;
//     for(int i = 0;i<3;i++)
//     {
//         cin>>arr[i];
//     }
//     for(int i = 0;i<3;i++)
//     {
//         answer = (answer * 10) + arr[i];
//     }
//     cout<<"The number you entered is "<< answer<<endl;
//     return 0;
// }

// now we have to find the reverse number of the elements of the array
// #include <iostream>
// #include <math.h>

// using namespace std;

// int main()
// {
//     int arr[3];
//     cout << "Enter the three elements of the array" << endl;
//     int answer = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         answer = ((arr[i] * pow(10, i)) + answer);
//         cout<<answer<<endl;
//     }

//     cout << "The entered sequence of numbers in reverse order is " << answer << endl;

//     return 0;
// }

// #include <iostream>
// #include <math.h>

// using namespace std;

// int main()
// {
//     int num;
//     cout << "Enter the number" << endl;
//     cin >> num;
//     int answer = 0;
//     int i = 0;
//     while (num != 0)
//     {
//         int bit = 0;
//         bit = num & 1;

//         num = num >> 1;
//         answer = (bit * pow(10, i)) + answer;
//         i++;
//     }
//     cout << "The bit representation of the number is " << answer << endl;
//     return 0;
// }


// #include<iostream>
// #include<math.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;

//     int ans = 0;
//     int i = 0;
//     while(n!=0)
//     {
//         int bit = n & 1;
//         ans = (bit * pow(10,i)) + ans;
//         n = n >> 1;
//         i++;
//     }
//     cout<<"Answer is "<<ans<<endl;
//     cout<<sizeof(int)<<endl;
//     return 0;
// }





// Binary to decimal conversion
// Method 1 : using the binary and operator and then right shift operator until number becomes equal to zero
// #include<iostream>
// #include<math.h>

// using namespace std;

// int main()
// {
//     int bin[5];
//     cout<<"Enter the binary number"<<endl;
//     int answer = 0;
//     for(int i = 0;i<5;i++)
//     {
//         cin>>bin[5 - 1 - i];
//     }
//     for(int i = 0;i<5;i++)
//     {
//         answer = (bin[i] * pow(2,i)) + answer;
//     }
//     cout<<"The binary representation of the number is " << answer << endl;
//     return 0;
// }



#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int number;
    cout<<"Enter the number"<<endl;
    cin>>number;

    int answer = 0;
    int i = 0;

    while(number != 0)
    {
        int digit = number % 10;
        number /= 10;
        answer = (digit * pow(2,i)) + answer;
        i++;
    }
    cout<<"The decimal form of the entered binary number is "<<answer<<endl;
    return 0;
}