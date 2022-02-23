#include<iostream>
#include<list>
#include<algorithm>
#include<numeric>
#include<iterator>

using namespace std;

void PrintList(list<int> &lList)
{
    cout << "Contents (" << "Size: "
         << (int)lList.size() << ") - ";

    ostream_iterator<int> output(cout, " ");
    copy(lList.begin(), lList.end(), output);

    cout << endl;

}

void PrintListReverse(list<int> &lList)
{
    cout << "Contents (" << "Size: "
        << (int)lList.size() << ") - ";

    ostream_iterator<int> output(cout, " ");
    copy(lList.rbegin(), lList.rend(), output);
}

int main (int args, char **argc)
{
    list<int> lList;
    lList.push_back(101);
    lList.push_back(201);
    lList.push_back(301);
    lList.push_back(401);
    lList.push_back(501);

    list<int> lList2;
    for(int i = 0; i < 5; i++){
        lList2.push_back(0);
    }

    copy(lList.begin(), lList.end(), lList2.begin());

    cout << "List 1: ";
    PrintList(lList);

    cout << "List 2 in reverse: ";
    PrintListReverse(lList2);

    lList2.sort();
    cout << "   Sorting the list: ";
    PrintList(lList2);

    lList2.reverse();
    cout << "   Reverse the list: ";
    PrintList(lList2);

    lList.push_front(600);
    lList.push_front(700);
    lList.pop_front();
    lList.push_front(800);

    cout << "   Push/Pop front: ";
    PrintList(lList);

    cout << " Acculmulate:  "
         << accumulate(lList.begin(), lList.end(), 0)
         << endl;
    
    lList.pop_back();
    lList.pop_back();

    cout << "Popped two from list: ";
    PrintList(lList);

    lList.clear();

    //Apparently inline and much faster than testing for size() == 0
    if(lList.empty() == true)
        cout << "List is empty.";
    else
        cout << "list is NOT empty.";

    cout << endl << endl;

    return 1;



}