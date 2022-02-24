#include <iostream>
#include <deque>

#define BASE 10
#define MAX_POSITIONS 2

using namespace std;

void RadixSort(int *array, int size)
{
    // base index, radix index, counter
    int b = 0, r = 0, i = 0;

    // container counter, base factor
    int index = 0, factor = 0;

    // List of containers for the sort.
    deque<int> qList[BASE];

    // Place in the containers then take them off for every base
    for(b = 1, factor = 1; b <= MAX_POSITIONS; factor*= BASE, b++){
        for(r = 0; r < size; r++){
            index = (array[r] / factor) % BASE;
            qList[index].push_back(array[r]);
        }

        for(r = 0, i = 0; r < BASE; r++){
            while(qList[r].empty() != true){
                array[i++] = qList[r].front();
                qList[r].pop_front();
            }
        }
    }
}

int main(int args, char *arg[])
{
    cout << "Radix sort Algorithm" << endl;

    const int size = 10;
    int i = 0;
    int array[size];

    for(i = 0; i < size; i++)
        array[i] = rand() % 99;

    cout << "Before sorting";

    for(i = 0; i < size; i++)
        cout << " " << array[i];

    cout << endl;

    RadixSort(array, size);

    cout << "After sorting:";

    for(i = 0; i < size ; i++)
        cout << " " << array[i];

    cout << endl;

    return 0;
}