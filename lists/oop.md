# C++ Object Oriented Programming

## Classes
- Classes can be defined with private, protected and public members.
- Members can be data variables or functions.
    - Private members accessed only by objects of that class
    - Protected can be accessed by "Friend" objects or Inherited objects.
    - Public is public

## Templates
- Generic programming, don't have to decide type at Compile time then
- Can be used for functions and classes, as well as when declaring containers
    - vector <int> or vector <string> etc.

## functions

```c++

template <class type> ret-type func-name(parameter list) {
   // body of function
} 

template <typename T>
T Max (T a, T b) { 
   return a < b ? b:a; 
}

//Function Definition
template <class myType>
myType GetMax (myType a, myType b) {
 return (a>b?a:b);
}

template <class T, class U>
T GetMin (T a, U b) {
  return (a<b?a:b);
}

// Function Call
int x,y,i;
long l;

i = GetMin<int,long> (x,l);
GetMax <int> (x,y);

// in these cases, compiler can figure out types 	
i = GetMin (j,l);
GetMax(x,y);

template <typename T>
inline T const& Max (T const& a, T const& b) { 
   return a < b ? b:a; 
}

```

## classes

```c++

template<typename T> class LinkList;


template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  mypair <int> myobject (100, 75);
  cout << myobject.getmax();
  return 0;
}

```

- Confused by so many T's? There are three T's in this declaration: The first one is the template parameter. The second T refers to the type returned by the function. And the third T (the one between angle brackets) is also a requirement: It specifies that this function's template parameter is also the class template parameter.