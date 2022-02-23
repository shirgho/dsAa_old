#include <iostream>
#include "array.h"

using namespace std;

int main(int args, char *arg[])
{
    cout << "parititoining Algorithm" << endl;

    const int size = 10;
    int i = 0;
    int pivotValue = 60;

    UnorderedArray<int> array(size);

    for(i = 0; i < size; i++)
        array.push(rand() % 100);

    cout << "Array size: " << size << " pivot value - "
    << pivotValue << "." << endl;

    cout << "Before partitioning";

    for(i = 0; i < size; i++)
        cout << " " << array[i];

    cout << endl;

    int pivot = array.Partition(0, size -1, pivotValue);

    cout << "After partitioning (pivot index - " << pivot << "):";

    for(i = 0; i < size ; i++)
        cout << " " << array[i];

    cout << endl;

    return 0;
}