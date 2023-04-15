// Working with the LRU and LFU data structures

// working with the least recently used data structure (lru cache)
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
    list<int> elements;
    unordered_map<int, list<int>::iterator> umap;
    int capacity;

public:
    LRUCache(int c)
    {
        this->capacity = c;
    }

    void put(int key)
    {
        if (capacity == 0)
        {
            return;
        }
        if (umap.find(key) != umap.end())
        {
            elements.erase(umap[key]);
            elements.push_front(key);
            umap[key] = elements.begin();
            return;
        }
        if (umap.size() == capacity)
        {
            auto temp = --elements.end();
            int delkey = *temp;
            umap.erase(delkey);
            elements.pop_back();
        }

        elements.push_front(key);
        umap[key] = elements.begin();
    }

    int get(int key)
    {
        if (umap.find(key) == umap.end())
        {
            return -1;
        }
        else
        {
            elements.erase(umap[key]);
            elements.push_front(key);
            umap[key] = elements.begin();
            return key;
        }
    }
};

// working with the least frequently used data structure(lfu cache)
class LFUCache
{
    unordered_map<int, pair<int, int>> keyVal;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> position;
    int capacity;
    int minFreq;

public:
    LFUCache(int c)
    {
        this->capacity = c;
        minFreq = 0;
    }

    void updateFreq(int key)
    {
        int currFreq = keyVal[key].second;
        auto pos = position[key];

        freqList[currFreq].erase(pos);

        keyVal[key].second++;
        currFreq++;
        freqList[currFreq].push_back(key);
        position[key] = --freqList[currFreq].end();
        if (freqList[minFreq].empty())
        {
            minFreq++;
        }
    }

    void put(int key, int val)
    {
        if (capacity == 0)
        {
            return;
        }
        if (keyVal.find(key) != keyVal.end())
        {
            updateFreq(key);
            keyVal[key].first = val;
            return;
        }
        if (keyVal.size() == capacity)
        {
            int delkey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyVal.erase(delkey);
            position.erase(delkey);
        }

        keyVal[key] = make_pair(val, 1);
        freqList[1].push_back(key);
        position[key] = --freqList[1].end();
        minFreq = 1;
    }

    int get(int key)
    {
        if (keyVal.find(key) == keyVal.end())
        {
            return -1;
        }
        else
        {
            updateFreq(key);
            return keyVal[key].first;
        }
    }
};

int main()
{
    return 0;
}