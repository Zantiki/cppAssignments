//
// Created by sebastian on 21.08.2020.
//

#include <iostream>
#include <string.h>
using namespace std;

void one_ab(){
    cout << "Assignment one" << endl;
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
    cout << "*q = 5 + 3 = 8 = " << *q << endl;
    cout << "*q = 5 = 7 + 1 = " << *q << endl;

    cout << "\n" << endl;
}


void two(){
    char *line = nullptr;

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
    }
}

void four(){
    int a = 5;
    // Moved for proper definition and assigned to int rather than reference
    int b = 2;
    // Cannot assign reference without pointer
    int *b2 = &b;
    int *c;
    c = &b;
    // Cannot do arithmetic on pointers, changed to regular variable
    a = *b2 + *c;
}

void five(){
    cout << "Assignment five" << endl;
    double number = 10;
    double *num_pointer = &number;
    double &number2 = *num_pointer;

    // Method one:
    number = 11;
    cout << number << endl;

    //Method two:
    *num_pointer = 12;
    cout << number << endl;


    //Method three:
    double *number3 = &number2;
    *number3 = 13;
    cout << number << endl;
    cout << "\n" << endl;
}

int find_sum(const int *table, int length){
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += table[i];
    }
    return sum;
}

void six(){
    cout << "Assignment six" << endl;
    int table[20];

    for(int i = 0; i < 20; i++){
        table[i] = i+1;
    }
    const int *table_pointer = table;

    int sum_of_ten = find_sum(table_pointer, 10);
    cout << "Result, ten first: " << sum_of_ten << endl;

    int five_next = find_sum(table_pointer+10, 5);
    cout << "Result, five next: " << five_next << endl;

    int five_last = find_sum(table_pointer+15, 5);
    cout << "Result, five last: " << five_last << endl;

    cout << "\n" << endl;

}


int main(){
    one_ab();

    //  Functions that break
    /*
    two();
    three();
     */
    four();
    five();
    six();
    return 0;
}