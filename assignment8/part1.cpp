//
// Created by sebastian on 28.09.2020.
//

#include <iostream>
#include <cmath>
using namespace std;

template<typename Type>

bool equal(Type a, Type b) {
    cout << "Calling template" << endl;
    double diff = abs(a - b);
    return diff < 0.00001;
}

bool equal(double a, double b) {
    cout << "Calling special" << endl;
    double diff = abs(a - b);
    return diff < 0.00001;
}

int main(){
    double a = 3.000001;
    double b = 3.001;
    int a1 = 3;
    int b1 = 3;

    cout << "Equal special:\n"  << equal(a, b)<< endl;
    cout << "Equal template:\n"  << equal(a1, b1)<< endl;
}