// Working on trie related questions
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Write a program to return the longest common prefix in a given array of strings
// first appraoch
// take the first string and compare the corresponding elements of the first string with all the corresponding elements of all the strings . If the characters are same put the character into the answer string otherwise break the loop and return the answer.
string longestCommonPrefix(vector<string> arr, int size)
{
    string ans;
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool presentInAll = true;
        // for traversing all the characters of first string
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {

                presentInAll = false;
                break;
            }
        }
        if (presentInAll)
        {
            ans.push_back(ch);
        }
        else
        {
            break;
        }
    }
    return ans;
}
// The time complexity of this solution is O(m*n) where m is the length of the string and n is the total number of strings
// The space complexity of this solution excluding the ans string is O(1) otherwise O(m).

// Implementing the same functionality using trie

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            {
                children[i] = NULL;
            }
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // aage badhjao
                int index = ch - 'A';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;
        }
    }
};
// The time complexity of this solution is O(m*n) and the space complexity of this solution is also O(m*n). So it is not an efficient solution to solve this problem.

int main()
{
    Trie *t = new Trie('\0');
    vector<string> arr = {"heello", "buflallo"};

    // insert kardo all strings into trie
    for (int i = 0; i < arr.size(); i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    // return ans;
    return 0;
}