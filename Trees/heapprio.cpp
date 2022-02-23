#include <iostream>
#include "heap.h"

using namespace std;

template<typename T>
class less_cmp
{
    public:
        inline bool operator()(T lVal, T rVal)
        {
            return (lVal < rVal);
        }
};

template<typename T>
class greater_cmp
{
    public:    
        inline bool operator()(T lVal, T rVal)
        {
            return (lVal > rVal);
        }
};

int main(int args, char ** argc)
{
    cout << "PrioQueue implemented over Heap" << endl;

    PriorityQueueHeap<int, less_cmp<int>> pq;

    pq.push(33);
    pq.push(43);
    pq.push(23);
    pq.push(20);
    pq.push(10);
    pq.push(22);
    pq.push(90);
    pq.push(95);
    pq.push(86);

    cout << "Priority Queue contents:";

    while(pq.empty() != true){
        cout << " " << pq.peek();
        pq.pop();
    }

    cout << "." << endl;

    return 0;
}