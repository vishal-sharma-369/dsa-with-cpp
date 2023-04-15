// // Working with the hash maps
// // Map is a data structure which we can use to  store the data in the form of key value pairs
// // The insertion, deletion and searching operations in a hash map can be performed in O(1) time complexity

// /*
// There are two types of maps:
// map - time complexity O(logn) - Based on binary tree structure
// unordered_map - time complexity O(1) - Based on hash tables
// */

// #include <iostream>
// #include <map>
// #include <unordered_map>
// #include <string>

// using namespace std;

// // Implementing an unordered map
// int main()
// {
//     // creation
//     unordered_map<string, int> m;

//     // insertion

//     // 1
//     pair<string, int> p = make_pair("babbar", 3);
//     m.insert(p);

//     // 2
//     pair<string, int> q("love", 2);
//     m.insert(q);

//     // 3
//     m["mera"] = 1; // this will make a new entry
//     m["mera"] = 2; // this will update the current entry

//     // All the keys are unique

//     // Searching
//     cout << m["mera"] << endl;
//     cout << m.at("babbar") << endl;
//     // cout << m.at("unknown") << endl;    // this will give us error
//     cout << m["unknown"] << endl; // this won't give us error instead 0 as this will create a new entry corresponding to 0 . So this is creating a new entry in the map
//     cout << m["unknown"] << endl; // this is retrieving the present value of the unknown key i.e. 0

//     // size
//     cout << m.size() << endl;

//     // to check presence
//     cout << m.count("bro") << endl; // count gives 0 if the key is not present and gives 1 if the key is present

//     // erase function
//     m.erase("love"); // this will erase a particular key from the map
//     cout << m.size() << endl;

//     // iterating the map
//     for (auto i : m)
//     {
//         cout << i.first << " " << i.second << " " << endl;
//     }

//     // iterator
//     unordered_map<string, int>::iterator it = m.begin();
//     while (it != m.end())
//     {
//         cout << it->first << " " << it->second << " " << endl;
//         it++;
//     }

//     // In unordered map  the key value pairs are stored in a random order
//     // Whereas in a ordered map the key value pairs are stored in the same order as they are inserted into the map

//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------
// Write a program to  print the most frequent number
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countFrequency(vector<int> arr, int size)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    int ans;
    int maxCount = INT32_MIN;
    for (auto i : mp)
    {
        if (i.second > maxCount)
        {
            maxCount = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main()
{

    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------

// Now we are going to talk about the bucket array and the hash functions
// A bucket array is simply an array which is used to store our key value pairs

// The hash function consists of two functions
// 1. hash code
// 2. compression function

// whichever data type of key is to be converted in the form of an integer using hash code function
// int coming hash code is to be converted into a desired range using the work of compression function

/*
Some of the hash codes are
identity function - same input same output
Sum of ascii values of all the characters of string -> returns an integer output
multiplied sum of ascii values with the corresponding index values -> returns an integer output
*/

/*
Hash functions are used for
- conversion to integer
- uniform distribution : different keys should not convert to a same integer (this is the concept of collision)

(collision handling):
open hashing : same place par hi jao : a head of the linked list is stored in the block -> this is also known as separate chaining
closed addressing :

open addressing :
hi(a) = h(a) + fi(a)
Linear probing: fi = i
quadratic probing: fi = i^2

The only thing to keep in mind which designing a hash function is that the separate chaining should work efficiently



for sufficient separate chaining
if : n -> no of elements to be inserted
if : b -> no of boxes availabe to store the data

then no of entries in a box -> (n/b) -> load factor
we always ensure -> (n/b) < 0.7
this ensures the uniform distribution of data in the hash maps



complexity analysis:
n-> total no of words
k -> word length

then according to rule
the tiime complexity of hash function should be
TC -> O(k) for insertion
but we assume that n>>k and we neglect the effect of O(k) and assume it to be equal to O(1)

// if you think that all the elements may come into a same linked list: so let me clear that this thing never takes place . Here we use the concept of load factor which is used to balance the amount of data or the elemnts.



Now it is safe to assume that the insertion is taking place in O(1) time complexity.


if n increases then the no of boxes b should also increase i.e. to increase the bucked size also in order to maintain the load factor
in this case we rehash all the entries in the hash map
this is the game for insertion


same is the stuff for deletion and insertion in a hash map

maps : what ? why ?
insertion : O(1)
deletion : O(1)
searching : O(1)

implementation :
Linked list : O(n)
BST : O(logn)
bucket array and hash function : O(1)
open hashing
closed addressing
n/b -> load factor (0.7 max)

*/