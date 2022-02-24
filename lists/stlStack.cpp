#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void DisplayStack(T &stack)
{
    cout << "(Size - " << stack.size() << ") :";

    while(stack.empty() == false){
        cout << " " << stack.top();
        stack.pop();
    }

    cout << "." << endl;
}


int main (int args, char ** argc)
{
    std::cout << "STL Stacks" << std::endl;

    stack<int> intStack;
    stack< int, vector<int> > vecStack;
    stack< int, list<int> > listStack;
    
    for(int i = 0; i < 5; i++){
        intStack.push(i * 11);
        vecStack.push(i * 22);
        listStack.push(i * 33);
    }

    listStack.push(33);

    cout << "Contents of int stack:";
    DisplayStack(intStack); 

    cout << "Contents of vector stack:";
    DisplayStack(vecStack); 

    cout << "Contents of list stack:";
    DisplayStack(listStack); 

    cout << "." << endl;

    if(intStack.empty() == true)
        cout << "The stack is empty." << endl;
    else
        cout << "The stack is NOT empty." << endl;

    if(vecStack.empty() == true)
        cout << "The stack is empty." << endl;
    else
        cout << "The stack is NOT empty." << endl;

    if(listStack.empty() == true)
        cout << "The stack is empty." << endl;
    else
        cout << "The stack is NOT empty." << endl;

    return 1;


}