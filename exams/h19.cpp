//
// Created by sebastian on 30.11.2020.
//
#include <thread>
#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

void swap(int &a, int &b){
    int temp_a = a;
    a = b;
    b = temp_a;
}

void swap(int *a,  int *b){
    int tmp_ptr = *a;
    *a = *b;
    *b = tmp_ptr;
}

void swap(int *a,  int &b){
    int a_value = *a;
    //int *a_address = a;
    *a = b;
    b = a_value;
}

void oppgave1(){
    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << ' ' << b << std::endl;
    swap(&a, &b);
    std::cout << a << ' ' << b << std::endl;
    auto c = &a;
    auto d = &b;
    swap(c, *d);
    std::cout << *c << ' ' << *d << std::endl;
}


class Degrees{
public:

    class Hot{
    public:
        string to_string(){
            return "hot";
        }
    };

    class Cold{
    public:
       string to_string(){
            return "cold";
        }
    };

    string operator +(){
        return Hot().to_string();
    }

    string operator -(){
        return Cold().to_string();
    }
};

/*ostream &operator <<(ostream &stream, Degrees::Hot temp){
    stream << temp.to_string();
};

ostream &operator <<(ostream &stream, Degrees::Cold temp){
    stream << temp.to_string();
};*/

void oppgave2(){
    Degrees degrees;
    cout << +degrees << endl;
    cout << -degrees << endl;
}

void oppgave3() {

    // Pekere gjort unique og taes inn som referanser i thread, brackets
    // er fjernet for å sørge for at a og b fortsatt eksisterer ved joining

    std::thread *a_thread;
    // a og b lever kun i bracketene, vi vil ikke kunne referere til de
    // i threaden
    unique_ptr<int> a = make_unique<int>(2);
    unique_ptr<int> b = make_unique<int>(2);

    // b tas in som kopi av peker.

    a_thread = new std::thread([&a, &b] {
        std::cout << (*a + *b) << std::endl;
    });
    a_thread->join();
}

class Electric{
public:
    static string to_string(){
        return "electric";
    }
};

class Gasoline{
public:
    static string to_string(){
        return "gasoline";
    }
};

class Car{
public:
    string descriptor;

    ostream &operator<< (ostream &stream){
        stream << this->to_string();
        return stream;
    }

    string to_string() const {
        return this->descriptor;
    }
};

template <class EngineType>
class Saab: public Car{
public:
    Saab(){
        descriptor="SAAB with "+EngineType::to_string()+" engine";
    }
};

template <class EngineType>
class Volvo: public Car{
public:
    Volvo(){
        descriptor="Volvo with "+EngineType::to_string()+" engine";
    }
};

ostream &operator<< (ostream &stream, Car &car){
    stream << car.to_string();
    return stream;
}

void oppgave4(){

    vector<unique_ptr<Car>> cars;
    cars.emplace_back(new Saab<Electric>());
    cars.emplace_back(new Saab<Gasoline>());
    cars.emplace_back(new Volvo<Electric>());
    for (auto &car : cars)
        cout << *car << endl;
}

void oppgave5(){

    // Segfault
    // Kopiere hele v2 på slutt av v1
    // {1, 2, 3, 4}
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    // Writes to initialized memory, potential buffer overflow
    // v1.resize(v1.end() - v1.begin() + 2);
    copy(v2.begin(), v2.end(), v1.begin() + 2);
    for (auto e : v1)
        cout << e << endl;
    cout << "\n" << endl;

    // setter inn første element fra på v3
    // printer {1, 2, 3}
    vector<int> v3 = {1, 2};
    vector<int> v4 = {3, 4};
    v3.insert(v3.end(), v4.begin(), v4.begin() + 1);
    for (auto e : v3)
        cout << e << endl;
    cout << "\n" << endl;
    //Finner alle tall over > 2
    // $ 3
    vector<int> v5 = {1, 2, 3, 4};
    cout << *find_if(v5.begin(), v5.end(), [](int e) {
        return e > 2;
    }) << endl;


    vector<int> v6 = {1, 2};
    vector<int> v7 = {3, 4};
    // Sjekker et den ene vectoren er 2 mindre enn den andre.
    // $ true
    cout << equal(v6.begin(), v6.end(), v7.begin(), [](int e1, int e2) {
        return e1 == e2 - 2;
    }) << endl;

    // Sjekker et den ene vectoren er 2 større enn den andre. her er det motstatt vei
    // $ true
    vector<int> v8 = {1, 2};
    vector<int> v9 = {3, 4};
    cout << equal(v9.begin(), v9.end(), v8.begin(), [](int e1, int e2) {
        return e1 == e2 + 2;
    }) << endl;
}


int main(){
    oppgave1();
    oppgave2();
    oppgave3();
    oppgave4();
    oppgave5();
    return 0;
}