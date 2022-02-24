#include <iostream>
#include "array.h"

using namespace std;

int main(int args, char *arg[])
{
    cout << "Quicksort Algorithm" << endl;

    const int size = 10;
    int i = 0;

    UnorderedArray<int> array(size);

    for(i = 0; i < size; i++)
        array.push(rand() % 90);

    cout << "Before sorting";

    for(i = 0; i < size; i++)
        cout << " " << array[i];

    cout << endl;

    array.Quicksort();

    cout << "After sorting:";

    for(i = 0; i < size ; i++)
        cout << " " << array[i];

    cout << endl;

    return 0;
}