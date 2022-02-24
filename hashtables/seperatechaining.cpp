#include <iostream>
#include "hashtable_2.h"

using namespace std;

int main(int args, char **argc)
{
    cout << "Hash tables innit" << endl;

    HashTable<int> hashTable(21);
    int item = 0;

    item = 835; hashTable.Insert(57, item);
    item = 247; hashTable.Insert(68, item);
    item = 456; hashTable.Insert(37, item);
    item = 235; hashTable.Insert(82, item);
    item = 644; hashTable.Insert(11, item);

    if(hashTable.Find(87, &item))
        cout << "Item: 87 has a value of " << item << "." << endl;
    else
        cout << "Item: 87 not found." << endl;

    if(hashTable.Find(112, &item))
        cout << "Item: 112 has a value of " << item << "." << endl;
    else
        cout << "Item: 112 not found." << endl;

    
    if(hashTable.Find(82, &item))
        cout << "Item: 82 has a value of " << item << "." << endl;
    else
        cout << "Item: 82 not found." << endl;

    
    if(hashTable.Find(37, &item))
        cout << "Item: 37 has a value of " << item << "." << endl;
    else
        cout << "Item: 37 not found." << endl;

    hashTable.Delete(37);

    if(hashTable.Find(37, &item))
        cout << "Item: 37 has a value of " << item << "." << endl;
    else
        cout << "Item: 37 not found." << endl;
 
    string str("cats");
    int stringHash = hashTable.HashFunction(str);
    cout << "The string cats hash to " << stringHash << "." << endl << endl;

}