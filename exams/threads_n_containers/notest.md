# Threads
Threads are initialized like so:
```c++
// Variables can be included in the capture list
thread test([]{
    cout << "i am a thread" << endl;   
});
```
A program can wait for a thread to finish or
detach it:
```c++
// Wait for thread
thread.join();

// Detach from proc
thread.detach();

// If you want to pause the thread
thread::sleep_for(10ms);
```
When using detach be careful that any referenced
variables within the thread presist while thread
is alive. To avoid this problem, convert the
shared object to a shared pointer:
```c++
auto message = make_shared<string>("some message");

// when using this in s thread, make sure you pass the
// pointer, not the refrence.

thread test([massage]{
    cout << message << endl;
});
test.detach();
```
When several threads are manipulating
the same variable, make use of the mutex object.
There are two ways of doing this:
```c++
int shared_variable;

// method 1 (Preferred) mutex will unlock 
// on ended scope.
{
    // use static for thread-safe 
    // initialization of mutex inside a thread
    static mutex variable_mutex;
    lock_guard<mutex> lock(variable_mutex);
    shared_variable = 2;
}
// method 2, unsafe
mutex variable_mutex();
variable_mutex.lock();
shared_variable = 2;
variable_mutex.unlock();
```
The usage of static makes the mutex a singleton,
meaning only one instance of the object can exists within 
a given process.

### Asyncronous services
Thinks server, with several threads being managed
under a single class (Usually called worker)
where tasks (usually functions, or lambda) kan be
submitted to be executed on one of the threads.
in C++ this is usually implemented with the _boost_
library.

The worker initilizer using boost looks like this:

```c++
// Worker needs to have boost service within scope
boost::asio::io_service service;
Workers(size_t number_of_threads) : work(service) {
    for (size_t c = 0; c < number_of_threads; ++c) {
      threads.emplace_back([this] {
        service.run(); // Wait for, and execute, tasks until service.stop() is called
      });
    }
```
Append a task worker like so:
```c++
Workers workers(4);
workers.post([]{
    cout << "I am a thread in a worker" << endl
})
```

Asyncronous services usually use an event-loop
instead of a _main_-function to execute workers.
An excellent example of this is Node.js.

For boost event-loops are just single-threaded
workers with workers within itself.

It is also possible, with a bit of clever programming
and with the _boost::asio::ip_ namespace to implement
a simple server that can handle multiple connections
on a single thread.
the following _boost_-methods are critical
to making this possible:
* async_read_until
* async_accept
* async_write


# Containers
Containers are part of STL, and are used as wrappers
for various data such as _vector_, _set_ and _map_
to name a few.
The _vector_ container is the C++ equivalent of 
list in Python.

A container is generally initialized like so:
```c++
container<type_within>;
// irl example:
vector<int>;
```
Vector is by far one of the more important containers
and has the following methods:
```c++
vector<int> int_vector;

// most efficient append
int_vector.emplace_back();

// less efficient append
int_vector.emplace();

// Find the current size:
int_vector.size()
// Find the current capacity:
int_vector.capacity();
```
When filling a vector with objects, all 
you need to do is pass the object-paramates 
when emplacing, like so:
```c++
vector<Object> objects;
// this will initilize the object 
// with the specified parameters, requires 
// relevant data members to be public.
objcts.emplace_back(object_paramater);
```
When working with vectors (or other iterators)
looping can be made more efiicent buy using the
auto keyword:
```c++
for (auto &object: objects ){
    cout << object << endl;
};
```

### Iterators
The return vale of an iterator is a pointer, to refrence the value
within the iterator use (*iterator).
Looping through iterators can be made simple by:
```c++
// For an iterator with objects
for (auto it = iterator.begin(); it != iterator.end; ++it){
    cout << (*it).member << endl;
    cout << it->member << endl;
}
```
Please note that when looping through iterators you should be
incrementing by _++i_ and not _i++_ to avoid two copies of _i_.
this is particularily important when working with objects.
# Libraries
A library is in this context a pre-compiled
implementation of various classes and functions
for usage in a given program.
### Static Libraries
installed libraries can be found under on linux.
>/user/lib
> 
>/user/local/lib

compiled c/c++ code is stored in object files
(extention .o)
### Dynamic Libraries
Generally packages are downloaded from a
package repositiory (i.e apt-get, windows 
lacks this).
### Makefiles
To build a library you generally need to use
a build-command with the compiler of
your choice.

Generally makefiles are preferred fo this
as some build options are rather complicated.
You build C++ libraries by using the _make_-command.
Under you find some useful make-commands:

Think node-commands (npm install, npm build, etc)
```shell
make all # Build full project, libraries and all
make install # Install necessary libraries
make clean # clean up libraries and executables.
```

Alternativly you can use cmake, which is even easier.
running the _cmake_ command will autogenerate one of
these files. When you want to add a library to your
project, add the following lines to your cmakelists.txt
```cmake
# Will add boost library to project.
cmake_minimum_required (VERSION 2.6)
project (ExampleProject)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost 1.55.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(example example.cpp)
target_link_libraries(example ${Boost_LIBRARIES})
```

Some useful libraries:
* boost: asynconous services
* sfml: sound, image and input
* gtkmm: GUI-library.