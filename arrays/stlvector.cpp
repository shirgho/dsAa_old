#include<iostream>
#include<vector>

using namespace std;

void PrintVector(vector<int> &array)
{
    cout << "Contents (" << "Size: " << (int)array.size() <<
    " Max: " << (int)array.max_size() << ") - ";
    for(int i = 0; i < (int)array.size(); i++){
        cout << array[i] << " ";
    }

    cout << endl;
}

int main(int args, char **argc)
{
    cout << "STL Vector Example" << endl;

    vector<int> array;

    array.reserve(5);
    array.push_back(10);
    array.push_back(20);
    array.push_back(30);
    array.push_back(40);

    cout << "  Inserted into vector.  ";
    PrintVector(array);

    array.pop_back();
    array.pop_back();
    cout << "Popped two from vector.  ";
    PrintVector(array);

    array.clear();
    cout << "        Cleared vector.  ";
    PrintVector(array);
    cout << endl;

    if(array.empty() == true)
        cout << "Vector is empty.";
    else
        cout << "Vector is NOT empty.";
    cout << endl << endl;

    return 1;
}