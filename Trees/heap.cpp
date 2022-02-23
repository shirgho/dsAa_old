#include <iostream>
#include "heap.h"

using namespace std;

int main(int args, char ** argc)
{
    cout << "Heaps" << endl;

    Heap<int> heap(10);

    heap.push(30);
    heap.push(33);
    heap.push(43);
    heap.push(23);
    heap.push(20);
    heap.push(10);
    heap.push(22);
    heap.push(90);
    heap.push(95);
    heap.push(86);

    cout << "Heap contents:";

    while(heap.size() != 0){
        cout << " " << heap.peek();
        heap.pop();
    }

    cout << "." << endl;

    return 0;
}