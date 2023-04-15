// level 2 practice hash maps and heaps pep coding
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>

using namespace std;
// // Write a program to implement lru and the lfu cache data structures
// class lruCache
// {
//     list<int> elements;
//     unordered_map<int, list<int>::iterator> umap;
//     int capacity;

// public:
//     lruCache(int c)
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
//             elements.push_front(key);
//             umap[key] = elements.begin();
//             return;
//         }
//         if (umap.size() == capacity)
//         {
//             auto delElement = --elements.end();
//             int delkey = *delElement;
//             umap.erase(delkey);
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

// // Write a program to implement the lfu cache datastructure
// class lfuCache
// {
// private:
//     unordered_map<int, pair<int, int>> keyVal;
//     unordered_map<int, list<int>> freqList;
//     unordered_map<int, list<int>::iterator> position;
//     int capacity;
//     int minFreq;

// public:
//     lfuCache(int c)
//     {
//         this->capacity = c;
//         this->minFreq = 0;
//     }

//     void updateFreq(int key)
//     {
//         int currentFreq = keyVal[key].second;
//         auto pos = position[key];

//         freqList[currentFreq].erase(pos);

//         keyVal[key].second++;
//         currentFreq = keyVal[key].second;

//         freqList[currentFreq].push_back(key);
//         position[key] = --freqList[currentFreq].end();

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
//             position.erase(delkey);
//             freqList[minFreq].pop_front();
//         }
//         keyVal[key] = make_pair(value, 1);
//         freqList[1].push_back(key);
//         position[key] = --freqList[1].end();
//         minFreq = 1;
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

// // In today's problems we will be studying about the acquire and the release method on hashmaps to solve the problems.

// class sample
// {
// private:
//     int a;
//     int b;
//     string s;

// public:
//     sample(int a, int b, string s)
//     {
//         this->a = a;
//         this->b = b;
//         this->s = s;
//     }

//     int operator+()
//     {
//     }

//     int equals()
//     {
//     }
// };

// // Write a program to implement the LRU cache data structure
// class lruCache
// {
//     list<int> elements;
//     unordered_map<int, list<int>::iterator> umap;
//     int capacity;

// public:
//     lruCache(int c)
//     {
//         this->capacity = c;
//     }

//     void put(int key, int value)
//     {
//         if (capacity == 0)
//             return;
//         if (umap.find(key) != umap.end())
//         {
//             elements.erase(umap[key]);
//             elements.push_front(key);
//             umap[key] = elements.begin();
//             return;
//         }
//         if (umap.size() == capacity)
//         {
//             int delkey = *(--elements.end());
//             umap.erase(delkey);
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

// // Write a program to find the number of distinct elemts in every window of size k
// vector<int> distinctElements(vector<int> arr, int size, int k)
// {
//     unordered_map<int, int> umap;
//     vector<int> ans;
//     // hashing the k-1 elements in the map
//     for (int i = 0; i < k - 1; i++)
//     {
//         umap[arr[i]]++;
//     }

//     for (int i = k - 1, j = 0; i < size; i++, j++)
//     {
//         // acquiring section
//         umap[arr[i]]++;

//         // adding the size to solution
//         ans.push_back(umap.size());

//         // releasing section
//         umap[arr[j]]--;
//         if (umap[arr[j]] == 0)
//         {
//             umap.erase(arr[j]);
//         }
//     }
//     // returning the solution
//     return ans;
// }
// // The time complexity of this solution is O(n)
// // The space complexity of this solution is O(k)

// // Write a program to print the largest sub array with 0 sum.

// // we will use the concept that if the sum of an array repeats then the sub of the remaining array is 0
// int largestWith0Sum(vector<int> arr, int size)
// {
//     unordered_map<int, int> umap;
//     umap.insert(0, -1);
//     int sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//         if (sum == 0)
//         {
//             maxLen = i;
//         }
//         else if (umap.find(sum) != umap.end())
//         {
//             int index = umap[sum];
//             maxLen = max(maxLen, i - index);
//         }
//         else
//         {
//             umap.insert(sum, i);
//         }
//     }
//     return maxLen;
// }

// // Write a program to find the count of all the subarrays with 0 sum
// int count0Sum(vector<int> arr, int size)
// {
//     int count = 0;
//     unordered_map<int, int> umap;
//     umap.insert(0, 1);
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//         if (umap.find(sum) != umap.end())
//         {
//             int temp = umap[sum];
//             count += temp;
//             umap[sum]++;
//         }
//         else
//         {
//             umap.insert(make_pair(sum, 1));
//         }
//     }

//     return count;
// }
// // The time complexity of this solution is O(n).
// // The space complexity of this solution is O(n).

// // Write a program to count the length of the largest subarray with contiguous elements.
// int largestContiguousSubarray(vector<int> arr, int size)
// {
//     int maxLen = 0;
//     for (int i = 0; i < size - 1; i++)
//     {
//         int maxi = arr[i];
//         int mini = arr[i];
//         unordered_set<int> uset;
//         uset.insert(arr[i]);
//         for (int j = i + 1; j < size; j++)
//         {
//             if (uset.find(arr[j]) != uset.end())
//             {
//                 break;
//             }
//             uset.insert(arr[j]);
//             if (maxi < arr[i])
//             {
//                 maxi = arr[i];
//             }
//             if (mini > arr[i])
//             {
//                 mini = arr[i];
//             }

//             if (maxi - mini == j - i)
//             {
//                 maxLen = max(maxLen, j - i);
//             }
//         }
//     }
//     return maxLen;
// }
// // The time complexity of this solution is O(n)
// // The space complexity of this solution is O(n)

// // Write a program to find the minimum window substring which contains all the elements of another string s2
// int minimumWindowSubstring(string s1, string s2)
// {
//     unordered_map<char, int> umap2;
//     int tomatch = 0;
//     for (char element : s2)
//     {
//         umap2[element]++;
//         tomatch++;
//     }

//     int minLen = INT_MAX;

//     int matchcount = 0;
//     int i = -1;
//     int j = -1;
//     unordered_map<char, int> umap1;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < s1.size())
//         {
//             f1 = true;
//             i++;
//             umap1[s1[i]]++;
//             if (umap1[s1[i]] <= umap2[s1[i]])
//             {
//                 matchcount++;
//             }

//             if (matchcount == tomatch)
//             {
//                 int len = i - j;
//                 minLen = min(minLen, len);
//                 break;
//             }
//         }

//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap1[s1[j]]--;

//             if (umap1[s1[j]] < umap2[s1[j]])
//             {
//                 matchcount--;
//                 break;
//             }

//             int len = i - j;
//             minLen = min(minLen, len);
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return minLen;
// }

// // Write a program to find the smallest substring of a string containing all unique characters of itself
// string smallestSubstring(string s)
// {
//     unordered_set<char> uset;
//     for (auto element : s)
//     {
//         uset.insert(element);
//     }

//     unordered_map<char, int> umap;
//     int minLength = INT_MAX;
//     int i = -1;
//     int j = -1;
//     string ans;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         // acquire till it is invalid (map.size() < set.size())
//         while (i < s.length())
//         {
//             f1 = true;
//             i++;
//             umap[s[i]]++;

//             if (umap.size() == uset.size())
//             {
//                 int len = i - j;
//                 if (len < minLength)
//                 {
//                     minLength = len;
//                     ans = s.substr(j + 1, i + 1);
//                 }
//                 break;
//             }
//         }

//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap[s[j]]--;
//             if (umap[s[j]] == 0)
//             {
//                 umap.erase(s[j]);
//             }

//             if (umap.size() < uset.size())
//             {
//                 break;
//             }

//             int len = i - j;
//             if (len < minLength)
//             {
//                 minLength = len;
//                 ans = s.substr(j + 1, i + 1);
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return ans;
// }

// // Write a program to print the longest substring with the non repeating characters
// // acquire until you become valid and release until you become valid.
// int nonRepeatingCharacters(string str)
// {
//     unordered_map<char, int> umap;
//     int i = -1;
//     int j = -1;
//     int maxLen = 0;

//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         // acquiring the elements
//         while (i < str.size())
//         {
//             f1 = true;
//             i++;
//             umap[str[i]]++;
//             if (umap[str[i]] == 2)
//             {
//                 break;
//             }

//             int len = i - j;
//             maxLen = max(len, maxLen);
//         }

//         // releasing the elements
//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap[str[j]]--;
//             if (umap[str[j]] == 1) // this can also be evaluated using the condition if(umap[str[i]] == 1)
//             {
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return maxLen;
// }
// // The time complexity of this solution is O(n)
// // The space complexity of this solution is O(n)

// // Write a program to count substrings having non repeating characters
// int countNonRepeating(string str)
// {
//     unordered_map<char, int> umap;
//     int i = -1;
//     int j = -1;
//     int count = 0;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < umap.size())
//         {
//             f1 = true;
//             i++;
//             umap[str[i]]++;
//             if (umap[str[i]] == 2)
//             {
//                 break;
//             }

//             count += i - j;
//         }
//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap[str[j]]--;

//             if (umap[str[i]] == 1)
//             {
//                 count += i - j;
//                 break;
//             }
//         }
//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return count;
// }

// // Write a program to find the length of the longest substring with exactly k unique characters
// int longestSubstring(string s, int k)
// {
//     unordered_map<char, int> umap;
//     int i = -1;
//     int j = -1;
//     int maxLen = 0;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         // acquiring section
//         while (i < s.length())
//         {
//             f1 = true;
//             i++;
//             umap[i]++;
//             if (umap.size() < k)
//             {
//                 continue;
//             }
//             else if (umap.size() == k)
//             {
//                 int len = i - j;
//                 maxLen = max(maxLen, len);
//             }
//             else
//             {
//                 break;
//             }
//         }

//         // release section
//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap[j]--;

//             if (umap.size() == k)
//             {
//                 int len = i - j;
//                 maxLen = max(maxLen, len);
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return maxLen;
// }

// // Write a program to find the number of substrings having exactly k unique characters
// int countUnique(string str, int k)
// {
//     unordered_map<int, int> umap;
//     int i = -1;
//     int j = -1;
//     int count = 0;

//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         // acquiring section
//         while (i < str.length())
//         {
//             f1 = true;
//             i++;
//             umap[str[i]]++;
//             if (umap.size() < k)
//             {
//                 continue;
//             }
//             else if (umap.size() == k)
//             {
//                 count++;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         // release section
//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap[str[j]]--;
//             if (umap[str[j]] == 0)
//             {
//                 umap.erase(str[j]);
//             }

//             if (umap.size() == k)
//             {
//                 count++;
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return count;
// }

// // This solution is ambiguous for now so i would prefer to see the solution given below.

// // We will solve this problem using the three pointer appraoch where two pointers will be used for acquiring process and one pointer will be used for releasing from both the maps.
// int solve(string &str, int k)
// {
//     unordered_map<char, int> umap;
//     int i = -1;
//     int j = -1;
//     int count = 0;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < str.size())
//         {
//             f1 = true;
//             i++;
//             umap[i]++;
//             if (umap.size() == k)
//             {
//                 continue;
//             }
//             else
//             {
//                 umap[i]--;
//                 i--;
//                 break;
//             }
//         }

//         while (j < i)
//         {
//             f2 = true;
//             if (umap.size() == 1)
//             {
//                 count += i - j;
//             }

//             j++;
//             umap[str[j]]--;

//             if (umap.size() == 0)
//             {
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return count;
// }
// int solution(string str, int k)
// {

//     if (k == 1)
//     {
//         return solve(str, k);
//     }
//     int ans = 0;

//     unordered_map<char, int> umaps;
//     unordered_map<char, int> umapl;
//     int is = -1;
//     int il = -1;
//     int j = -1;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         bool f3 = false;

//         while (il < str.length())
//         {
//             f1 = true;
//             il++;
//             umapl[il++];

//             if (umapl.size() <= k)
//             {
//                 continue;
//             }
//             else if (umapl.size() > k)
//             {
//                 umapl[il]--;
//                 il--;
//                 break;
//             }
//         }

//         while (is < il)
//         {
//             f2 = true;
//             is++;
//             umaps[is]++;

//             if (umaps.size() <= k - 1)
//             {
//                 continue;
//             }
//             else if (umaps.size() > k - 1)
//             {
//                 umaps[is]--;
//                 is--;
//                 break;
//             }
//         }

//         while (j < is)
//         {
//             f3 = true;
//             if (umapl.size() == k && umaps.size() == k - 1)
//                 ans += il - is;

//             j++;
//             umaps[j]--;
//             umapl[j]--;

//             if (umaps.size() < k - 1 || umapl.size() < k)
//             {
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false && f3 == false)
//         {
//             break;
//         }
//     }
//     return ans;
// }

// // Write a program to print the count of equivalent subarrays i.e. the sub arrays having equal number of distinct elements as there are in the whole array
// int countSubarrays(vector<int> arr, int size)
// {
//     unordered_set<int> uset;
//     for (auto element : arr)
//     {
//         uset.insert(element);
//     }

//     int k = uset.size();
//     unordered_map<int, int> umap;
//     int i = -1;
//     int j = -1;
//     int count = 0;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < arr.size())
//         {
//             f1 = true;
//             i++;
//             umap[arr[i]]++;
//             if (umap.size() == k)
//             {
//                 break;
//             }
//         }

//         while (j < i)
//         {
//             f2 = true;
//             if (umap.size() == k)
//             {
//                 count += arr.size() - i;
//             }

//             j++;
//             umap[arr[j]]--;
//             if (umap.size() < k)
//             {
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }

//     return count;
// }
// // Time complexity O(n).
// // Space complexity O(n).

// // Write a program to solve the problem of maximum consecutive ones
// int maxConsecutiveOnes(vector<int> arr, int k)
// {
//     unordered_map<int, int> umap;
//     int i = -1;
//     int j = -1;
//     int maxLen = 0;
//     int zcount = 0;

//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < arr.size())
//         {
//             f1 = true;
//             i++;
//             if (arr[i] == 1)
//             {
//                 int len = i - j;
//                 maxLen = max(maxLen, len);
//             }
//             else
//             {
//                 zcount++;
//                 if (zcount <= k)
//                 {
//                     int len = i - j;
//                     maxLen = max(maxLen, len);
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }

//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             if (arr[j] == 0)
//             {
//                 zcount--;
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return maxLen;
// }

// // Write a program to solve the problem of maximum consecutive ones
// int maxConsecutiveOnes1(vector<int> arr)
// {
//     int maxLen = 0;
//     int zcount = 0;
//     int i = -1;
//     int j = -1;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < arr.size())
//         {
//             f1 = true;
//             i++;
//             if (arr[i] == 0)
//             {
//                 zcount++;
//                 if (zcount > 1)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     int len = i - j;
//                     maxLen = max(maxLen, len);
//                 }
//             }
//             else
//             {
//                 int len = i - j;
//                 maxLen = max(maxLen, len);
//             }
//         }

//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             if (arr[j] == 0)
//             {
//                 zcount--;
//                 if (zcount <= 1)
//                 {
//                     int len = i - j;
//                     maxLen = max(maxLen, len);
//                     break;
//                 }
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return maxLen;
// }

// // Write a program to find the longest substring with at most k unique characters
// int longestSubstring(string str, int k)
// {
//     unordered_map<char, int> umap;
//     int i = -1;
//     int j = -1;
//     int maxLen = 0;
//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         while (i < str.length())
//         {
//             f1 = true;
//             i++;
//             umap[i]++;
//             if (umap.size() > k)
//             {
//                 break;
//             }
//             int len = i - j;
//             maxLen = max(maxLen, len);
//         }

//         while (j < i)
//         {
//             f2 = true;
//             j++;
//             umap[j]--;

//             if (umap.size() == k)
//             {
//                 maxLen = max(maxLen, i - j);
//                 break;
//             }
//         }

//         if (f1 == false && f2 == false)
//         {
//             break;
//         }
//     }
//     return maxLen;
// }

// // Write a program to count the substrings with at most k distinct characters
// int countSubstrings(string str, int k)
// {
//     int i = -1;
//     int j = -1;
//     unordered_map<int, int> umap;
//     int count = 0;
//     while (true)
//     {
//         while (i < str.size())
//         {
//             i++;
//             umap[i]++;
//             if (umap.size() <= k)
//             {
//                 count += i - j;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         if (i == str.length() && umap.size() <= k)
//         {
//             break;
//         }

//         while (j < i)
//         {
//             j++;
//             umap[j]--;
//             if (umap.size() == k)
//             {
//                 count += i - j;
//                 break;
//             }
//         }
//     }
//     return count;
// }

// // Write a program to find all the anagrams in a string
// vector<pair<int, int>> findAnagrams(string s, string p)
// {
//     unordered_map<char, int> pmap;
//     unordered_map<char, int> smap;
//     vector<pair<int, int>> ans;
//     int count = 0;

//     for (int i = 0; i < p.length(); i++)
//     {
//         pmap[p[i]]++;
//     }
//     int k = p.length();
//     for (int i = 0; i < k - 1; i++)
//     {
//         smap[s[i]]++;
//     }

//     for (int i = k - 1, j = 0; i < s.length(); i++, j++)
//     {
//         smap[s[i]]++;
//         if (smap == pmap)
//         {
//             count++;
//             ans.push_back(make_pair(count, j));
//         }
//         smap[s[j]]--;
//     }
//     return ans;
// }

// // Write a program to solve the problem of k anagrams
// bool kAnagrams(string s1, string s2, int k)
// {
//     if (s1.length() != s2.length())
//     {
//         return false;
//     }
//     unordered_map<char, int> umap;
//     for (auto element : s1)
//     {
//         umap[element]++;
//     }

//     for (auto element : s2)
//     {
//         if (umap.find(element) != umap.end())
//         {
//             umap[element]--;
//         }
//     }

//     int count = 0;
//     for (auto i : umap)
//     {
//         if (i.second > 0)
//         {
//             count++;
//         }
//     }
//     if (count <= k)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// // Write a program to find the anagram mappings
// vector<int> anagramMappings(vector<int> arr1, vector<int> arr2)
// {
//     unordered_map<int, list<int>> umap;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         umap[arr1[i]].push_back(i);
//     }

//     vector<int> ans;
//     for (int i = 0; i < arr2.size(); i++)
//     {
//         ans.push_back(umap[arr2[i]].front());
//         umap[arr2[i]].pop_front();
//     }

//     return ans;
// }

// // Write a program to check whether the two given strings are valid anagrams or not
// bool validAnagrams(string s1, string s2)
// {
//     if (s1.length() != s2.length())
//         return false;
//     unordered_map<char, int> umap;
//     for (auto element : s1)
//     {
//         umap[element]++;
//     }
//     for (auto element : s2)
//     {
//         if (umap.find(element) == umap.end())
//         {
//             return false;
//         }
//         else
//         {
//             umap[element]--;
//             if (umap[element] == 0)
//             {
//                 umap.erase(element);
//             }
//         }
//     }
//     return true;
// }

// // // Write a program for gouping the anagrams
// // vector<vector<string>> groupAnagrams(vector<string> arr)
// // {
// //     unordered_map<unordered_map<char, int>, list<string>> umap;
// // }

// // You need to view this question again to solve the unordered_map<unordered_map<char,int>,list<string>> umap; problem

// string getKey(string str)
// {
//     string key = "";

//     for (int i = 1; i < str.length(); i++)
//     {
//         char curr = str[i];
//         char prev = str[i - 1];

//         int diff = curr - prev;
//         if (diff < 0)
//         {
//             diff += 26;
//         }

//         key += diff + "#";
//     }

//     key += ".";
//     return key;
// }

// vector<vector<string>> groupShiftedStrings(vector<string> strs)
// {
//     unordered_map<string, vector<string>> umap;

//     for (string str : strs)
//     {
//         string key = getKey(str);

//         if (umap.find(key) == umap.end())
//         {
//             umap[key].push_back(str);
//         }
//         else
//         {
//             umap[key].push_back(str);
//         }
//     }
//     vector<vector<string>> ans;
//     for (auto i : umap)
//     {
//         ans.push_back(i.second);
//     }
//     return ans;
// }

// // Write a program to check whether the given two strings are isomorphic or not.
// bool isIsomorphic(unordered_map<char, char> mapping)
// {
//     unordered_map<char, char> umap1;
//     unordered_map<char, bool> used;
//     for (auto i : mapping)
//     {
//         if (umap1.find(i.first) != umap1.end())
//         {
//             if (umap1[i.first] != i.second)
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             if (used.find(i.second) != used.end())
//             {
//                 return false;
//             }
//             else
//             {
//                 umap1.insert(make_pair(i.first, i.second));
//                 used.insert(make_pair(i.second, true));
//             }
//         }
//     }
//     return true;
// }

// // Write a program to solve the word pattern problem
// bool wordPattern(vector<char> a, vector<string> b)
// {
//     unordered_map<char, string> umap1;
//     unordered_map<string, bool> used;
//     if (a.size() != b.size())
//     {
//         return false;
//     }
//     for (int i = 0; i < a.size(); i++)
//     {
//         int ch = a[i];
//         string str = b[i];
//         if (umap1.find(ch) != umap1.end())
//         {
//             if (umap1[ch] != str)
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             if (used.find(str) != used.end())
//             {
//                 return false;
//             }
//             else
//             {
//                 umap1.insert(make_pair(ch, str));
//                 used.insert(make_pair(str, true));
//             }
//         }
//     }
//     return true;
// }

// // Write a program to solve the subarray sum equals k problem. i.e. count subarrays with sum equals k.
// int countSubarrays(vector<int> arr, int k)
// {
//     int preSum = 0;
//     int count = 0;
//     unordered_map<int, int> umap;
//     umap.insert(0, 1);
//     for (int i = 0; i < arr.size(); i++)
//     {
//         preSum += arr[i];
//         int target = preSum - k;
//         if (umap.find(target) != umap.end())
//         {
//             count += umap[target];
//         }
//         umap[preSum]++;
//     }

//     return count;
// }
// // The time and space complexity of this solution are O(n) and O(n) respectively.

// // Write a program to calculate the longest subarray with sum divisible by k.
// int longestSubarray(vector<int> arr, int k)
// {
//     unordered_map<int, int> umap;
//     int maxLen = 0;
//     umap.insert(make_pair(0, -1));
//     int preSum = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         preSum += arr[i];
//         int rem = preSum % k;
//         if (rem < 0)
//         {
//             rem += k;
//         }

//         if (umap.find(rem) != umap.end())
//         {
//             int j = umap[rem];
//             int len = i - j;
//             maxLen = max(maxLen, len);
//         }
//         else
//         {
//             umap.insert(make_pair(rem, i));
//         }
//     }
//     return maxLen;
// }

// // Write a program to print the count of subarrays with sum divisible by k.
// int countSubarray(vector<int> arr, int k)
// {
//     unordered_map<int, int> umap;
//     int count = 0;
//     umap.insert(0, 1);
//     int preSum = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         preSum += arr[i];
//         int rem = preSum % k;
//         if (rem < 0)
//         {
//             rem += k;
//         }

//         if (umap.find(rem) != umap.end())
//         {
//             count += umap[rem];
//         }
//         umap[rem]++;
//     }
//     return count;
// }

// // Write a program to print the longest subarray with equal number of 0's and 1's.
// int longestSubarray(vector<int> arr)
// {
//     unordered_map<int, int> umap;
//     umap.insert(make_pair(0, -1));
//     int preSum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == 0)
//         {
//             preSum += -1;
//         }
//         else
//         {
//             preSum += 1;
//         }

//         if (umap.find(preSum) != umap.end())
//         {
//             int j = umap[preSum];
//             int len = i - j;
//             maxLen = max(maxLen, len);
//         }
//         else
//         {
//             umap.insert(make_pair(preSum, i));
//         }
//     }
//     return maxLen;
// }

// // Write a program to count the total number of subarrays with equal number of 0's and 1's
// int countSubarray(vector<int> arr)
// {
//     unordered_map<int, int> umap;
//     int presum = 0;
//     int count = 0;
//     umap.insert(make_pair(0, 1));
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == 0)
//         {
//             presum += -1;
//         }
//         else
//         {
//             presum += 1;
//         }

//         if (umap.find(presum) != umap.end())
//         {
//             count += umap[presum];
//         }
//         umap[presum]++;
//     }
//     return count;
// }

// // Write a program to find the longest subarray with equal number of 0's 1's and 2's.
// int longestSubarray(vector<int> arr)
// {
//     unordered_map<string, int> umap;
//     int c0;
//     int c1;
//     int c2;
//     int maxLen = 0;
//     umap.insert(make_pair("0#0", -1));
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == 0)
//         {
//             c0++;
//         }
//         else if (arr[i] == 1)
//         {
//             c1++;
//         }
//         else
//         {
//             c2++;
//         }

//         int d10 = c1 - c0;
//         int d21 = c2 - c1;
//         string key = d10 + "#" + d21;

//         if (umap.find(key) != umap.end())
//         {
//             int j = umap[key];
//             int len = i - j;
//             maxLen = max(maxLen, len);
//         }
//         else
//         {
//             umap.insert(make_pair(key, i));
//         }
//     }
//     return maxLen;
// }

// // Write a program to find the count of subarrays with equal number of 0's 1's and 2's
// int countSubarray(vector<int> arr)
// {
//     int c0 = 0;
//     int c1 = 0;
//     int c2 = 0;
//     unordered_map<string, int> umap;
//     int count = 0;
//     umap.insert(make_pair("0#0", 1));
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == 0)
//         {
//             c0++;
//         }
//         else if (arr[i] == 1)
//         {
//             c1++;
//         }
//         else
//         {
//             c2++;
//         }

//         int d10 = c1 - c0;
//         int d21 = c2 - c1;
//         string key = d10 + "#" + d21;

//         if (umap.find(key) != umap.end())
//         {
//             count += umap[key];
//         }
//         umap[key]++;
//     }
//     return count;
// }

// // Write a program to check whether there exists two pairs in the array where a + b = c + d
// bool solution(vector<int> arr)
// {
//     unordered_set<int> uset;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             int sum = arr[i] + arr[j];
//             if (uset.find(sum) != uset.end())
//             {
//                 return true;
//             }
//             uset.insert(sum);
//         }
//     }
//     return false;
// }
// // The time complexity of this solution is O(n^2)

// // the easier problem of this question will be to find whether there exists a pair whose sum is equal to the target value. It's time complexity would be O(n).

// // Write a program to convert a fraction to a recurring decimal
// string fractionToRecurringDecimal(int num, int den)
// {
//     int q = num / den;
//     int r = num % den;
//     if (r == 0)
//     {
//         return to_string(q);
//     }

//     string ans = "";
//     ans += q;
//     ans += ".";
//     unordered_map<char, int> umap;
//     while (r && umap.find(r) == umap.end())
//     {
//         umap.insert(make_pair(r, ans.length()));
//         r = r * 10;
//         q = r / den;
//         r = r % den;
//         ans += q;
//     }

//     if (r)
//     {
//         ans.insert(umap[r], "(");
//         ans.append(")");
//     }
//     return ans;
// }
// // The time complexity of this solution is O(den).
// // The space complexity of this solution is O(den).

// // Write a program to solve the rabbits in a forest problem.
// // Write a program to count the total number of rabbits in a forest where a few of the rabbits reported and a few of them did not reported at all.
// int countRabbits(vector<int> arr)
// {
//     int count = 0;
//     unordered_map<int, int> umap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         umap[arr[i] + 1]++;
//     }

//     for (auto i : umap)
//     {
//         int groupStrength = i.first;
//         int reportingRabbits = i.second;

//         int x = int(ceil(float(reportingRabbits) / float(groupStrength)));
//         int totalRabbits = x * groupStrength;
//         count += totalRabbits;
//     }
//     return count;
// }
// // The time complexity of this solution is O(n).
// // The space complexity of this solution is O(n).

// // Write a program to check whether the given array is an arithmetic sequence or not.
// bool isAP(vector<int> arr)
// {
//     if (arr.size() <= 1)
//     {
//         return true;
//     }
//     int min = arr[0];
//     int max = arr[0];
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//         }
//         if (max < arr[i])
//         {
//             max = arr[i];
//         }
//     }
//     int n = arr.size();

//     int cd = (max - min) / (cd - 1);
//     unordered_set<int> uset;
//     for (int i = 0; i < n; i++)
//     {
//         uset.insert(arr[i]);
//     }

//     for (int i = min; i <= max; i += cd)
//     {
//         if (uset.find(i) == uset.end())
//         {
//             return false;
//         }
//     }
//     return true;
// }

// vector<int> smallestWithHighestFrequency(vector<int> arr)
// {
//     unordered_map<int, int> freq;
//     unordered_map<int, int> fomap;
//     int start = 0;
//     int end = 0;
//     int highestFreq = 0;
//     int length = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int ele = arr[i];
//         if (freq.find(ele) != freq.end())
//         {
//             freq[ele]++;
//             int f = freq[ele];
//             if (f > highestFreq)
//             {
//                 int s = fomap[ele];
//                 int len = i - s;
//                 highestFreq = f;
//                 length = len;
//                 start = s;
//                 end = i;
//             }
//             else if (f == highestFreq)
//             {
//                 int s = fomap[ele];
//                 if (i - s < end - start)
//                 {
//                     start = s;
//                     end = i;
//                     length = i - s + 1;
//                 }
//             }
//         }
//         else
//         {
//             freq.insert(ele, 1);
//             if (1 > highestFreq)
//             {
//                 highestFreq = 1;
//                 start = i;
//                 end = i;
//                 length = end - start + 1;
//             }
//             fomap.insert(ele, i);
//         }
//     }
//     vector<int> ans;
//     ans.push_back(length);
//     ans.push_back(start);
//     ans.push_back(end);
//     return ans;
// }

// // Write a program to solve the task completion problem.
// void completeTask(int n, int m, int arr[])
// {
//     unordered_set<int> uset;
//     for (int i = 0; i < m; i++)
//     {
//         uset.insert(arr[i]);
//     }
//     vector<int> p1;
//     vector<int> p2;

//     bool first = true;
//     for (int i = 1; i <= n; i++)
//     {
//         if (uset.find(arr[i]) != uset.end())
//         {
//             continue;
//         }
//         else
//         {
//             if (first)
//             {
//                 p1.push_back(arr[i]);
//             }
//             else
//             {
//                 p2.push_back(arr[i]);
//             }
//             first = !first;
//         }
//     }
//     return;
// }

// // Write a program to check whether the given two matrices contains the given target sum or not.
// bool checkPair(int arr1[5][5], int arr2[5][5], int k)
// {
//     int *start = arr1[0];
//     int *end = arr2[4] + 4;
//     while (start <= arr1[4] + 4 and end >= arr2[0] + 0)
//     {
//         int sum = *start + *end;
//         if (sum == k)
//         {
//             return true;
//         }
//         else if (sum < k)
//         {
//             start++;
//         }
//         else
//         {
//             end--;
//         }
//     }
//     return false;
// }

// // This problem can also be solved using the hash map problem.
// bool containPair(vector<vector<int>> arr1, vector<vector<int>> arr2, int k)
// {
//     unordered_map<int, int> umap;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         for (int j = 0; j < arr1[0].size(); j++)
//         {
//             umap[arr1[i][j]]++;
//         }
//     }

//     int count = 0;

//     for (int i = 0; i < arr2.size(); i++)
//     {
//         for (int j = 0; j < arr2[0].size(); j++)
//         {
//             int target = k - arr2[i][j];
//             if (umap.find(target) != umap.end())
//             {
//                 count += umap[target];
//             }
//         }
//     }
//     return count;
// }

// // Write a program to solve the subdomain visit count problem
// vector<pair<string, int>> subDomainVisits(vector<string> domains)
// {
//     unordered_map<string, int> umap;
//     for (string str : domains)
//     {
//         stringstream ss(str);
//         string word;
//         vector<string> splitter;
//         while (!ss.eof())
//         {
//             getline(ss, word, ' ');
//             splitter.push_back(word);
//         }
//         string f = splitter[0];
//         int i = 1;
//         int freq = 0;
//         char x = f[f.length() - 1];
//         f.pop_back();
//         freq += int(x);
//         while (f != "")
//         {
//             char x = f[f.length() - 1];
//             f.pop_back();
//             freq = x * pow(10, i) + freq;
//             i++;
//         }

//         stringstream sit(splitter[1]);
//         vector<string> sites;
//         while (!sit.eof())
//         {
//             getline(sit, word, '.');
//             sites.push_back(word);
//         }

//         string domain = sites[sites.size() - 1];
//         for (auto dom : sites)
//         {
//             umap[domain] += freq;
//             // domain = dom + "." + domain; you can do it in this way but it is a costly expression for the compiler
//             domain.insert(0, ".");
//             domain.insert(0, dom);
//         }
//         umap[domain] += freq;
//     }

//     vector<pair<string, int>> ans;
//     // vector<string> answer;
//     for (auto i : umap)
//     {
//         ans.push_back(make_pair(i.first, i.second));
//         // string temp;
//         // temp.append(i.first);
//         // temp.append(to_string(i.second));
//         // answer.push_back(temp);
//     }
//     return ans;
// }

// // Write a program to find the first non repeating character
// char firstNonRepeating(string str)
// {
//     unordered_map<char, int> umap;
//     for (char c : str)
//     {
//         umap[c]++;
//     }
//     for (char c : str)
//     {
//         if (umap[c] == 1)
//         {
//             return c;
//         }
//     }
//     return -1;
// }
// // The time complexity of this solution is O(n).
// // The space complexity of this solution is O(n).

// // Write a progarm to implement the lru cache structure
// class lrucache
// {
// private:
//     list<int> elements;
//     unordered_map<int, list<int>::iterator> umap;
//     int capacity;

// public:
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
//             int delkey = *(--elements.end());
//             umap.erase(delkey);
//             elements.pop_back();
//         }

//         elements.push_front(key);
//         umap[key] = --elements.end();
//     }

//     int get(int key)
//     {
//         if (umap.find(key) != umap.end())
//         {
//             elements.erase(umap[key]);
//             elements.push_front(key);
//             umap[key] = elements.begin();
//             return key;
//         }
//         else
//         {
//             return -1;
//         }
//     }
// };

// // write a program to implement the lfu cache datastructure
// class lfucache
// {
// private:
//     unordered_map<int, pair<int, int>> keyval;
//     unordered_map<int, list<int>> freqlist;
//     unordered_map<int, list<int>::iterator> position;
//     int capacity;
//     int minFreq;

// public:
//     lfucache(int c)
//     {
//         this->capacity = c;
//         this->minFreq = 0;
//     }

//     void updateFreq(int key)
//     {
//         int currFreq = keyval[key].second;
//         auto pos = position[key];

//         freqlist[currFreq].erase(pos);

//         keyval[key].second++;
//         currFreq = keyval[key].second;

//         freqlist[currFreq].push_back(key);
//         position[key] = --freqlist[currFreq].end();
//         if (freqlist[minFreq].empty())
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
//         else if (keyval.find(key) != keyval.end())
//         {
//             updateFreq(key);
//             keyval[key].first = value;
//             return;
//         }
//         else if (keyval.size() == capacity)
//         {
//             int delkey = freqlist[minFreq].front();
//             keyval.erase(delkey);
//             position.erase(delkey);
//             freqlist[minFreq].pop_front();
//         }

//         keyval[key] = make_pair(value, 1);
//         freqlist[1].push_back(key);
//         position[key] = --freqlist[1].end();
//         minFreq = 1;
//     }

//     int get(int key)
//     {
//         if (keyval.find(key) != keyval.end())
//         {
//             updateFreq(key);
//             return keyval[key].first;
//         }
//         else
//         {
//             return -1;
//         }
//     }
// };

// // Write a program to put x of a kind in deck
// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }
// bool hasGroupSizeX(vector<int> deck)
// {
//     unordered_map<int, int> umap;

//     for (int i = 0; i < deck.size(); i++)
//     {
//         umap[deck[i]]++;
//     }

//     int g = 0;
//     for (auto i : umap)
//     {
//         g = gcd(g, i.second);
//     }
//     return g;
// }

// // Write a program to solve the brick wall problem
// pair<int, int> brickSolve(vector<vector<int>> arr)
// {
//     unordered_map<int, int> umap;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int preSum = 0;
//         for (int j = 0; j < arr[0].size() - 1; i++)
//         {
//             preSum += arr[i][j];
//             umap[preSum]++;
//         }
//     }

//     int maxSplit = 0;
//     int index = 0;
//     for (auto i : umap)
//     {
//         if (maxSplit < i.second)
//         {
//             maxSplit = i.second;
//             index = i.first;
//         }
//     }

//     int minBrick = arr.size() - maxSplit;
//     return make_pair(index, minBrick);
// }

// // Write a program to solve the max frequency stack problem.
// #include <stack>
// class freqStack
// {
// private:
//     unordered_map<int, stack<int>> umap;
//     unordered_map<int, int> fmap;
//     int maxFreq;

// public:
//     freqStack()
//     {
//         maxFreq = 0;
//     }
//     void push(int val)
//     {
//         if (fmap.count(val) == 1)
//         {
//             int cf = fmap[val];
//             cf++;
//             fmap[val]++;
//             umap[cf].push(val);
//             if (cf > maxFreq)
//             {
//                 maxFreq = cf;
//             }
//         }
//         else
//         {
//             umap[1].push(val);
//             fmap.insert(make_pair(val, 1));
//             if (1 > maxFreq)
//             {
//                 maxFreq = 1;
//             }
//         }
//     }

//     int pop()
//     {
//         if (maxFreq > 0)
//         {
//             int element = umap[maxFreq].top();
//             umap[maxFreq].pop();
//             fmap[element]--;
//             if (fmap[element] == 0)
//             {
//                 fmap.erase(element);
//             }
//             if (umap[maxFreq].empty())
//             {
//                 maxFreq--;
//             }
//             return element;
//         }
//         else
//         {
//             return -1;
//         }
//     }
// };
// #include <math.h>
// #include <random>
// // Write a program to encode and decode tiny url
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

class solution
{
private:
    unordered_map<string, string> umap;

public:
    string encode(string longURL)
    {
        srand((unsigned)time(NULL));
        string key;
        key.append(to_string(char(rand() % 100)));
        while (umap.find(key) != umap.end())
        {
            key.append(to_string(char(rand() % 100)));
        }
        umap[key] = longURL;
        return key;
    }
    string decode(string shortURL)
    {
        return umap[shortURL];
    }
};

// Write a program to solve the skyline problem

// Write a program to implement the insert delete getrandom data structure
class solution
{
private:
    unordered_map<int, int> umap;
    vector<int> elements;

public:
    void insert(int val)
    {
        if (umap.find(val) != umap.end())
            return;
        elements.push_back(val);
        umap[val] = elements.size() - 1;
    }
    void deleteFrom(int idx)
    {
        umap.erase(elements[idx]);
        elements[idx] = elements[elements.size() - 1];
        elements.pop_back();
        umap[elements[idx]] = idx;
    }

    int getRandom()
    {
        srand((unsigned)time(NULL));
        int randIdx = rand() % elements.size();
        int ans = elements[randIdx];
        return ans;
    }
};

// write a program to implement the insert delete getrandom data structure with duplicacy allowed.
class solution
{
private:
    unordered_map<int, unordered_set<int>> umap;
    vector<int> elements;

public:
    void insert(int val)
    {
        elements.push_back(val);
        umap[val].insert(elements.size() - 1);
    }

    void remove(int val)
    {
        if (umap.find(val) == umap.end())
            return;
        int delidx = *(umap[val].end());
        umap[val].erase(delidx);
        elements[delidx] = elements[elements.size() - 1];
        umap[elements[delidx]].erase(elements.size() - 1);
        umap[elements[delidx]].insert(delidx);
    }

    int getRandom()
    {
        srand((unsigned)time(NULL));
        int randidx = rand() % elements.size();
        return elements[randidx];
    }
};

// This function will return a random number in the range of 0 to n-1 inclusive
int getRandom(int n)
{
    srand((unsigned)time(NULL));
    return rand() % n;
}

int getRandom(int n, vector<int> blacklisted)
{
    unordered_set<int> uset;
    for (auto ele : blacklisted)
    {
        uset.insert(ele);
    }

    int target = n - blacklisted.size() - 1;
    int j = n - 1;
    unordered_map<int, int> umap;
    for (auto i : uset)
    {
        if (i <= target)
        {
            while (uset.count(j))
            {
                j--;
            }
            umap.insert(make_pair(i, j));
        }
    }

    int random = getRandom(target + 1);
    if (umap.find(random) == umap.end())
    {
        return random;
    }
    else
    {
        return umap[random];
    }
}
// The time complexity of this solution is O(blacklisted.size()).
// The space complexity of this solution is O(blacklisted.size()).

// Write a program to solve avoid flood in a city problem.
vector<int> avoidFlood(vector<int> rains)
{
    unordered_map<int, int> lastRain;
    set<int> dry;
    vector<int> ans;

    for (int i = 0; i < rains.size(); i++)
    {
        int x = rains[i];

        if (x == 0)
        {
            dry.insert(i);
            ans.push_back(1); // As recommended from the question. this is gonna change in future iterations
        }
        else
        {
            if (lastRain.find(x) == lastRain.end())
            {
                lastRain.insert(make_pair(x, i));
                ans.push_back(-1);
            }
            else
            {
                int j = lastRain[x];
                if (dry.size() == 0)
                {
                    return {};
                }
                else
                {
                    int drythisday = -1;
                    int max = INT_MAX;
                    for (auto i : dry)
                    {
                        if (i > j && i < max)
                        {
                            drythisday = i;
                            max = i;
                        }
                    }
                    if (drythisday == -1)
                    {
                        return {};
                    }
                    else
                    {
                        dry.erase(drythisday);
                        ans[drythisday] = x;
                        lastRain[x] = i;
                        ans.push_back(-1);
                    }
                }
            }
        }
    }
    return ans;
}

// Write a program to find the pairs of non coinciding pairs

int numOfPairs(vector<int> xlist, vector<int> ylist, int n)
{
    unordered_map<int, int> umapx;
    unordered_map<int, int> umapy;
    unordered_map<string, int> umappair;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x = xlist[i];
        int y = ylist[i];

        if (umapx.find(x) != umapx.end())
        {
            count += umapx[x];
        }
        if (umapy.find(y) != umapy.end())
        {
            count += umapy[x];
        }
        string key = x + "*" + y;
        if (umappair.find(key) != umappair.end())
        {
            count -= 2 * umappair[key];
        }
        umapx[x]++;
        umapy[y]++;
        umappair[key]++;
    }

    return count;
}

// Write a program to solve the line reflection problem
bool isReflected(vector<vector<int>> points)
{
    unordered_map<long, long> umap;
    long xmin = INT_MAX;
    long xmax = INT_MIN;

    for (auto point : points)
    {
        long x = point[0];
        long y = point[1];

        xmin = min(xmin, x);
        xmax = max(xmax, x);

        long hash = x * 100000000 + y;
        umap.insert(make_pair(hash, 1l));
    }

    long mirr = xmin + xmax;
    for (auto point : points)
    {
        int x = point[0];
        int y = point[1];

        long ximg = mirr - x;
        long yimg = y;

        long imghash = ximg * 100000000 + y;

        if (umap.find(imghash) == umap.end())
        {
            return false;
        }
    }
    return true;
}

// Write a program to find the longest substring with atmost two distinct characters
int longestSubstring(string str)
{
    unordered_map<char, int> umap;
    int i = -1;
    int j = -1;
    int maxlen = 0;
    while (true)
    {
        bool f1 = false;
        bool f2 = false;
        // acquiring
        while (i < str.length())
        {
            f1 = true;
            i++;
            umap[str[i]]++;
            if (umap.size() > 2)
            {
                break;
            }
            else
            {
                int len = i - j;
                maxlen = max(len, maxlen);
            }
        }

        while (j < i)
        {
            f2 = true;
            j++;
            umap[str[j]]--;
            if (umap.size() <= 2)
            {
                int len = i - j;
                maxlen = max(len, maxlen);
                break;
            }
        }

        if (f1 == false && f2 == false)
        {
            break;
        }
    }
    return maxlen;
}

// Write a program to find the minimum cost of a string
int minimumCost(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < arr.size(); i++)
    {
        minHeap.push(arr[i]);
    }

    int minCost = 0;
    while (minHeap.size() > 1)
    {
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        int sum = a + b;
        minCost += sum;
        minHeap.push(sum);
    }
    return minCost;
}

// Write a program to solve the ticky sorting cost problem
int trickySort(vector<int> arr)
{
    unordered_map<int, int> umap;

    int maxcons = 1;
    for (int n : arr)
    {
        if (umap.find(n - 1) == umap.end())
        {
            int len = umap[n - 1];
            umap.insert(make_pair(n, len + 1));
            maxcons = max(maxcons, len + 1);
        }
        else
        {
            umap.insert(make_pair(n, 1));
        }
    }

    return arr.size() - maxcons;
}

class Pair
{

public:
    char ch;
    int f;
    Pair(char ch, int f)
    {
        this->ch = ch;
        this->f = f;
    }
};

class compare
{
public:
    bool operator()(Pair a, Pair b)
    {
        return a.f < b.f;
    }
};

string reorganizeString(string s)
{
    vector<int> map(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        map[s[i] - 'a']++;
    }

    priority_queue<Pair, vector<Pair>, compare> maxHeap;

    for (int i = 0; i < 26; i++)
    {
        if (map[i] > 0)
        {
            Pair p('a' + i, map[i]);
            maxHeap.push(p);
        }
    }

    string ans;
    Pair block = maxHeap.top();
    maxHeap.pop();
    ans.push_back(block.ch);
    block.f--;
    while (maxHeap.size() > 0)
    {
        Pair temp = maxHeap.top();
        maxHeap.pop();
        ans.push_back(temp.ch);
        temp.f--;
        if (block.f > 0)
        {
            maxHeap.push(block);
        }
        block = temp;
    }

    if (block.f > 0)
    {
        return "";
    }
    return ans;
}

// Write a program to solve the snapshot array problem
class solution
{
private:
    int sid = 0;
    unordered_map<int, unordered_map<int, int>> umap;

public:
    void set(int index, int val)
    {
        umap[index].insert(sid, val);
    }

    int snap()
    {
        sid++;
        return sid;
    }

    int get(int index, int snap_id)
    {
        while (snap_id >= 0 && umap[index].find(snap_id) == umap[index].end())
        {
            snap_id--;
            if (snap_id == -1)
            {
                return 0;
            }
        }
        return umap[index][snap_id];
    }
};

int main()
{
    srand((unsigned)time(NULL));
    cout << rand() % 100 << endl;
    return 0;
}
// But there are still some numbers which are blacklisted.
// But there are still some numbers which are blacklisted.
// I think this is the best solution possible for this problem.