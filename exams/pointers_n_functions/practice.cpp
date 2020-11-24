//
// Created by sebastian on 23.11.2020.
//
#include "iostream"
using namespace std;

int value_transfer(int a, int *b){
    for(auto i = 0; i < 4; i++){
        int *val = b + i;
        cout << i << ", " << *val + a << endl;
        b[i] = *val + a;
        //b = b + i;
    }
    cout << "\n" << endl;
    int *c = (b + 2);
    return *c;
}

int pointer_fun(){
    cout << "test" << endl;
    int list[10];
    list[0] = 5;
    list[1] = 3;
    int *test = list + 1;
    int *test_2 = test - 1;

    int another_one = *test_2;
    list[0] = 8;

    cout << another_one << endl;

    int &ref = another_one;
    another_one = 10;
    cout << *&ref << endl;

    int b[4];
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;

    int c = value_transfer(2, b);

    cout << c << endl;
    return 0;
}

int main(){
    pointer_fun();
}