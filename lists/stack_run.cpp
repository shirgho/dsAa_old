#include <iostream>
#include "stack_4.h"

using namespace std;

int main (int args, char ** argc)
{
    std::cout << "Stacks innit" << std::endl;

    // For list based, no constructor function called explicitely
    Stack<int> sList;
    // For array based
    //Stack<int> sList(5);

    sList.push(191);
    sList.push(291);
    sList.push(391);
    sList.push(491);
    sList.push(591);

    sList.pop();

    sList.push(621);

    cout << "Contents of the stack:";

    while(sList.isEmpty() == false){
        cout << " " << sList.top();
        sList.pop();
    }

    cout << "." << endl;

    return 1;


}