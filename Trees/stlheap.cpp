#include <iostream>
#include <algorithm> 
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

void DisplayVectorAuto(vector<int> &array)
{
    //auto iterator
    //for(auto it = array.begin(); it != array.end(); it++){
    //    cout << " " << *it;
    //}

    for(auto it : array){
        cout << " " << it;
    }
    cout << ".";
}

int main(int args, char ** argc)
{
    cout << "STL heap functions" << endl;

    vector<int> array;

    array.push_back(33);
    array.push_back(43);
    array.push_back(23);
    array.push_back(20);
    array.push_back(10);
    array.push_back(22);
    array.push_back(90);
    array.push_back(95);
    array.push_back(86);

    cout << "Vector contents:";
    DisplayVectorAuto(array);
    cout << endl;

    make_heap(array.begin(), array.end());

    cout << "Heap contents:";
    DisplayVectorAuto(array);
    cout << endl;

    cout << "Popping Heap: (so performing heapsort) ";
    while(array.size() != 0){
        cout << " " << array.front();
        pop_heap(array.begin(), array.end());
        array.pop_back();
    }

  /*   sort_heap(array.begin(), array.end());

    cout << "Heap contents sorted:";
    DisplayVectorAuto(array);
    cout << endl; */

    return 0;
}