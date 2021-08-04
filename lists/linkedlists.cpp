

/* linked list scene

Mathematically, a list (L) is a sequence of zero or more elements of a given type.

END(L) : returns the position 

1. INSERT(x, p, L) : insert x at p in L
2. LOCATE(x,L) : return p
3. RETRIEVE(p, L) : return x at p
4. DELETE(p, L) : remove x at p
5. NEXT(p, L) and PREVIOUS(p, L)
6. MAKENULL(L) : Make L
7. FIRST(L)
8. PRINTLIST(L)
*/

#include "linkedlists.h"
#include <iostream>

#define MAXLENGTH 100
#define ITEM_TYPE int  
#define POSITION int

// linked list array implementation (contiguously allocated structure)

POSITION END(listArray L) {
    return L.last + 1;
}

// linked list pointer implementation (linked data structure)

// simplestList implementations

bool IsEmpty(simplestList *L){
    if(L -> next == nullptr)
        return true;
    else
        return false;
}

void printSimpleList(simplestList *L){
    simplestList* n = L;
    while (n != nullptr){
        std::cout << "This node is "<< n->item << std::endl;
        std::cout << "This node is "<< n << std::endl;
        std::cout << "The next node will be "<< n->next << std::endl;
        n = n->next;      
    } 
    std::cout << "The last node in the list is "<< n << std::endl;
    std::cout << "The last node in the list is "<< &n << std::endl;

}

void printSimpleListAddress(simplestList *L){
    simplestList* n = L;
    while (n != nullptr){
        std::cout << "This node is "<< &n << std::endl;
        std::cout << "The second last node in the list is "<< n << std::endl;
        n = n->next; 
        std::cout << "The last node in the list is "<< n << std::endl;     
    } 
    std::cout << "The last node in the list is address "<< &n << std::endl;
    // so the address of n does not change. The address to where it points to changes.
    // n is a pointer, holding the address of the struct. &n is a pointer to this pointer.

}

ITEM_TYPE searchSimpleList(simplestList *L, ITEM_TYPE x){
    simplestList* n = L;
    while (n != nullptr){
        if (n -> item == x)
            return n->item;
        else
            n = n->next;
    }  
        
    std::cout << "Could not find element in the list, sorry." << std::endl;
    return -1;
    
}

void insertSimpleList(simplestList *L, ITEM_TYPE x, POSITION p){
    simplestList* newListNode = (simplestList*) malloc(sizeof(simplestList));
    newListNode -> item = x;

    simplestList* n = L;

    for(POSITION i = 0; i < p; i++){
        if (n == NULL){
            std::cout << "index is out of bounds of list" << std::endl;
            return;
        }   
        n = n->next;
    }

    newListNode->next = n->next;
    n->next = newListNode;

}

void deleteSimpleList(simplestList *L, ITEM_TYPE x){
    simplestList *n = L;
    while(n != NULL){   
            if (n->next->item != x){
                n = n->next;
            } else {
                n->next = n->next->next;
                std::cout << "deleted" << std::endl;
                return;
            }
    }
     std::cout << "couldn't find" << std::endl;    
     return;
}