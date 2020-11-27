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
