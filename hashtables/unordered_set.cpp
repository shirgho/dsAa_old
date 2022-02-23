#include <iostream>
#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

struct cmp
{
    bool operator()(const char *str1, const char *str2) const
    {
        return strcmp(str1, str2) == 0;
    }
};

void Find(const unordered_set<string> &c, const char *str)
{
    unordered_set<string>::const_iterator it = c.find(str);

    if(it == c.end())
        cout << str << " - was not found!" << endl;
    else
        cout << str << " - was found in the hash table!" << endl; 
}

int main(int arfs, char **argc)
{
    cout << "Hash tables - unordered set" << endl;

    unordered_set<string> hashTable;

    hashTable.insert("Hello");
    hashTable.insert("And");
    hashTable.insert("Goodbye");
    hashTable.insert("Take Care");
    hashTable.insert("So Long");

    Find(hashTable, "Test");
    Find(hashTable, "Example");
    Find(hashTable, "Hello");
    Find(hashTable, "Take Care");
    Find(hashTable, "Goodbye");

    cout << endl;

    return 0;
}

