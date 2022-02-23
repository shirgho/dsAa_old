#include<iostream>
#include "list.h"

using namespace std;

int main(int args, char **argc)
{
    LinkList<int> lList;

    lList.Push_Back(101);
    lList.Push_Back(201);
    lList.Push_Back(301);
    lList.Push_Back(401);
    lList.Push_Back(501);

    lList.Pop_Back();

    lList.Push_Back(601);

    lList.Pop_Back();
    lList.Pop_Back();
    lList.Pop_Front();
    lList.Pop_Front();
    lList.Push_Front(111);
    lList.Push_Front(222);

    
    LinkIterator<int> lIterator;
    
    cout << "Contents of Linked List forward: ";
    for(lIterator = lList.Begin(); lIterator != NULL; lIterator++){
        cout << " " << *lIterator;
    }
    cout << "." << endl;
 

    cout << "Contents of Linked List reverse: ";
    for(lIterator = lList.End(); lIterator != NULL; lIterator--){
        cout << " " << *lIterator;
    }
    cout << "." << endl;
   

    return 0;


}