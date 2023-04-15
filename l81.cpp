// Write a program for implementing a phone directory
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// The time complexity of this solution is O(n*m^2).
// The space complexity of this solution is O(m*n) where m is the average length of the string and n is the total number of strings given to us.

class TrieNode
{
public:
    char data;
    int childCount;
    bool isTerminal;
    TrieNode *children[26];

    TrieNode(char ch)
    {
        data = ch;
        childCount = 0;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
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
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            // check for last character
            TrieNode *curr = prev->children[lastch - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // creating of trie
    Trie *t = new Trie('\0');

    // insert all contact list in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        t->insertWord(contactList[i]);
    }

    // return ans
    return t->getSuggestions(queryStr);
}

int main()
{
    Trie *t = new Trie('\0');
    vector<string> arr = {"cod", "coding", "codding", "code", "coly"};

    for (int i = 0; i < arr.size(); i++)
    {
        t->insertWord(arr[0]);
    }

    return 0;
}

// the space complexity of this solution is O(m*n)
// the time complexity of this solution is O(n*m*m).
// The main aim of studies is personal development. If you are not able to do so then there is no point of studying at all.
