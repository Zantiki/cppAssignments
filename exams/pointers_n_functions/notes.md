## Pointers and refrences
initilizantion:
A reference is the address of a variable, where the pointer fetches
the value at the referenced address.

\* is called the dereferencing-operator

& is called the address-operator

```c++
int ref = value_to_point_to;
int *pointer = &ref;
```

refrencing a pointer, i.e \*&pointer or &\*pointer will be the
 value of pointer.

### Arrays as pointers
```c++
// Table is interpreted as the address
// to the first element in array
int table[10];

// Fetch 5th element in table
int *element = &table[4];

// We can move around the array as so, here calling next() will
// result inn table[4] being returned.
*table = table[3];

// Other than that you can assign elements normally:
table[2] = 8; 

// To assign value at pointer to regular variable:
int x = *element;

// X will be address of element: 
int x = element;

``` 

### Const pointer
Used to prevent modification through the pointer to the value
it points to.
```c++

int i = 100;
int *const i = &i;
// works for  below as only pointer is const:
*i = 101;
// But does NOT work for code below
int y = 101;
*i = &y
// Below code will also NOT work:
const int i = 100;
int *const i = &i;
*i = &y
i = 101
``` 

### Pointer operations
Primary use-cases for for pointer-arithmetic are +/-. These can
be used to traverse an array like so:

```c++
int table[10];

// Will point to second value in table
int *value_1 = table + 1;

// Will point to first value in array
int *value_2 = value_1 - 1;
```
### Argument transfer
C++ uses two different types of argument-transfer.
* Value-transfer: copy of an a given argument, or 
in the case of arrays address-transfer.
* Referense-transfer: A function is working with 
predefined variables outside its scope. Commonly used when
input/output are the same variables. Here refrences must be const,
for the sake of referring to the same variable the entire way.
### Pitfalls
* Pointers are interpreted as raw addresses and such it can
lead anywhere, and cause all kinds of problems. You compiler
might not save you.
* Pointers with no clear definition of how much memory should be used
are dangerous and can overwrite anything. Assigning it to a string works
but is not ideal if you wish to modify the string later on. Use
'_const char *string_' for safety.
* Refrences are in simple terms another name for a given variable, i.e
names for an area in memory. As such they have to be initilized 
with a pre-existing variable.
