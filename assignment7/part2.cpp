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
        this->set_vector = clean_vector(init_vector);
    }

    Set operator=(Set& other) {
        this->set_vector = other.set_vector;
        return Set(this->set_vector);
    }

    Set operator+(const Set &other) {
        vector<int> result = this->set_vector;
        for(int i = 0; i < other.set_vector.size(); i ++){
            result.push_back(other.set_vector[i]);
        }
        return clean_vector(result);
    }


    Set operator+(int element) {
        vector<int> new_vector = this->set_vector;
        new_vector.push_back(element);
        return Set(new_vector);

    }

    friend ostream& operator<<(ostream& os, Set& other);
    friend Set operator+(int element, Set& set);

private:
    std::vector<int> clean_vector(std::vector<int> check_vector){

        vector<int>::iterator ip;
        vector<int> cleaned;

        ip = std::unique(check_vector.begin(), check_vector.begin() + check_vector.size());
        check_vector.resize(std::distance(check_vector.begin(), ip));

        for (ip = check_vector.begin(); ip != check_vector.end(); ++ip) {
            cleaned.push_back(*ip);
        }
        sort(cleaned.begin(), cleaned.end());
        return cleaned;
    }


};

ostream& operator<<(ostream& os, Set& other){
    std::string tmp = "{ ";
    for (int i = 0; i < other.set_vector.size(); i++){
        tmp += to_string(other.set_vector[i]) +" ";
    }
    return os << tmp +"}";
}

Set operator+(int element, Set& set) {
    vector<int> new_vector = set.set_vector;
    new_vector.push_back(element);
    return Set(new_vector);
}

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

    // Todo: Fix assignment operator.

    cout << "\n-- Assignment --" << endl;
}