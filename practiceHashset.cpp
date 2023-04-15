// // unordered_set is implemented using hash set where the keys are hashed into indices of a hash table so that the insertion is always randomised
// // all the operations on the unordered_set takes constant time O(1) on an average.
// // which can go up to linear time O(n) in worst case
// // which depends on the internally used hash functjion, but practically they perform very well and generally provide a constant time lookup operation.
// // #include <unordered_map>
// // #include <unordered_set>

// // set vs unordered_set
// /*
// // set -> key are stored in ordered fashion
// // unordered_set -> key are stored in ordered fashion

// set is internally implemented using red black tree
// unordered_set is internally implemented using hashing

// set operation -> time complexity O(log n)
// unordered_set operation ->  time complexity O(1)
// */

// /*
// functions:
// insert()
// size()
// clear()
// begin()
// end()
// find()
// erase()
// count()

// unordered_set does not have duplicate keys
// */
// #include <bits/stdc++.h>
// #include <unordered_set>
// using namespace std;

// using namespace std;
// int main()
// {
//     unordered_set<int> s;
//     s.insert(10);
//     s.insert(5);
//     s.insert(15); // TC : O(1)
//     s.insert(20);
//     s.insert(20); // the set will ignore this entry as it is already present in the set

//     for (auto i = s.begin(); i != s.end(); i++) // auto keyword automatically detects the data type
//     {
//         cout << *i << endl;
//     }

//     cout << "number of elements : ";
//     cout << s.size() << endl; // tc : O(1)

//     s.clear(); // this will clear the whole set
//     cout << "number of elemtns : " << s.size() << endl;

//     int key = 25;
//     if (s.find(key) == s.end())
//     {
//         cout << "key not found" << endl;
//     }
//     else
//     {
//         cout << "key found" << endl;
//         auto temp = s.find(key); // find function returns the iterator to the specified key
//         s.erase(temp);
//     }

//     int deleted_key = 15;
//     s.erase(deleted_key);

//     cout << "the size of set is " << s.size() << endl;

//     // we can erase a key by two methods
//     // by the key itself
//     // or by using the iterator to that key

//     if (s.find(key) != s.end())
//     {
//         cout << "key found" << endl;
//     }

//     if (s.count(5))
//     {
//         cout << "key found" << endl;
//     }
//     else
//     {
//         cout << "Key not found" << endl;
//     }

//     return 0;
// }

// in unordered_set only the data is stored in the form of keys where the data itself is used to find the particular hash index.
// in unordered_map the data is stored in the form of {key,value} pairs where the keys are used to find the particular hash index.

/*
the functionality and the implementation of unordered_map is same as the unordered_set except the data is stored in pairs insted of keys only.


the data is stored in unordered fashion both in case of unordered_set and unordered_map
*/

// life is not about achieving things. It is about the process.

// #include <bits/stdc++.h>
// #include <unordered_map>

// using namespace std;

// int main()
// {
//     unordered_map<string, int> umap;
//     umap["prince"] = 44;
//     umap["gfg"] = 26;
//     umap["hello world"] = 98;

//     // unordered_map<string, int>::iterator it = umap.begin(); // This is the iterator to iterate over the map.
//     for (auto x : umap)
//     {
//         cout << x.first << " " << x.second << endl;
//     }

//     for (auto itr = umap.begin(); itr != umap.end(); itr++) // itr is the iterator which behaves as a pointer to the element pairs inside the map
//     {
//         cout << itr->first << " " << itr->second << endl;
//     }

//     string key = "prince";
//     if (umap.find(key) != umap.end()) // the find function returns iterator or the pointer to the element entry in the map. and end function denotes the iterator or the pointer to the end of the map where there is no element.
//     {
//         cout << "key found" << endl;
//     }
//     else
//     {
//         cout << "key not found" << endl;
//     }

//     if (umap.find(key) != umap.end())
//     {
//         auto temp = umap.find(key);
//         cout << "key is : " << temp->first << endl;
//         cout << "value is : " << temp->second << endl;
//     }

//     umap.insert(make_pair("mobile", 17000));

//     key = "hello world";

//     umap.erase(key); // erase function deletes a particular pair with that key from the map

//     cout << umap.size() << endl;

//     return 0;
// }

// Write a program which uses an unordered_map to store the frequency of occurances of elements in an array
// #include <bits/stdc++.h>
// #include <unordered_map>

// using namespace std;

// int main()
// {
//     int arr[] = {7, 1, 0, 3, 5, 0, 1, 3, 2, 5, 7, 3, 8, 9, 9};
//     unordered_map<int, int> counter;
//     // for(int i = 0;i<arr.size();i++)
//     // {

//     // }

//     for (auto i : arr)
//     {
//         counter[i]++;
//     }

//     for (auto i : counter)
//     {
//         cout << i.first << " " << i.second << endl;
//     }

//     for (auto i = counter.begin(); i != counter.end(); i++)
//     {
//         cout << i->first << " " << i->second << endl;
//     }
//     return 0;
// }

// Write a program to print the first non repeating element in the array
// #include <iostream>

// #include <bits/stdc++.h>
// using namespace std;
// int firstNonRepeating(int arr[], int n)
// {
//     // using unordered map to solve this problem
//     unordered_map<int, int> mp;

//     for (int i = 0; i < n; i++)
//     {
//         mp[arr[i]]++;
//     }

//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int key = arr[i];
//         auto temp = mp.find(key); // this will return an iterator or a pointer to the particular entry in the map
//         if (temp != mp.end() && temp->second == 1)
//         {
//             ans = key;
//             break;
//         }
//     }

//     return ans;
// }
// The time complexity of this solution is O(n).
// The space complexity of this solution is O(n).
// life is not about achieving things. it is more about the process.

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int arr[] = {1, 5, 3, 4, 3, 5, 6};

//     // make an unordered map and store the count
//     unordered_map<int, int> mp;

//     for (auto i : arr)
//     {
//         mp[i]++;
//     }

//     for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//     {
//         // if (mp.find(arr[i])->second > 1)
//         // {
//         //     return i;    // for 0 based indexing otherwise i+1 for 1 based indexing
//         // }
//         if (mp[arr[i]] > 1)
//         {
//             return i; // for 0 based indexing otherwise i+1 for 1 based indexing
//         }
//     }
//     return 0;
// }
// // The time complexity of this solution is O(n)
// // The space complexity of this solution is O(n)

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;

// Write a program to find the union of two arrays
// vector<int> findUnion(vector<int> arr1, vector<int> arr2)
// {
//     // using hashing
//     unordered_set<int> uset;
//     for (auto i : arr1)
//     {
//         uset.insert(i);
//     }
//     for (auto i : arr2)
//     {
//         uset.insert(i);
//     }
//     vector<int> ans;
//     // for (auto i : uset)
//     // {
//     //     ans.push_back(i);
//     // }
//     for (auto i = uset.begin(); i != uset.end(); i++)
//     {
//         ans.push_back(*i);
//     }
//     return ans;
// }

// Write a program to find the intersection of two arrays
// we will use the unordered_set to solve this question
// vector<int> intersectionSet(vector<int> arr1, vector<int> arr2)
// {
//     unordered_set<int> uset;
//     for (auto i : arr1)
//     {
//         uset.insert(i);
//     }

//     vector<int> ans;
//     for (auto i : arr2)
//     {
//         // if (uset.find(i) != uset.end())
//         // {
//         //     ans.push_back(i);
//         // }
//         if (uset.count(i) == 1)
//         {
//             ans.push_back(i);
//             uset.erase(i);
//         }
//     }
//     return ans;
// }
// The time complexity of this solution is O(max(arr1.size(),arr2.size()))
// The space complexity of this solution is O(arr1.size())

// Write a program to find whether a given array contains a pair whose sum is equal to the given key
// bool pairExist(vector<int> arr, int size, int key)
// {
//     unordered_set<int> uset;
//     for (auto i : arr)
//     {
//         uset.insert(i);
//     }

//     for (auto i = uset.begin(); i != uset.end(); i++)
//     {
//         int x = key - *i;
//         uset.erase(*i);
//         if (uset.find(x) != uset.end())
//         {
//             return true;
//         }
//         uset.insert(*i);
//     }
//     return false;
// }

// Write a program to find the subarray with 0 sum
// the naive approach to this problem would be to see all the subarrays and check if its sum is 0
// bool isSubarray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int cur_sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             cur_sum += arr[i];
//             if (cur_sum == 0)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// The time complexity of this solution is O(n^2)
// The space complexity of this solution is O(1)

// the more optimized appraoch to solve this problem would be to use an unordered_set
// bool isSubarrayPresent(int arr[], int n)
// {
//     unordered_set<int> uset;
//     int prefSum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         prefSum += arr[i];
//         if (prefSum == 0)
//         {
//             return true;
//         }
//         if (uset.find(prefSum) != uset.end())
//         {
//             return true;
//         }
//         uset.insert(prefSum);
//     }
//     return false;
// }
// This is the best approach to solve this problem
// The time complexity of this solution is O(n)
// The space complexity of this solution is O(n)
// This solution uses the concept of prefix sum. So study it if you don't know.

// Write a program to find the winner of an election
// vector<string> electionWinner(vector<string> arr, int n)
// {
//     unordered_map<string, int> umap;
//     for (auto i : arr)
//     {
//         umap[i]++;
//     }

//     string winner;
//     int maxVotes = 0;
//     for (auto i : umap)
//     {
//         if (i.second > maxVotes)
//         {
//             maxVotes = i.second;
//             winner = i.first;
//         }
//         else if (i.second == maxVotes)
//         {
//             if (i.first < winner)
//             {
//                 winner = i.first;
//             }
//         }
//     }
//     vector<string> ans;
//     ans.push_back(winner);
//     ans.push_back(to_string(maxVotes));
//     return ans;
// }

// Write a program to print all the pairs with positive and negative values
// int getOpp(int x)
// {
//     if (x < 0)
//     {
//         return -1 * x;
//     }
//     else
//     {
//         return x;
//     }
// }

// vector<int> getPairs(vector<int> arr, int size)
// {
//     unordered_set<int> uset;
//     vector<int> ans;
//     for (int i = 0; i < size; i++)
//     {
//         if (uset.find(getOpp(arr[i])) != uset.end())
//         {
//             ans.push_back(arr[i]);
//             ans.push_back(getOpp(arr[i]));
//             // uset.insert(arr[i]);
//             uset.erase(getOpp(arr[i]));
//         }
//         else
//         {
//             uset.insert(arr[i]);
//         }
//     }
//     return ans;
// }
// We can't use this solution for the array containing repeated values
// implementing the same solution using unordered map

// vector<int> getPairs(vector<int> arr, int n)
// {
//     unordered_map<int, int> umap;
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         if (umap.find(getOpp(arr[i]))->second != 0)
//         {
//             ans.push_back(arr[i]);
//             ans.push_back(getOpp(arr[i]));
//             umap[getOpp(arr[i])]--;
//         }
//         else
//         {
//             umap[arr[i]]++;
//         }
//     }
//     return ans;
// }
// // The space complexity of this solution is O(n)
// // The time complexity of this solution is O(n)

// vector<int> PosNegPair(int a[], int n)
// {
//     vector<int> v, ans;
//     map<int, int> mp;

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] < 0)
//         {
//             v.push_back(a[i]);
//         }
//         else
//         {
//             mp[a[i]]++;
//         }
//     }
//     sort(v.begin(), v.end());

//     for (int i = (v.size()) - 1; i >= 0; i--)
//     {
//         int data = fabs(a[i]);
//         if (mp[data] > 0)
//         {
//             ans.push_back(v[i]);
//             ans.push_back(data);
//             mp[data] -= 1;
//         }
//     }
//     return ans;
// }

// Write a program to print all the elements of an array according to the given order
// vector<int> sortAccToOrder(vector<int> arr1, vector<int> arr2, int size1, int size2)
// {
//     unordered_map<int, int> umap;
//     vector<int> ans;
//     for (auto i : arr1)
//     {
//         umap[i]++;
//     }
//     for (auto i : arr2)
//     {
//         while (umap[i] > 0)
//         {
//             ans.push_back(i);
//             umap[i]--;
//         }
//     }
//     vector<int> temp;
//     for (auto i : umap)
//     {
//         while (i.second)
//         {
//             temp.push_back(i.first);
//             i.second--;
//         }
//     }
//     sort(temp.begin(), temp.end());
//     for (auto i : temp)
//     {
//         ans.push_back(i);
//     }
//     return ans;
// }

// solving the same question using an ordered map
// vector<int> sortAccToOrder(vector<int> arr1, vector<int> arr2, int size1, int size2)
// {
//     map<int, int> omap;
//     vector<int> ans;
//     vector<int> ans;
//     for (auto i : arr1)
//     {
//         omap[i]++;
//     }
//     for (auto i : arr2)
//     {
//         if (omap.find(i) != omap.end())
//         {
//             auto x = omap.find(i);
//             int count = x->second;
//             vector<int> v(count, i);
//             ans.insert(ans.end(), v.begin(), v.end());
//             omap.erase(i);
//         }
//     }
//     for (auto i : omap)
//     {
//         int ele = i.first;
//         int count = i.second;
//         vector<int> v(count, ele);
//         ans.insert(ans.end(), v.begin(), v.end());
//         omap.erase(ele);
//     }
//     return ans;
// }

// Write a program to custom sort a string
// string customSort(string s1, string s2)
// {
//     string ans = "";
//     unordered_map<char, int> umap;
//     for (auto i : s2)
//     {
//         umap[i]++;
//     }
//     for (auto i : s1)
//     {
//         if (umap.find(i) != umap.end())
//         {
//             auto temp = umap.find(i);
//             int count = temp->second;
//             string s(count, i);
//             ans += s;
//             umap.erase(i);
//         }
//     }
//     for (auto i : umap)
//     {
//         char element = i.first;
//         int count = i.second;
//         string s(count, element);
//         ans += s;
//         umap.erase(element);
//     }
//     return ans;
// }

// Write a program to group anagram
// vector<string> groupAnagrams(vector<string> arr)
// {
//     string firstString = arr[0];
//     unordered_set<char, int> uset;
//     for (auto i : firstString)
//     {
//         uset.insert(i);
//     }
//     vector<string> ans;
//     for (int i = 1; i < arr.size(); i++)
//     {
//         string temp = arr[i];
//         bool isSame = true;
//         for (auto i : temp)
//         {
//             if (uset.find(i) == uset.end())
//             {
//                 isSame = false;
//                 break;
//             }
//         }
//         if (isSame)
//         {
//             ans.push_back(temp);
//         }
//     }
//     return ans;
// }
// This is a wrong solution

// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     vector<vector<string>> ans;
//     unordered_map<string, vector<string>> umap;

//     for (auto x : strs)
//     {
//         string temp = x;
//         sort(temp.begin(), temp.end());
//         umap[temp].push_back(x);
//     }

//     for (auto x : umap)
//     {
//         // vector<string> temp = x.second;
//         ans.push_back(x.second);
//     }
//     return ans;
// }

// Sort an array by increasing frequency
// vector<int> frequencySort(vector<int> &nums)
// {
//     unordered_map<int, int> umap;
//     vector<int> ans;
//     map<int, int> omap;
//     for (auto i : nums)
//     {
//         umap[i]++;
//     }
//     for (auto i : umap)
//     {
//         omap[i.second] = i.first;
//     }

//     for (auto i : omap)
//     {
//         vector<int> v(i.first, i.second);
//         ans.insert(ans.end(), v.begin(), v.end());
//     }
//     return ans;
// }

// Working with the lambda function appraoch to solve this problem
// vector<int> frequencySort(vector<int> &nums)
// {
//     unordered_map<int, int> umap;
//     for (auto x : nums)
//     {
//         umap[x]++;
//     }

//     sort(nums.begin(), nums.end(), [&](int a, int b) -> bool
//          { return umap[a] != umap[b] ? umap[a] < umap[b] : a > b; });
//     return nums;
// }

// Implement the lru cache functionality using maps
// class LFUCache
// {
// public:
//     int capacity, minFreq;
//     unordered_map<int, pair<int, int>> keyVal;
//     unordered_map<int, list<int>> freqList;
//     unordered_map<int, list<int>::iterator> pos;

//     LFUCache(int capacity)
//     {
//         this->capacity = capacity;
//         minFreq = 0;
//     }

//     void updateFreq(int key)
//     {
//         int curr_freq = keyVal[key].second;
//         freqList[curr_freq].erase(pos[key]);

//         keyVal[key].second++;
//         curr_freq = keyVal[key].second;

//         freqList[curr_freq].push_back(key);
//         pos[key] = --freqList[curr_freq].end();

//         if (freqList[minFreq].empty())
//         {
//             minFreq++;
//         }
//     }

//     void put(int key, int value)
//     {
//         if (capacity == 0)
//             return;
//         if (keyVal.find(key) != keyVal.end())
//         {
//             keyVal[key].first = value;
//             updateFreq(key);
//             return;
//         }
//         if (keyVal.size() == capacity)
//         {
//             // Find the lru
//             int delKey = freqList[minFreq].front();
//             keyVal.erase(delKey);
//             pos.erase(delKey);
//             freqList[minFreq].pop_front();
//         }
//         keyVal[key] = make_pair(value, 1);
//         freqList[1].push_back(key);
//         pos[key] = --freqList[1].end();
//         minFreq = 1;
//     }

//     int get(int key)
//     {
//         if (keyVal.find(key) == keyVal.end())
//         {
//             return -1;
//         }
//         updateFreq(key);
//         return keyVal[key].first;
//     }
// };

// Write a program to implement the lfu cache functionality again
// class LfuCache
// {
// private:
//     unordered_map<int, pair<int, int>> keyVal;
//     unordered_map<int, list<int>> freqList;
//     unordered_map<int, list<int>::iterator> pos;
//     int capacity;
//     int minFreq;

// public:
//     LfuCache(int c)
//     {
//         this->capacity = c;
//         this->minFreq = 0;
//     }

//     void updateFreq(int key)
//     {
//         int currFreq = keyVal[key].second;
//         auto position = pos[key];
//         freqList[currFreq].erase(position);

//         keyVal[key].second++;
//         currFreq = keyVal[key].second;
//         freqList[currFreq].push_back(key);
//         pos[key] = --freqList[currFreq].end();
//         if (freqList[minFreq].empty())
//         {
//             minFreq++;
//         }
//     }

//     void put(int key, int value)
//     {
//         if (capacity == 0)
//         {
//             return;
//         }
//         if (keyVal.find(key) != keyVal.end())
//         {
//             updateFreq(key);
//             keyVal[key].first = value;
//             return;
//         }
//         if (keyVal.size() == capacity)
//         {
//             int delkey = freqList[minFreq].front();
//             keyVal.erase(delkey);
//             pos.erase(delkey);
//             freqList[minFreq].pop_front();
//         }

//         keyVal[key] = make_pair(value, 1);
//         freqList[1].push_back(key);
//         pos[key] = --freqList[1].end();
//         minFreq = 1;
//         return;
//     }

//     int get(int key)
//     {
//         if (keyVal.find(key) == keyVal.end())
//         {
//             return -1;
//         }
//         else
//         {
//             updateFreq(key);
//             return keyVal[key].first;
//         }
//     }
// };

// Write a program to implement the 2 sum problem
// pair<int, int> twoSum(vector<int> arr, int key)
// {
//     unordered_map<int, int> umap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         umap.insert(make_pair(arr[i], i));
//     }

//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (umap.find(key - arr[i]) != umap.end())
//         {
//             return {umap[key - arr[i]], i};
//         }
//         umap[arr[i]] = i;
//     }
// }
// The time complexity of this solution is O(n) for average case of unordered map insertion and O(n^2) for worst case insertion of elements in unordered map
// The space complexity of this solution is O(n)

// Write a program to solve the 4 sum problem
// int binarySearch(vector<int> &arr, int start, int end, int key)
// {
//     while (start <= end)
//     {
//         int mid = (start + end) / 2;
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         else if (arr[mid] < key)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return 0;
// }

// vector<int> fourSum(vector<int> arr, int key)
// {
//     unordered_map<int, int> umap;
//     for (int i = 0; i < arr.size() - 3; i++)
//     {
//         for (int j = i + 1; j < arr.size() - 2; j++)
//         {
//             for (int k = j + 1; k < arr.size() - 1; k++)
//             {
//                 int target = key - arr[i] - arr[j] - arr[k];
//                 // for (int l = k + 1; l < arr.size(); l++)
//                 // {
//                 //     if (arr[l] == target)
//                 //     {
//                 //         return {i, j, k, l};
//                 //     }
//                 // }
//                 int found = binarySearch(arr, k + 1, arr.size() - 1, target);
//                 if (found)
//                 {
//                     return {i, j, k, found};
//                 }
//             }
//         }
//     }
// }

// Write a program to print the longest consecutive sequence in a given array
// int longestconsecutive(vector<int> arr)
// {
//     unordered_map<int, bool> umap;
//     for (auto i : arr)
//     {
//         umap.insert(make_pair(i, true));
//     }

//     for (auto i : arr)
//     {
//         if (umap.find(i - 1) != umap.end())
//         {
//             umap[i - 1] = false;
//         }
//     }

//     int maxCount = INT_MIN;
//     for (auto i : umap)
//     {
//         if (i.second == true)
//         {
//             int val = 0;
//             int count = 0;
//             while (1)
//             {
//                 if (umap.find(i.first + val) != umap.end())
//                 {
//                     count++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             if (count > maxCount)
//             {
//                 maxCount = count;
//             }
//         }
//     }
//     return maxCount;
// }
// The time complexity of this solution is O(n). In the average case .
// The space complexity of this solution is o(n).

// Write a program to print the largest subarray with the sum 0
// the naive approach to solve this question would be to generate all the subarrays and find the length of the max subarray whose sum comes out to be 0
// The subarrays can be generated using the kadanes algorithm
// The time complexity of this solution will be O(n^3)
// The space complexity of this solution will be O(1)
// int largestSubarrayWith0Sum(vector<int> &arr)
// {
//     unordered_map<int, int> umap;
//     int prefixSum = 0;
//     int ans = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         prefixSum += arr[i];
//         if (prefixSum == 0)
//         {
//             ans = max(ans, i + 1);
//         }
//         if (umap.find(prefixSum) != umap.end())
//         {
//             int length = i - umap[prefixSum];
//             ans = max(length, ans);
//         }
//         else
//         {
//             umap.insert(make_pair(prefixSum, i));
//         }
//     }
//     return ans;
// }
// The time complexity of this solution is O(n).
// The space complexity of this solution is O(n).

// Write a program to count all the subarrays with xor as k
// The naive approach to this problem will be to find all the subarrays using the kadane's algorithm and then count the number of subarrays whose elements xor up to the value of k.
// The time complexity of this naive solution is O(n^3) to generate all the subarrays which can be further optimised to a complexity of O(n^2).

/*











*/

// Write a program to find the longest substring without repeating characters.
// The naive approach to solve this problem will be to find all the substrings using the kaden's algorithm and then find the longest substring with non repeating characters
// the time complexity of this solution will be O(n^3) and O(n^2) after optimization.

// The optimized solution for this problem is:
// int longestSubstring(string s)
// {
//     int left = 0;
//     int right = 0;
//     unordered_set<char> uset;
//     int maxLength = 0;
//     while (left < s.size() and right < s.size())
//     {
//         if (uset.find(s[right]) != uset.end())
//         {
//             uset.erase(s[left]);
//             left++;
//         }
//         else
//         {
//             maxLength = max(maxLength, right - left + 1);
//             uset.insert(s[right]);
//             right++;
//         }
//     }
//     return maxLength;
// }
// The time complexity of this solution is O(2n) which eventually turns out to be O(n).
// The space complexity of this solution is O(n).

// This solution can further be optimized to a solution of accurate O(n) solution using an unordered map.
// int longestSubstring(string s)
// {
//     int left = 0;
//     int right = 0;
//     unordered_map<int, int> umap;
//     int maxLength = 0;
//     while (left < s.size() and right < s.size())
//     {
//         if (umap.find(s[right]) != umap.end() and umap.find(s[right])->second >= left)
//         {
//             auto temp = umap.find(s[right]);
//             left = temp->second + 1;
//         }
//         else
//         {
//             maxLength = max(maxLength, right - left + 1);
//             umap.insert(make_pair(s[right], right));
//             right++;
//         }
//     }
// }
// The time complexity of this solution is O(n).
// The space complexity of this solution is O(n).

// Write a program to solve the job scheduling problem
// class Job
// {
// public:
//     int id;
//     int profit;
//     int deadline;
// };

// bool comparison(Job a, Job b)
// {
//     return a.profit > b.profit;
// }

// pair<int, int> JobScheduling(Job arr[], int n)
// {
//     // sort(arr,arr+n,comparison);
//     sort(arr, arr + n, [&](Job a, Job b) -> bool
//          { return a.profit > b.profit; });

//     int maxi = arr[0].deadline;
//     for (int i = 1; i < n; i++)
//     {
//         maxi = max(maxi, arr[i].deadline);
//     }

//     int slot[maxi + 1];
//     for (int i = 0; i <= maxi; i++)
//     {
//         slot[i] = -1;
//     }

//     int countJobs = 0;
//     int jobProfit = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = arr[i].deadline; j > 0; j--)
//         {
//             if (slot[j] == -1)
//             {
//                 slot[j] = i;
//                 countJobs++;
//                 jobProfit += arr[i].profit;
//                 break;
//             }
//         }
//     }

//     return make_pair(countJobs, jobProfit);
// }

// the whole solution lies on the concept that you want to perform the maximum profit job as late as possible i.e. its deadline so that in the rest of the days you can perform the rest of the jobs with the smaller profits.
// Write a program to implement lfu cache system
// class lfucache
// {
//     unordered_map<int, pair<int, int>> keyValue;
//     unordered_map<int, list<int>> freqList;
//     unordered_map<int, list<int>::iterator> pos;
//     int minFreq;
//     int capacity;

// public:
//     lfucache(int c)
//     {
//         this->capacity = c;
//         minFreq = 0;
//     }

//     void updateFreq(int key)
//     {
//         int currentFreq = keyValue[key].second;
//         auto position = pos[key];
//         freqList[currentFreq].erase(position);

//         keyValue[key].second++;
//         currentFreq = keyValue[key].second;
//         freqList[currentFreq].push_back(key);
//         pos[key] = --freqList[currentFreq].end();
//         if (freqList[minFreq].empty())
//         {
//             minFreq++;
//         }
//     }

//     void put(int key, int value)
//     {
//         if (capacity == 0)
//             return;

//         if (keyValue.find(key) != keyValue.end())
//         {
//             updateFreq(key);
//             keyValue[key].first = value;
//             return;
//         }

//         if (keyValue.size() == capacity)
//         {
//             int delKey = freqList[minFreq].front();
//             keyValue.erase(delKey);
//             pos.erase(delKey);
//             freqList[minFreq].pop_front();
//         }

//         keyValue[key] = make_pair(value, 1);
//         freqList[1].push_back(key);
//         pos[key] = --freqList[1].end();
//         minFreq = 1;
//     }

//     int get(int key)
//     {
//         if (keyValue.find(key) == keyValue.end())
//         {
//             return -1;
//         }
//         else
//         {
//             updateFreq(key);
//             return keyValue[key].first;
//         }
//     }
// };

// Write a program to implement the lru cache structure
// class lruCache
// {
// public:
//     class node
//     {
//     public:
//         int key;
//         int val;
//         node *next;
//         node *prev;
//         node(int _key, int _val)
//         {
//             key = _key;
//             val = _val;
//         }
//     };

//     node *head = new node(-1, -1);
//     node *tail = new node(-1, -1);
//     int cap;
//     unordered_map<int, node *> umap;

//     lruCache(int capacity)
//     {
//         cap = capacity;
//         head->next = tail;
//         tail->prev = head;
//     }

//     void addnode(node *newnode)
//     {
//         node *temp = head->next;
//         newnode->next = temp;
//         newnode->prev = head;
//         head->next = newnode;
//         temp->prev = newnode;
//     }

//     void deletenode(node *delnode)
//     {
//         node *delprev = delnode->prev;
//         node *delnext = delnode->next;
//         delprev->next = delnext;
//         delnext->prev = delprev;
//         delete delnode;
//     }

//     int get(int key)
//     {
//         if (umap.find(key) != umap.end())
//         {
//             node *resnode = umap[key];
//             int res = resnode->val;
//             umap.erase(key);
//             deletenode(resnode);
//             addnode(resnode);
//             umap[key] = head->next;
//             return res;
//         }
//         return -1;
//     }

//     void put(int key, int value)
//     {
//         if (umap.find(key) != umap.end())
//         {
//             node *existingnode = umap[key];
//             umap.erase(key);
//             deletenode(existingnode);
//         }
//         if (umap.size() == cap)
//         {
//             umap.erase(tail->prev->key);
//             deletenode(tail->prev);
//         }
//         addnode(new node(key, value));
//         umap[key] = head->next;
//     }
// };

// // Implementing the same class using stl
// class lrucache
// {
// public:
//     list<int> elements;
//     unordered_map<int, list<int>::iterator> umap;
//     int capacity;

//     lrucache(int c)
//     {
//         capacity = c;
//     }

//     void put(int key, int value)
//     {
//         if (capacity == 0)
//         {
//             return;
//         }

//         if (umap.find(key) != umap.end())
//         {
//             elements.erase(umap[key]);
//             elements.push_front(key);
//             umap[key] = elements.begin();
//             return;
//         }

//         if (umap.size() == capacity)
//         {
//             auto temp = --elements.end();
//             int key = *temp;
//             umap.erase(key);
//             elements.pop_back();
//         }

//         elements.push_front(key);
//         umap[key] = elements.begin();
//     }

//     int get(int key)
//     {
//         if (umap.find(key) == umap.end())
//         {
//             return -1;
//         }
//         else
//         {
//             elements.erase(umap[key]);
//             elements.push_front(key);
//             umap[key] = elements.begin();
//             return key;
//         }
//     }
// };

// // Write a program to implement the lru cache structure
// class LruCache
// {
// public:
//     list<int> elements;
//     unordered_map<int, list<int>::iterator> umap;
//     int capacity;

//     LruCache(int c)
//     {
//         this->capacity = c;
//     }

//     void put(int key, int value)
//     {
//         if (capacity == 0)
//         {
//             return;
//         }
//         if (umap.find(key) != umap.end())
//         {
//             elements.erase(umap[key]);
//             elements.push_back(key);
//             umap[key] = elements.begin();
//             return;
//         }

//         if (umap.size() == capacity)
//         {
//             auto temp = --elements.end();
//             int delKey = *temp;
//             umap.erase(delKey);
//             elements.pop_back();
//         }

//         elements.push_front(key);
//         umap[key] = elements.begin();
//     }

//     int get(int key)
//     {
//         if (umap.find(key) == umap.end())
//         {
//             return -1;
//         }
//         else
//         {
//             elements.erase(umap[key]);
//             elements.push_front(key);
//             umap[key] = elements.begin();
//             return key;
//         }
//     }
// };

// // Write a program to implement the lfu cache structure
// class Lfucache
// {
//     unordered_map<int, pair<int, int>> keyVal;
//     unordered_map<int, list<int>> freqlist;
//     unordered_map<int, list<int>::iterator> pos;
//     int capacity;
//     int minFreq;

// public:
//     Lfucache(int c)
//     {
//         this->capacity = c;
//         this->minFreq = 0;
//     }

//     void updateFreq(int key)
//     {
//         int currentFreq = keyVal[key].second;
//         auto position = pos[key];
//         freqlist[currentFreq].erase(position);

//         keyVal[key].second++;
//         currentFreq = keyVal[key].second;

//         freqlist[currentFreq].push_back(key);
//         pos[key] = --freqlist[currentFreq].end();
//         if (freqlist[minFreq].empty())
//         {
//             minFreq++;
//         }
//     }

//     void put(int key, int val)
//     {
//         if (capacity == 0)
//         {
//             return;
//         }

//         if (keyVal.find(key) != keyVal.end())
//         {
//             updateFreq(key);
//             keyVal[key].first = val;
//             return;
//         }

//         if (keyVal.size() == capacity)
//         {
//             int delKey = freqlist[minFreq].front();
//             freqlist[minFreq].pop_front();
//             keyVal.erase(delKey);
//             pos.erase(delKey);
//         }

//         keyVal[key] = make_pair(val, 1);
//         freqlist[1].push_back(key);
//         pos[key] = --freqlist[1].end();
//         minFreq = 1;
//     }

//     int get(int key)
//     {
//         if (keyVal.find(key) == keyVal.end())
//         {
//             return -1;
//         }
//         updateFreq(key);
//         return keyVal[key].first;
//     }
// };

int main()
{
    return 0;
}

// life is not about achieving things. it is about process. ~ prince
// life is not about achieving things. it is about process. ~ prince
// life is not about achieving things. It is about process. ~ prince
// life is not about achieving things. It is about process. ~ prince
// nothing is easy nothing is hard , it is all about practice . the more you practice the more easy the concept become.
// Enjoy the journey. Don't chase the destination.
// enjoy the journey. don't chase the destination.
// Enjoy the journey. Don't chase the destination.
// Enjoy the journey. Don't chase the destination.
// Enjoy the journey. Don't chase the destination.

// List is a data type in stl which is used to make doubly linked list.