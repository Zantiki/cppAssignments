//
// Created by sebastian on 28.09.2020.
//

#include <iostream>
#include <cmath>
using namespace std;

template<typename Type>

bool equal(Type a, Type b) {
    double diff = abs(a - b);
    return diff < 0.00001;
}

int main(){
    double a = 3.000001;
    double b = 3.001;
    cout << equal(a, b)<< endl;
}