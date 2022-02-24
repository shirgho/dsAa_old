# Dynamic memory 

## New and Delete

int *foo;

Here, you declared a pointer variable, that can point to an int.

foo = new int [5];

Here, you've initialised the pointer variable to now point to a block of integers.

Now when you delete[] foo, you're removing the allocated memory block.
Foo still exists.
You can assign Foo to NULL for example, making it now a null pointer.

## Passing Pointers to Functions

### half baked explanation
You can also pass pointers or references to functions, sure, you know this.
BUT you can also inadvertently pass a pointer by value, and not the reference that the pointer was actually pointing too.

In c++, you can pass by reference, which is different from passing a pointer. Even though a pointer's value is a reference to something, pointer
itself is still a variable.

It's a bit confusing. References are also memory addresses, but you pass
them directly without wrapping them in a pointer variable.

I explain:

´´´
int pointer;

void foo(int *pointer){

}
which would be foo(pointer). This will create a copy of the pointer value.
Any changes done will just be for this local variable inside the function.

void foo(int &pointer){

}
which would be foo(&pointer). Now any changes done to pointer or dereferencing and changing the value held by the reference pointed to by the pointer will be changing the same outside pointer variable.


´´´
### Better explanation:
https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in

int a;
int *pointer = &a;
int &r = a;

a reference as another name for the same variable.
It is an alias for the variable. You can &pointer to get the address of the pointer, but the address of the &r is the same as &a.

- Can have arbitrary level of nested pointers to pointers, offering extra levels of indirection. References only offer one level of indirection.

- Still not sure what the point of references are, except for making temp variables to pass into functions, lists, without making pointers for the original variables and dereferencing them.

## Pointers to Pointers / 2 dimensional arrays

```
char **m_adjMatrix;
m_adjMatrix = new char*[m_maxVerts];
m_adjMatrix[index1][index2] = 1;
```

m_adjMatrix is pointer to pointer.
Pointer to first dimension, can be thought.
Then accessing that, you access second dimension. (the second pointer)

