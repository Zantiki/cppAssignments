//
// Created by sebastian on 28.09.2020.
//
#import <iostream>
using namespace std;

template <typename Type1, typename Type2>

class Pair{
public:
    Type1 first;
    Type2 second;
    Pair(Type1 a, Type2 b){
        this->first = a;
        this->second = b;
    };

    bool operator>(Pair &other){
        Type1 this_sum = this->first + this->second;
        Type1 other_sum = other.first + other.second;

        return this_sum > other_sum;
    }

    bool operator<(Pair &other){
        Type1 this_sum = this->first + this->second;
        Type1 other_sum = other.first + other.second;

        return this_sum < other_sum;
    }

    Pair operator+(Pair &other){
        Type1 new_first = this->first + other.first;
        Type2 new_second = this->second + other.second;
        Pair<Type1, Type2> p3(new_first, new_second);
        return p3;
    }
};

int main(){
    /*
     * Assuming we have operators implemented for all the different types of data that Type1 and Type2 can be,
     * We simply use our Templates withing the operators and let the "existing" operators deal with each case.
     * For instance, the current implementation assumes that we have > implemented for a double > int. If this
     * was not the case, we would have gotten typing errors at our > operator.
     */
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;

}