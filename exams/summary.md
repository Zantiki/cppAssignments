# Exam evaluation
## Re-occuring errors:
* Avoid using to_string if you can overload ostream directly //
* incorrect implementation of in-object ostreams, they
should be defined a friend-functions on binary operands //
* use str() definition instead of to_string() //
* use template <class TypeClass> correctly //
* std::move to move unique pointer. //
* Make better use of const keyword. //
* use auto for val:iter when looping iterator //
* use overridable function instead of static paramter? //
* redfinition of template class on different different
templates as input. //
* make use of abstract functions //
* pass mutex as reference and use lock_guard //

### Overloaded ostream and to_strings:
use the following snippet to overload binary << operand within an object:
```c++
class Object{
    friend ostream &operator <<(ostream &stream, Object &object){
        ostream << object.printable;
        return ostream;
    }
};
```
Use str() in C++, _not_ to_string();

### Better iterator traversal
vectors can be iterated easily.
```c++
vector<int> vec = {1, 2, 3};

for(auto &iteration: vec){
    cout << iteration.printable << endl;
}
```

### Polymorphism, abstractions and objects:
inheritance and overrides:
```c++
class General{
    virtual void overridable_abstract_method() const = 0;
};

class Special: public General{
    void overridable_abstract_method() const override {
        cout << "overridden" << endl;
    }
};
```
class template example:
```c++
template <class PrintableType>
class SomeObject{
    const string str(){
        return PrintableType::str();
    }
    
    template <class PrintableType2>
    const string print_another(const PrintableType2 &other){
        cout << this->str() << other.str() << endl;
    }
};

class OtherObject{
    static const str(){
        return "test";
    };
};

auto object = SomeObject<OtherObject>()
cout << object.str() << endl;
```

### Thread, Mutex and unique_ptr
Thread-safe mutex init:
```c++
vector<int> shared_variable;
unique_ptr<Object> unique_object= make_unique<Object>(new Object());
// move unique pointer to scope of thread
thread test_thread([u = move(unique_object), &shared_variable](){
    // thread-safe init
    static mutex variable_mutex;
    lock_guard<mutex> lock(variable_mutex);
    shared_variable.emplace_back(*(u).integer_inside)
})


```