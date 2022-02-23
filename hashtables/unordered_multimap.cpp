#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

struct cmp
{
    bool operator()(const char *str1, const char *str2) const
    {
        return strcmp(str1, str2) == 0;
    }
};

typedef unordered_multimap<const char*, int, hash<const char*>, cmp> mapType;

void Find(const mapType &c, const char *str)
{
    mapType::const_iterator it = c.find(str);
    //auto ait = c.find(str); //should use auto hi for making iterators?

    if(it == c.end())
        cout << str << " - was not found!" << endl;
    else
        cout << it->first << " - was found with value: " << it->second << endl; 
}

int main(int args, char **argc)
{
    cout << "Hash tables - Unordered Multi Map" << endl;

    mapType hashTable;

    if(hashTable.empty() == true)
        cout << "The table is empty." << endl;

    hashTable.insert(mapType::value_type("Hello" , 30));
    hashTable.insert(mapType::value_type("Hello" , 60));
    hashTable.insert(mapType::value_type("Hello" , 90));
    hashTable.insert(mapType::value_type("What" , 300));
    hashTable.insert(mapType::value_type("Okay" , 3000));


    cout << "The Hash table has " << hashTable.size() << "items after insertions."
    << endl;

    Find(hashTable, "Test");
    Find(hashTable, "Example");
    Find(hashTable, "Hello");
    Find(hashTable, "Why Hello");
    Find(hashTable, "What");

    hashTable.erase("What");
    Find(hashTable, "What");

    cout << endl;

    pair<mapType::iterator, mapType::iterator> range;
    range = hashTable.equal_range("Hello");

    cout << "Displaying all items in a range:" << endl;

    for(mapType::iterator it = range.first; it != range.second; it++){
        cout << "key: " << it->first << " value: " << it->second << endl;
    }



    return 0;
}

