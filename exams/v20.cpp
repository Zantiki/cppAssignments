//
// Created by sebastian on 03.12.2020.
//

#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <algorithm>
#include <shared_mutex>

using namespace std;

string escape(const string &text) {
    // Use const on functions that don't modify
    string new_string;

    try {
        for(auto &c: text) {
            switch (c) {
                case '<':
                    new_string += "&lt;";
                    break;
                case '>':
                    new_string += "&gt;";
                    break;
                case '&':
                    new_string += "&amp;";
                    break;
                default:
                    new_string += c;
                    break;

            }
        }
    }catch (const exception &e) {
        cout << "Text not stringy" << endl;
    }
    return new_string;
}

void escape(string &text) {
    string new_string;

    try {
        for (char const &c: text) {

            switch (c) {
                case '<':
                    new_string += "&lt;";
                    break;
                case '>':
                    new_string += "&gt;";
                    break;
                case '&':
                    new_string += "&amp;";
                    break;
                default:
                    new_string += c;
                    break;

            }
        }
    }catch (const exception &e) {
        cout << "Text not stringy" << endl;
    }
    text = new_string;
}


void oppgave1(){
    cout << escape("Escape these symbols: <<&>>") << endl;
    std::string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;
}

class Animal{
public:
    Animal(string name_): name(name_){}
    string name;
    string animal_type;

    friend ostream &operator <<(ostream &stream, Animal &animal) {
        stream << animal.animal_type << " named " << animal.name;
    }
};


class Cat: public Animal{
public:

    Cat(string name_): Animal(name_){
        this->animal_type = "Cat";
    }
};

class Dog: public Animal{
public:

    Dog(string name_): Animal(name_){
        this->animal_type = "Dog";
    }
};

void oppgave2(){
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
//animals.emplace_back(new Animal()); // Should cause compilation error
    // does not cause errors:
    // animals.emplace_back(new Animal("Max")); // Should cause compilation error
    for (auto &animal : animals)
        cout << *animal << endl;
}

void oppgave3(){
    map<long, long> results;
    vector<thread> threads;
    // Right thought, wrong initialization
    shared_lock<mutex> mutex;
    // Mulig out-of-bounds ved preincrement
    for(long x = 43; x < 47; x++)
    {
        // Ikke noe thread init, bare lambda?
        threads.emplace_back(thread([&results, &mutex, x] {
            // unngå å bruke auto når vi vet at f(x) skal være long
            // Vi må også ha tilgang til f avhenger av hvordan den er implementert
            // f.eks captures i lambda.
            long result = f(x); // Time-consuming task
            // race conditions? Bruke mutex
            mutex.lock();
            results.emplace(x, result);
            mutex.release();
        }));
    }

    for(auto &thread : threads)
        // kan ikke kalle join på et funksjonsobjekt
        thread.join();
    for(auto &pair : results)
        cout << "f(" << pair.first << ") = " << pair.second << endl;
}

class NorwegianKrone{
public:
    static double exchange_rate_euro;

    static double get_exchange_rate(){
        return exchange_rate_euro;
    }

    static double to_euro(double amount){
        return amount * exchange_rate_euro;
    }
};

double NorwegianKrone::exchange_rate_euro = 0.1;

class Euro{
public:
    static double exchange_rate_euro;

    static double to_euro(double amount){
        return amount*exchange_rate_euro;
    }
    static double get_exchange_rate(){
        return exchange_rate_euro;
    }
};
double Euro::exchange_rate_euro = 1;

template <class CurrencyType>
class Currency{
public:
    double amount;

    Currency(double amount_){
        this->amount = amount_;
    }

    ostream &operator<< (ostream &stream){
        stream << CurrencyType::to_euro(this->amount);
        return stream;
    }

    double get_euro_value(){
        return this->amount * CurrencyType::to_euro(this->amount);
    }

    /*Currency<CurrencyType> operator +(Currency<Euro> other){
        double euro_sum = other.get_euro_value() + this->get_euro_value();
        double new_amount = euro_sum;
        return Currency<CurrencyType>(new_amount);
    }*/
    template <class CurrencyType2>
    Currency<CurrencyType> operator +(Currency<CurrencyType2> other){
        double euro_sum = other.get_euro_value() + this->get_euro_value();
        double new_amount = euro_sum * CurrencyType2::get_exchange_rate();
        return Currency<CurrencyType>(new_amount);
    }
};

template <class CurrencyType>
ostream &operator<< (ostream &stream, Currency<CurrencyType> other){
    stream << CurrencyType::to_euro(other.amount) << " Euro";
    return stream;
}

void oppgave4(){
    cout << Currency<NorwegianKrone>(1) << endl;
    cout << Currency<Euro>(1) << endl;
    cout << (Currency<NorwegianKrone>(10) +
             Currency<Euro>(10) +
             Currency<NorwegianKrone>(10)) << endl;
}

void oppgave5(){
    vector<int> a = {2, 5, 2, 5, 1, 5, 1};
    vector<int> b = {2, 5, 2, 5, 1, 5, 1};
    vector<int> c = {2, 5, 2, 5, 1, 5, 1};

    swap_ranges(a.begin(), a.begin() + 3, a.end()-3);
    rotate(b.begin(), b.begin()+1, b.end());
    transform(c.begin(), c.end(), c.begin(), [](int e){
        return e*2;
    });


    for (auto &e : a)
        cout << e << endl;
    cout << "\n" << endl;
    for (auto &e : b)
        cout << e << endl;
    cout << "\n" << endl;
    for (auto &e : c)
        cout << e << endl;
}

int main(){
    oppgave1();
    oppgave2();
    oppgave4();
    oppgave5();
    return 0;
}