// today we are going to talk about trie
// what is trie
/*
I want to implement a dictionary:
addword
search
removeword

which datastructure can efficiently do all these operations:
ans1 : hashmap -> the average time complexity of all these operatios will  come out to be O(1).
// but in worst case the time complexities will differ -> in full fledged case -> the time complexity will be O(l) for insertion where l is the length of word
// similar is the case with deletion and searching. all will consume a time complexity of O(l) in full fledged cases or in the worst cases.

*/

#include <iostream>

using namespace std;

// implementing a trie node
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Write a program to implement the insertion and searching algorithm in a trie
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption , word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Absent
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

    // Implementing the search word algorihtm

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
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
            // absent
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // Implementing the prefix searching algorithm
    bool prefixUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }

        // recursion
        return prefixUtil(child, word.substr(1));
    }

    bool prefixWord(string word)
    {
        return prefixUtil(root, word);
    }

    // Implementing the delete word algorithm
    // just set the isTerminal of the terminal node to false
    // homeword to search the word
};
// Now we are going to talk about the time complexities
/*
Insertion => O(length) => length of word
Search => O(length) => length of word
deletion => O(length) => length of word
*/

// why use trie instead of hash maps if the time complexity in both the data structures are the same
// The answer is space utilization.
// I has improved searching in a data stream. whereas in case of hash maps we would have to traverse the whole array to do the same thing which is a costly operation.

int main()
{
    return 0;
}