#include <iostream>
#include <string>

using namespace std;

class Commodity{
public:
    Commodity(string name, int id, double price);
    double get_price(double quantity) const;
    double get_price() const;
    void set_price(double new_price);
    string get_name() const;
    int get_id() const;
    double get_price_with_sales_tax(double quantity) const;

private:
    string name;
    int id;
    double price;

};

using namespace std;

double sales_tax = 0.25;



Commodity::Commodity(string name_, int id_, double price_): name(name_), id(id_), price(price_) {}

int Commodity::get_id() const{
    return id;
}

string Commodity::get_name() const{
    return name;
}

double Commodity::get_price() const{
    return price;
}

double Commodity::get_price(double quantity) const{
    return price * quantity;
}

double Commodity::get_price_with_sales_tax(double quantity) const{
    double percent_factor = 1 + sales_tax;
    return price * quantity * percent_factor;
}

void Commodity::set_price(double new_price) {
    price = new_price;
}