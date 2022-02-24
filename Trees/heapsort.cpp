#include <iostream>
#include <vector>
#include <iterator>
#include "heap.h"

using namespace std;

void HeapSortAscending(vector<int> &array)
{
    Heap<int> heap;
    int i;

    for(i = 0; i < (int)array.size(); i++){
        heap.push(array[i]);
    }

    for(i = (int)(array.size()) - 1; i>= 0; i--){
        array[i] = heap.peek();
        heap.pop();
    }

}


void HeapSortDescending(vector<int> &array)
{
    Heap<int> heap;
    int i;

    for(i = 0; i < (int)array.size(); i++){
        heap.push(array[i]);
    }

    for(i = 0; i < (int)array.size(); i++){
        array[i] = heap.peek();
        heap.pop();
    }
    
}

void DisplayVectorSub(vector<int> &array)
{
    //subscript way
    for(int i = 0; i < (int)array.size(); i++){
        cout << " " << array[i];
    }
    cout << ".";   
}

void DisplayVectorOut(vector<int> &array)
{
    //ostream iterator
    ostream_iterator<int> output(cout, " ");
    copy(array.begin(), array.end(), output);
    cout << "."; 
}

void DisplayVectorAuto(vector<int> &array)
{
    //auto iterator
    //for(auto it = array.begin(); it != array.end(); it++){
    //    cout << " " << *it;
    //}

    for(auto const &it : array){
        cout << " " << it;
    }
    cout << ".";
}

int main(int args, char **argc)
{
    cout << "Heap Sort" << endl;

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

    cout << "Array contents before sort:";
    DisplayVectorSub(array);
    cout << endl;

    cout << "Array contents after sort (ascending):";
    HeapSortAscending(array);
    DisplayVectorOut(array);
    cout << endl;

    cout << "Array contents after sort (descending):";
    HeapSortDescending(array);
    DisplayVectorAuto(array);
    cout << endl;

    return 0;
}