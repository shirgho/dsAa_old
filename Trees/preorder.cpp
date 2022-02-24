/*Pre order run through of a tree*/

// Functins defined in library

/*
ROOT(T);
LABEL(n, T);
CREATEi(c, T1, T2,, ..., Ti);
MAKENULL(T);
PARENT(n, T);
LEFTMOST_CHILD(n, T);
RIGHT_SIBLING(n, T);

*/

node n = ROOT(T);
PREORDER(n);

//recursive solution
int PREORDER(node n){
  node c;

  std::cout << label(n, T);
  c = LEFTMOST_CHILD(n, t);

  while( c != NULLTREE){
    PREORDER(c);
    c = RIGHT_SIBLING(c, T);
  }
  
}




//non recursive solution
