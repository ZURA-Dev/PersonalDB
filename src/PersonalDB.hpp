#ifndef PERSONALDB_HPP
#define PERSONALDB_HPP
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>

/*====================================================================
 *						    HASH TABLES
 *====================================================================*/
// use linked list for storing these hashtable values.
// for now use vectors until later vector.
using namespace std;
struct KeyValue
{
public:
    string key;
    int value;
    KeyValue(const string &key = "", int value = 0)
    {
        this->key = key;
        this->value = value;
    }
};

class hashtable
{
private:
    vector<KeyValue> pairs;

public:
    hashtable(int tableSize)
    {
        pairs.resize(tableSize); // Initialize the vector with the specified size
    }
    int hashFunction(const string &key)
    {
        unsigned long hash = 5381;
        for (char c : key)
        {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % getTable();
    }
    int getTable() { return pairs.capacity(); }
    void insert(const string &key, const int &value)
    {
        if (pairs.size() == pairs.capacity() - 1)
        {
            pairs.resize(pairs.capacity() + 10);
            int hash = hashFunction(key);
            pairs[hash] = KeyValue(key, value);
        }
        else
        {
            int hash = hashFunction(key);
            pairs[hash] = KeyValue(key, value);
        }
    }
    int find(const string &key)
    {
        int hash = hashFunction(key);
        if (pairs[hash].key == key)
        {
            cout << "HASH: " << hash << endl;
            cout << "KEY:" << pairs[hash].key << endl;
            cout << "VECTOR SIZE: " << pairs.size() << endl;
            cout << "VECTOR CAPACITY: " << pairs.capacity() << endl;
            return pairs[hash].value;
        }
        return -1; // Key not found
    }
};
//*************************************************************
// Database
// so im thinking like a vector, then use a hash, and resize the vector if size gets too big and rehash everything, just a quick idea will optimize later
struct Table
{
};
class DB
{
private:
public:
    DB() {}
    ~DB() {}
};
//*************************************************************
#endif