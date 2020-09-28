//
// Created by sebastian on 24.09.2020.
//
# include <vector>
# include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class Set{
public:
    std::vector<int> set_vector;

    Set(){
        this->set_vector={};
    }

    Set(std::vector<int> init_vector){

        vector<int>::iterator ip;
        vector<int> cleaned;

        ip = std::unique(init_vector.begin(), init_vector.begin() + init_vector.size());
        init_vector.resize(std::distance(init_vector.begin(), ip));

        for (ip = init_vector.begin(); ip != init_vector.end(); ++ip) {
            cleaned.push_back(*ip);
        }

        this->set_vector = cleaned;
    }

    void operator=(Set other) {
        this->set_vector = other.set_vector;
    }

    void operator=(int other) {
        this->set_vector = {other};
    }

    Set operator+(const Set &other) {
        vector<int> result = this->set_vector;
        for(int i = 0; i < other.set_vector.size(); i ++){
            result.push_back(other.set_vector[i]);
        }
        return Set(result);
    }


    Set operator+(int element) {
        vector<int> new_vector = this->set_vector;
        new_vector.push_back(element);
        return Set(new_vector);

    }

    // We need to use friend-functions for operators in the case of left-side calls.

    friend ostream& operator<<(ostream& os, Set& other){
        std::string tmp = "{ ";
        for (int i = 0; i < other.set_vector.size(); i++){
            tmp += to_string(other.set_vector[i]) +" ";
        }
        return os << tmp +"}";
    };

    friend Set operator+(int element, Set& set){
        vector<int> new_vector = set.set_vector;
        new_vector.push_back(element);
        return Set(new_vector);
    };


};

int main(){
    Set set1 = Set({1,2,3,3,3});
    Set set2 = Set({4,5,6,6,6,6,6});
    Set result = set2 + set1;

    cout << "-- Sorted set and union --" << endl;
    cout << set1 << endl;
    cout << result << endl;

    cout << "\n-- New element appended --" << endl;
    Set set3 = set1 + 50;
    set3 = set3 + 50;
    Set set4 = 51 + set1;
    cout << set3 << endl;
    cout << set4 << endl;

    cout << "\n-- Assignment --" << endl;
    Set set5 = Set({10, 11, 12});
    Set set6 = Set({13, 14, 15});
    set5 = 1;
    set6 = set3;
    cout << set5 << endl;
    cout << set6 << endl;
}