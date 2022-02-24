# Iterators

Iterators for variables/types with Templates need typname in front to tell
the compiler that this is the type for the iterator.

template <typename T> void foo() {
  list<tnode<int>*>::iterator it1; // OK without typename
  typename list<tnode<T>*>::iterator it2; // typename necessary
}