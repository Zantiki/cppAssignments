//
// Created by sebastian on 31.08.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_test(){
    double to_insert = 555;
    vector<double> numbers = {1.2, 2.1, 3.2, 2.3, 4.2};

    cout << "Number in front: " << numbers.front() << endl;
    cout << "Number in back: "<< numbers.back() << endl;

    numbers.emplace(numbers.begin()+1, to_insert );

    cout << "Number in front: " << numbers.front() << endl;

    vector<double>::iterator result = find(numbers.begin(), numbers.end(), to_insert);

   if (result != numbers.end()){
       cout << "The number exists: " << *result << endl;
   }else{
       cout << "The number does not exist" << endl;
   }

}

int main(){
    find_test();
    return 0;
}

