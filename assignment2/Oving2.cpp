//
// Created by sebastian on 21.08.2020.
//

#include <iostream>
#include <string.h>
using namespace std;

void one_ab(){
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;
    cout << "&i: " << &i << endl;
    cout << "&j: " << &j << endl;
    cout << "*p, points to i: " << *p << endl;
    cout << "*q, points to j: " << *q << endl;
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << "*q = 5 + 4 = 8 = " << *q << endl;
    cout << "*q = 5 = 7 + 1 = " << *q << endl;
}


void two(){
    char *line = nullptr;   // eller char *line = 0;

    // Copy a string to a pointer, will fail as the pointer here is a nullptr
    strcpy(line, "Dette er en tekst");
}

void three(){
    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text;
    // incrementing the pointer causes stack-smashing (stack overflow bleeding into execution stack)
    while (*pointer != search_for) {
        *pointer = search_for;
        pointer++;
        //cout << pointer << endl;
    }
}

void four(){
    int a = 5;
    int &b;
    int *c;
    c = &b;
    *a = *b + *c;
    &b = 2;
}

void five(){

}

int find_sum(const int *table, int length){

}

int main(){
    //one_ab();
    //two();
    three();
    return 0;
}