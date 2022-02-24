#include "linkedlists.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Hello world!" << endl;

    listArray arraylist1;

    cout << &arraylist1 << endl;
    cout << arraylist1.list[99] << endl;
    cout << arraylist1.last << endl;
    cout << END(arraylist1) << endl;

    simplestList header;
    simplestList firstListNode;
    simplestList secondListNode;
    
    simplestList* thirdListNodeAlloc;
    simplestList* fourthListNodeAlloc;
    simplestList* fifthListNodeAlloc;


    header.item = 0;
    header.next = &firstListNode;
    firstListNode.item = 1;
    firstListNode.next = &secondListNode;
    secondListNode.item = 2;
    secondListNode.next = nullptr;

    thirdListNodeAlloc = (simplestList*) malloc(sizeof(simplestList));
    fourthListNodeAlloc =  (simplestList*) malloc(sizeof(simplestList));
    fifthListNodeAlloc = (simplestList*) malloc(sizeof(simplestList));

    secondListNode.next = thirdListNodeAlloc;
    thirdListNodeAlloc->item = 3;
    thirdListNodeAlloc->next = fourthListNodeAlloc;
    fourthListNodeAlloc->item = 4;
    fourthListNodeAlloc->next = fifthListNodeAlloc;
    fifthListNodeAlloc->item = 5;
    fifthListNodeAlloc->next = nullptr;

    int a = 5;
    int* ptrA = &a;

    // Header->next = &firstListNode;
    
    /* firstListNode.item = 2;
    firstListNode.next = &secondListNode;
    secondListNode.item = 4;
    secondListNode.next = nullptr; */

    // Header->next->item = 2;
    // Header->next->next = &secondListNode;


    // cout << "The first node is " << Header->next->item << endl;
    // cout << "The second node is " << Header->next->next << endl;

    //cout <<  "The List is empty, " << IsEmpty(&header) << endl;
    //cout <<  "The Header->next is " << header.next << endl;
    //cout <<  "The Header->next is really " << &firstListNode << endl;
    
    //printSimpleList(&header);
    //printSimpleListAddress(&header);
    //cout << searchSimpleList(&header, 9) << endl;
    insertSimpleList(&header, 9, 3);
    //cout << searchSimpleList(&header, 9) << endl;
    printSimpleList(&header);
    deleteSimpleList(&header, 6);
    printSimpleList(&header);

}
