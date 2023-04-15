// Making pattern : 1

// #include <iostream>
// using namespace std;
// int main()
// {
//     int number;
//     cout << "Enter the number of rows and columns " << endl;
//     cin >> number;
//     for (int row = 0; row < number; row++)
//     {
//         for (int col = 0; col < number; col++)
//         {
//             cout << col + 1;
//         }
//         cout << endl;
//     }
// } 



// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number"<<endl;
//     cin>>n;
//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0;col<n;col++)
//         {
//             cout<<n - col;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;
//     int value = 1;

//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0;col<n;col++)
//         {
//             cout<<value++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of rows"<<endl;
//     cin>>n;
//     for(int row = 0;row < n;row++)
//     {
//         for(int col = 0; col <= row ; col++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of rows"<<endl;
//     cin>>n;
//     for(int row = 0;row < n;row++)
//     {
//         for(int col = 0;col<=row;col++)
//         {
//             cout<<row + 1;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     int value = 1;
//     for(int row = 0;row < n;row++)
//     {
//         for(int col = 0;col<=row;col++)
//         {
//             cout<<value;
//             value++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of rows"<<endl;
//     cin>>n;
//     for(int row = 0;row < n;row++)
//     {
//         int value = row + 1;
//         for(int col = 0; col<=row;col++)
//         {
//             cout<<value++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// making the same pattern without using the initializer variable
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0;row < n;row++)
//     {
//         for(int col = 0; col <=row ; col++)
//         {
//             cout<<row + 1 + col;
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of rows"<<endl;
//     cin>>n;

//     for(int row = 0; row < n; row++)
//     {
//         for(int col = 0; col <= row ; col++)
//         {
//             cout<<row + 1 - col;
//         }
//         cout<<endl;
//     }
//     return 0;
// }





// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of number of rows"<<endl;
//     cin>>n;
//     for(int row = 0; row<n;row++)
//     {
//         for(int col = 0; col<n;col++)
//         {
//             cout<<char(65+row);
//         }
//         cout<<endl;
//     }
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;
//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0; col<n;col++)
//         {
//             cout<<char(65 + col);
//         }
//         cout<<endl;
//     }
//     return 0;
// }





// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;
//     int value= 0;
//     for(int row = 0; row < n; row++)
//     {
//         for(int col = 0;col<n;col++)
//         {
//             cout<<char(65 + value++);
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0; row < n; row++)
//     {
//         for(int col = 0;col<n;col++)
//         {
//             cout<<char(65+row+col);
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of rows"<<endl;
//     cin>>n;

//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0;col<=row;col++)
//         {
//             cout<<char(65+row);
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;
//     int value = 65;

//     for(int row = 0 ; row < n ; row++ )
//     {
//         for(int col = 0 ; col <= row ; col++ )
//         {
//             cout<<char(value++);
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0; row < n; row ++)
//     {
//         for(int col = 0; col <= row ; col++)
//         {
//             cout<<char(65 + row + col);
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0; row<n;row++)
//     {
//         for(int col = 0; col<=row;col++)
//         {
//             cout<<char(65+n-1-row+col);
//         }
//         cout<<endl;
//     }
//     return 0;
// }





// #include<iostream>

// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Enter the number of rows"<<endl;
//     cin>>n;

//     for(int row = 0;row<n;row++)
//     {
//         for(int col=0;col<n-1-row;col++)
//         {
//             cout<<" ";
//         }
//         for(int col = 0;col<=row;col++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0;col<n-row;col++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0;col<row;col++)
//         {
//             cout<<" ";
//         }
//         for(int col = 0;col<n-row;col++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include<iostream>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;

//     for(int row = 0;row<n;row++)
//     {
//         for(int col = 0;col<n-1-row;col++)
//         {
//             cout<<" ";
//         }
//         for(int col = 0;col<=row;col++)
//         {
//             cout<<col+1;
//         }
//         for(int col = 0;col<row;col++)
//         {
//             cout<<row-col;
//         }
//         cout<<endl;
//     }
//     return 0;
// }




#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    for(int row = 0;row<n;row++)
    {
        for(int col = 0;col<n-row;col++)
        {
            cout<<col+1;
        }
        for(int col = 0;col<row;col++)
        {
            cout<<"**";
        }
        for(int col =0;col<n-row;col++)
        {
            cout<<n-row-col;
        }
        cout<<endl;
    }
    return 0;
}