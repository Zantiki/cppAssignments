# OOP
## String:
More often then not, you'd like to conver a string to a number.
To do this, you can use osstreams:
```c++
#include <sstream>
string to_string(int number){
    osstringtream oss;
    oss << number;
    return oss.str()
}
```
Same method can be leveraged to parse numbers to string

```c++
int to_int(string number_string){
    istringstream iss;
    int int_number;
    iss.str(number_string)
    iss >> int_number;
}
```
istringstream can also parse several different number types:
```c++
istringstream iss;
int int_number;
double dub_number;
iss.str("2 2.5");
// Will hold 2
iss >> int_number;
// Will hold 2.5
iss >> dub_number;
```

## Basic Class
Example of a standard class:
```c++
class Object{
public:
    Object(const string &immutable_, int mutable_);
    const int get_immutable() const;
    int get_mutable() const;
    
private:
    string immutable;
    int mutable;
};

Object::Object(const string &immutable_, int mutable_) : immutable(immutable_), mutable(mutable){}

const int Object::get_immutable() const {
    return immutable;
}

int Object::get_mutable() const{
    return mutable;
} 

int main(){
    Object test("test_object", 1);
    return 0;
}
```

Classes can be split into several files using .hpp and .cpp files
hpp usually contains the prototypes, while .cpp contains the implementation.
using the keyword _#pragma_ _once_ we make sure that the .hpp decleration is only used one
if there are multiple imports.
## Polymorphic class
Polymorphism isn't too much fuzz, but to ensure that it works properly
we have to use declerations _virtual_ and _override_
f.ex:
```c++
class General{
public:
    string id;
    General(const string &id): id(id_){}
    
    // Super has virtual, on beginning
    virtual void print() const{
        cout << "General" << endl;
    }
};

class Special{
public:
    string special_id;
    Special(const string &general_id, const string &special_id) : General(general_id), special_id(special_id){}
    // subclass has override on end
    void print() const override{
        General::print()
        cout << "NOT!!!" << endl;
    }
};
```

use dynamic_cast<Subclass*>(object) when you want to 
have a specific class-pointer.

You can declare classes as abstrect by setting the member functions
like so:
```c++
virtual void Object::print(const string &text) const = 0;

// These can be used in other definitions in the abstract object.
void Object::print_all(string *texts){
    while (texts){
        this->print(*texts);
        texts++;
    }
}
```

## Tips and tricks
* Using const: when a function does not change the data within an object
* Refrencing objects within objects: use &object2 (refrence) instead of passing
a copy of object2 to avoid uneccesary resource usage.
* When returning a value within a object, make sure to use const
if it is a refrence to avoid manipulation. i.e _const_ _int_ _&get()_ and
  not _int_ _get()_
* avoid using the standard constructor.
* You can have several implementations of the constructor to avoid
all input-arguments.
* When referring to classes within classes, use refrences.

When using an object as input for a function, define the function like so:

```c++
double get_something_in_object(const Object &object) const;

// Doing it this way lets you call the functions like:

get_something_in_object(Object())
// and
Object object()
get_something_from_object(object)
```
# Lambda
## Expression
Lamdas follow a certain type of expression, like so:
```c++

[&variable_to_capture](const int &variable_to_pass){
    // Variables from capture-list are available in the internal scope.
    // Passed variables are available like normal.
}


```