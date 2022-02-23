#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>

using namespace std;


/* If using custom classes or pointers, use vectors. Use them anyway. 

    SomeClass someArray[100]; calls a 100 constructors for 100 objects.

    vector<SomeClass> someVec;
    someVec.reserve(100); no constructors are executed to store.

*/

void PrintVector(vector<int> &array)
{
    cout << "Contents (" << "Size: " << (int)array.size() <<
    " Max: " << (int)array.capacity() << ") - ";

    ostream_iterator<int> output(cout, " ");
    copy(array.begin(), array.end(), output);
    cout << endl;
}

int main(int args, char **argc)
{
    cout << "STL Vector Example 2: Iterators" << endl;
    cout << "Data Structures for Game Developers" << endl;
    cout << "Allen Sherrod" << endl << endl;

    vector<int> array;
    array.reserve(5);

    // Add items then print.
    array.push_back(10);
    array.push_back(20);
    array.push_back(30);
    array.push_back(40);
    array.push_back(50);

    // Calling the copy algorithm.
    vector<int> array2;
    array2.reserve(5);
    array2.push_back(100);
    array2.push_back(200);
    array2.push_back(300);
    array2.push_back(400);
    array2.push_back(500);
    cout << "  Inserted into vector2:  ";
    PrintVector(array2);
    vector<int>::const_iterator it = find(array2.begin(), array2.end(), 300);
    if(it != array2.end())
        cout << "Item 300 found" << endl;
    else
        cout << "Item 300 not found." << endl;

    copy(array.begin(), array.end(), array2.begin());
    
    cout << "  Inserted into vector:  ";
    PrintVector(array);
    cout << "  Inserted into vector2:  ";
    PrintVector(array2);
    sort(array2.begin(), array2.end(), greater<int>());
    cout << "  vector2 sorted:  ";
    PrintVector(array2);
    fill(array2.begin(), array2.end(), 5);
    cout << "  Inserted into vector2:  ";
    PrintVector(array2);

    // Run the accumulate algorithm.
    cout << "            Accumulate:  "
        << accumulate(array.begin(), array.end(), 0)
        << endl;
 
    // Pop off the container.
    array.pop_back();
    array.pop_back();

    cout << "Popped two from vector:  ";
    PrintVector(array);

    // Clear the container.
    array.clear();

    cout << "        Cleared vector:  ";
    PrintVector(array);
    cout << endl;

    // Test if the container is empty.
    if(array.empty() == true)
        cout << "Vector is empty.";
    else
        cout << "Vector is NOT empty.";

    cout << endl << endl;
    return 1;
}