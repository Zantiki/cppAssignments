# Templates
Templates are a general functions/classes that can be used by
multiple different datatypes. The general algorithm is predefined
and can then be used in varying situations.
An example of a template function:

```c++
// Give the type a descriptive name
template <typename Type>
int sum(const Type &data){
    int total_sum;
    
    for(int i: data){
        total_sum += static_cast<int>(data);
    }
    return sum;
}
``` 
On runtime the template is replaced with the actual datatype
f.ex:
```c++
vector<int> table{1,2,3};

// The template will be replaced with the vector.
int total_sum = sum(table);
```
It is up the the user how many generic types they include
in a given function:
```c++
template <typename T1, typename T2>
void print(const T1 &arg1, const T2 &arg2 ){
    cout << arg1 << " " << arg2 << endl;
}
```
In order for an Template-function to work, you need 
to use all of the generic types defined in template<>
this means that if you'd like to make en return of type t, 
then t has to be part of the argument.
We seperate templates from overloads, where overloads
have varying prototypes that are selected based on the type of input.
We sperate from inherited functions where the arguments are the
same, but the contents of the functions are different.
All of these types of functions are considererd polymorphic.

To ensure consistent typing, use casting:
```c++
int test = static_cast<int>(2.01);

// If we are dealing with polymorphism, use dynamic_cast
// Take note of the pointer, won't work with static
SpecializedObject so(parmas);
GeneralObject go = dynamic_cast<GeneralObject*>(so);
```

We can define classes that have template members, f.ex:
```c++
template <typename Type>
class Values {
public:
    Type t1, t2;
    
    int sum(const Values &v1){
    int sum = static_cast(*this.t1) + static_cast(*this.t2)
    return sum + static_cast<int>(v1.t1) + static_cast<int>(v1.t2)
    };
};
```
# STL Algorithms
 All of the below functions require iterators
## Algorithms that search
```c++
// Returns end of iterator on not found
find(v1.begin(), v1.end(), value_to_find)
// Search for parts of an iterator within another iterator
// Useful for strings.
find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
// Find to equal elements next to one another.
adjacent_find(v1.begin(), v1.end());
// Count amounts of specific number.
count(v1.begin(), v1.end(), 3);
// Find the max-element, use a ptr as it returns iterator
*max_element(v1.begin(), v1.end());
```
## Algorithms to manipulate data
```c++
// Swap contents of vectors
swap(v1, v2);
// Resize a vector
v1.resize(v1.size() + v2.size());
// Copy iterator over to part of a different iterator
copy(v2.begin(), v2.end(), v1.begin() + old_size);
// insert new element
v1.insert(v1.end(), v2.begin(), v2.end());
// Swap contents of a given range
swap_ranges(v1.begin(), v1.begin() + 5, v1.begin() + 5);
// Fill a given range with a specified value
fill(v1.begin(), v1.begin() + 5, 3);
// Same as copy, where specified numbers are 
// replaced with one another
replace_copy(v1.begin(), v1.end(), copy.begin(), 3, 300);
// Copy backwards
reverse_copy(v1.begin(), v1.end(), v1_reversed.begin());
// Shift the vector a specified number of positions forward.
rotate(v1.begin(), v1.begin() + 3, v1.end());
// generate a single permutation of len(table)! number
// of permutations.
next_permutation(table.begin(), table.end());

// Same as python-map:
transform(table.begin(), table.end(), table.begin(), [](int e){
    return e*2;
});

```
## Algorithms for sorting data
```c++
// Lowest index of a given number
lower_bound(v1.begin(), v1.end(), 17);
// Check if part of an iterator exists within another one
includes(v1.begin(), v1.end(), v2.begin() + 1, v2.begin() + 3))
// Merge two iterators 
merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
// Remove duplicates
unique(result.begin(), result.end());
// Remove part of iterator
result.erase(end, result.end());
// Return the union of two iterators
set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
// Return the intersection of two iterators
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
```