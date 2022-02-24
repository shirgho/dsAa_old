#include <iostream>
#include <cstring>
#include "array.cpp"
#include "orderedarray.cpp"
using namespace std;


void UnorderedArrayTest()
{
    UnorderedArray<int> array(3);
    array.push(3);
    array.push(53);
    array.push(83);
    array.push(23);
    array.push(82);
    
    array[2] = 112;

    array.pop();
    array.remove(2);
    
    cout << "Unordered array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Search for 53 was found at index: ";
    cout << array.search(53);
    cout << endl << endl;
}
void OrderedArrayTest()
{

    OrderedArray<int> array(3);
    
    array.push(43);
    array.push(8);
    array.push(23);
    array.push(94);
    array.push(17);
    array.push(12);
    array.push(123);
    array.push(65);

    cout << "Ordered array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
    

    cout << "Search for 12 was found at index: ";
    cout << array.search(12);
    cout << endl << endl;

    cout << "Search for 12 was found at index through recursive binary search: ";
    cout << array.recursiveSearch(123);
    cout << endl << endl;

    OrderedArray<int> array2(3);

    cout << "Ordered array 2 contents: ";
    
    array2.binaryInsert(43);
    array2.binaryInsert(8);
    array2.binaryInsert(23);
    array2.binaryInsert(94);
    array2.binaryInsert(17);
    array2.binaryInsert(12);
    array2.binaryInsert(123);
    array2.binaryInsert(65);

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    

    cout << "Search for 12 was found at index: ";
    cout << array.search(12);
    cout << endl << endl;

    cout << "Search for 12 was found at index through recursive binary search: ";
    cout << array.recursiveSearch(123);
    cout << endl << endl;
}


int main(int args, char **argc)
{
    UnorderedArrayTest();
    OrderedArrayTest();
    return 1;
}