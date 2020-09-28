//
// Created by sebastian on 24.09.2020.
//

#include <functional>
#include <iostream>


#pragma once

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(){
        numerator=0;
        denominator=1;
    };
    Fraction(int numerator, int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    };
    /*void set(int numerator_, int denominator_ = 1);
    Fraction operator+(const Fraction &other) const;*/
    Fraction operator-(const Fraction &other) const{
    int right_numerator = this->numerator * other.denominator;
    int right_denominator = this->denominator * other.denominator;
    int left_numerator = other.numerator * this->denominator;
    int left_denominator = other.denominator * this->denominator;
    return Fraction(right_numerator-left_numerator, right_denominator);
};
   /* Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;*/
    Fraction operator-(int other) const {
        Fraction other_fraction = Fraction(other, 1);
        return Fraction(this->numerator, this->denominator) - other_fraction;
    };
    /*Fraction &operator++(); // Preinkrement
    Fraction &operator--(); // Predekrement
    Fraction &operator+=(const Fraction &other);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);
    Fraction &operator=(const Fraction &other);
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;*/

private:
    void reduce();
    int compare(const Fraction &other) const;
};

Fraction operator-(int caller, const Fraction &other){
    Fraction first_fraction = Fraction(caller, 1);
    return  first_fraction - other;
}

int main(){
    Fraction fraction = Fraction(5, 5);
    Fraction test1 = fraction - 5;
    std::cout << test1.numerator << "/" << test1.denominator << std::endl;
    Fraction test2 = 5 - fraction;
    std::cout << test2.numerator << "/" << test2.denominator << std::endl;

    Fraction frac1 = Fraction(1, 2);
    Fraction frac2 = Fraction(4, 8);

    Fraction final_fraction = 5 - 3 - frac1 - 7 - frac2;

    /* Theory explained (method_calls are called within function object, function_calls are called on normal operators):
     * 5 - 3 = 2
     * 2 - Fraction(1,2) = function_call -(2, Fraction(1,2)) = Fraction(3, 2)
     * Fraction(3, 2) - 7 = method_call -(Fraction(3, 2), 7) =
     * method_call -(Fraction(3, 2), Fraction(7, 1)) = Fraction(-11, 2)
     * method_call -(Fraction(-11, 2), Fraction(4, 8)) = Fraction(-96, 16)
     *
     * If we use '-' ahead of the object that overloads, we will use the one implemented in the function or default to
     * standard '-', i.e 1-1 (default '-'), obj-1 (object overloaded '-'), 1-obj (function overloaded '-')
     * */
    std::cout << final_fraction.numerator << "/" << final_fraction.denominator << std::endl;
}