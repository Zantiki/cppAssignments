# Life and death

## Scope
Variables only live inside the their respective brackets
```c++
{
    // variable a cannot be accessed outside brackets
    int a = 2;
}
```
For some objects you might need to use a deconstructor
(defined with ~in front of constructor):
```c++
class Object{
public: 
    Object(){
        // This is a constructor
        }
    ~Object(){
        // This is a deconstructor
    }
};

int main(){

    {
        Object o; // Object() is called
    } // ~Object() is called

}
```
When destroying an object with scopes, 
the memory in the heap will be freed. This is particularily
practical with strings.

We can store an object on the heap (dynamnic memory)
 and point to it. Doing it this way, will not cause 
 the deconstructor to be called when scope ends.
 Using unique pointer will solve this automatically.
```c++
{
    Object *o = new Object(); // Object not deleted, but pointer is
}

{
    // will delete object and pointer
    Object *o = new Object();
    delete o
}

{
    // will also delete object and pointer
    unique_ptr<Object> o(new Object());
}
```
Using smart pointers is generally good practice as avoids
the issue of predetermining when a pointer should be destroyed.

## Smart Pointers
There are primarily two types of smart pointers:
* unique_ptr: stops copying of references 
(use move() function instead), automatic deconstrution 
when leaving scope.
* shared_ptr: used for reference-counting,
 a form of garbage collection
 
unique_ptr's object can also be deleted by setting 
it as a nullpointer. It will also be deleted when
assigning to a new pointer with another object.
 ```c++
// Delete the object
unique_ptr<Object> o(new Object());
o = nullptr

// Reassign object, will delete old one.
o = unique_ptr<Object>(new Object)
```
### Operator Overloading
There are two types of operators:
* binary: two operators
* unary: one operator

When defining object-specific operators:
 ```c++
// General definition,  used for + - \ *
Object Object::operator+(const Object &other){
    return Object(other.member + *this.member)
}
// Operators that do assignment
// i.e +=, -= ++, --, *=, \=
Object Object::&operator+=(const Object &other){
    *this.member = other.member + *this.member
    return *this
}

// Bool operators
bool Object::operator==(const Object &other){
    return other.member == *this.member
}
 ```
when conducting arithmetic with operators the
first line will be the same as calling the
operator method as so:
> object1 + object2 =
> object1.plus(object2)

Because of how the operators are implemented they
can be chained together. This called being _associative_.

For doing arithmetic with the first operand not being
of the specified object type, the use the following:
 ```c++
// "this" is not invoked as first operand 
// When function is not defined as member of Object.  
friend Object::operator+(int value1, const Object &object){
    return Object(value1 + *object.member);
}
 ```
We can also redefine operators for external classes
by writing our own function.
 ```c++
ostream &operator<<(ostream &out, const Object &object){
    out << object.member;
    return out;
}
 ```

operators ++ and -- are interpreted as binary when
defining, but as unary when calling. -> will be 
interpreted as unary if overloaded.