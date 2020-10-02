//
// Created by sebastian on 01.10.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    vector<int> v2 = {2, 3, 12, 14, 24};

    auto v1_find_if_result = find_if(v1.begin(), v1.end(), [](int number){
        if(number > 15) return true;
        return false;

    });
    int result_index = v1_find_if_result - v1.begin();
    cout << "find_if result: " << v1[result_index] << endl;

    bool v1_equal_v2_5 = equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int number1, int number2){
        if (abs(number1 - number2) > 2){
            return false;
        };
        return true;
    });

    bool v1_equal_v2_4 = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int number1, int number2){
        if (abs(number1 - number2) > 2){
            return false;
        };
        return true;
    });
    cout << "equal result [v1.begin(), v1.begin() + 5>: " << boolalpha << v1_equal_v2_5 << endl;
    cout << "equal result [v1.begin(), v1.begin() + 4>: " << boolalpha << v1_equal_v2_4 << endl;

    vector<int> v1_replaced;
    v1_replaced.resize(v1.size());

    replace_copy_if(v1.begin(), v1.end(), v1_replaced.begin(), [](int number){
        if (number % 2 > 0) return true;
        return false;
    }, 100);

    string vector_string = "{ ";
    for (int value:v1_replaced){
        vector_string += to_string(value) +" ";
    }
    vector_string += "}";
    cout << "replaced vector: " << vector_string << endl;
}