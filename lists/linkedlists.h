#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

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

// linked list array implementation (contiguously allocated structure)

#define MAXLENGTH 100
#define ITEM_TYPE int  
#define POSITION int

typedef struct listArray {
    ITEM_TYPE list[MAXLENGTH];
    int last; 
} listArray;

POSITION END(listArray L);
POSITION RETRIEVE(listArray L, ITEM_TYPE X);
void INSERT(listArray L, ITEM_TYPE X, POSITION P);
void DELETE(listArray L, ITEM_TYPE X);


// linked list pointer implementation (linked data structure)

// simple list

typedef struct simplestList {
    ITEM_TYPE item;
    struct simplestList *next;
} simplestList;


bool IsEmpty(simplestList *L);
void printSimpleList(simplestList *L);
void printSimpleListAddress(simplestList *L);
ITEM_TYPE searchSimpleList(simplestList* L, ITEM_TYPE x);
void insertSimpleList(simplestList *L, ITEM_TYPE x, POSITION p);
void insertAtHeadSimpleList(simplestList *L, ITEM_TYPE x);
void insertAtTailSimpleList(simplestList *L, ITEM_TYPE x);
void deleteSimpleList(simplestList *L, ITEM_TYPE x);
simplestList* findPrev(simplestList *L, ITEM_TYPE x); 

// somewhat less simpler List Class
/*
struct Node {
    ITEM_TYPE data;
    Node *next;

    Node(ITEM_TYPE d){
        data = d;
        next = nullptr;
    }
};

class linkedList {
    private:
        Node *Head;
        Node *Tail;

    public:
        LinkedList(){
            Head = NULL;
        }

        void RETRIEVE(ITEM_TYPE d);
        void INSERT(ITEM_TYPE d, POSITION p);
        void DELETE(ITEM_TYPE d, POSITION p);
}
*/

#endif /*LINKEDLISTS_H*/