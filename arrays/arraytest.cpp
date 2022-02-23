#include <iostream>
#include <cstring>
#include "array.h"
#include "orderedarray.h"
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

    array.push(83);
    array.push(82);
    array.BubbleSort();

    cout << "bubble sorted array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    array.clear();

    cout << "cleared array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    array.push(3);
    array.push(53);
    array.push(83);
    array.push(23);
    array.push(82);

    array.SelectionSort();

    cout << "selection sorted array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    array.clear();

    cout << "cleared array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    array.push(3);
    array.push(53);
    array.push(83);
    array.push(23);
    array.push(82);

    array.InsertionSort();

    cout << "insertion sorted array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    array.clear();

    cout << "cleared array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

    UnorderedArray<int> array2(10);

    for(int i = 0; i < 10; i++)
        array2.push(rand() % 100);

    cout << "Before shellsort: " << endl;
    for(int i = 0; i < 10; i++)
        cout << " " << array2[i];

    array2.ShellSort();

    cout << "After shellsort sort:";

    for(int i = 0; i < 10; i++)
        cout << " " << array2[i];

    cout << endl << endl;

    array.push(3);
    array.push(53);
    array.push(83);
    array.push(23);
    array.push(182);
    array.push(682);
    array.push(282);
    array.push(82);
    array.push(10982);

    array.MergeSort();

    cout << "Merge sorted array contents: ";

    for(int i = 0; i < array.GetSize(); i++){
        cout << array[i] << " ";
    }
    cout << endl;

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
    cout << array.recursiveSearch(12);
    cout << endl << endl;

    OrderedArray<int> array2(3);

    cout << "Ordered array 2 contents: ";
    
    array2.binaryInsert(43);
    array2.binaryInsert(8);
    array2.binaryInsert(24);
    array2.binaryInsert(94);
    array2.binaryInsert(17);
    array2.binaryInsert(11);
    array2.binaryInsert(123);
    array2.binaryInsert(65);
    array2.binaryInsert(123);
    array2.binaryInsert(124);

    for(int i = 0; i < array2.GetSize(); i++){
        cout << array2[i] << " ";
    }
    cout << endl;

    cout << "Search for 124 was found at index: ";
    cout << array2.search(125);
    cout << endl << endl;

    cout << "Search for 125 was not found at index: ";
    cout << array2.search(125);
    cout << endl << endl;

    cout << "Search for 94 was found at index through recursive binary search: ";
    cout << array2.recursiveSearch(94);
    cout << endl << endl;
}

int main(int args, char **argc)
{
    UnorderedArrayTest();
    OrderedArrayTest();
    return 1;
}