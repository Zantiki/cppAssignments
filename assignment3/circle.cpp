//
// Oppgave 1
// Created by sebastian on 27.08.2020.
//

const double pi = 3.141592;

class Circle {
public:
    // Set c in circle to uppercase
    Circle(double radius_);
    int get_area() const;
    double get_circumference() const;
private:
    // moved radius definition
    double radius;
}; // Added semicolon

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() const {
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    double circumference = 2.0 * pi * radius;
    return circumference;
}

#include <iostream>

using namespace std;

int main() {
    Circle circle = Circle(5);

    double area = circle.get_area();
    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}