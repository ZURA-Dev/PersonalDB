#include "PersonalDB.hpp"
#include <iostream>
#include <string>
using namespace std;
const int TABLE_SIZE = 10;
unsigned long hashFunction(const string &key, int tableSize)
{
    unsigned long hash = 5381;
    for (char c : key)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % tableSize;
}

int main()
{
    int value = hashFunction("JOADSHSGSNNASSSSNASASAA", TABLE_SIZE);
    DB *db = new DB;
    std::cout << value;
    hashtable newHash(10);
    newHash.insert("joe1", 5);
    newHash.insert("joe2", 5);
    newHash.insert("joe3", 5);
    newHash.insert("joe4", 5);
    newHash.insert("joe5", 5);
    newHash.insert("joe6", 5);
    newHash.insert("joe7", 5);
    newHash.insert("joe8", 5);
    newHash.insert("joe9", 5);
    newHash.insert("joe10", 5);
    newHash.insert("joe11", 5);
    newHash.insert("joe12", 5);
    newHash.insert("joe13", 5);
    newHash.insert("joe14", 5);
    newHash.find("joe14");
}
