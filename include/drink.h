#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>

using namespace std;

class Drink {
protected:
    string name;
    double price;

public:
    Drink(string name = "Unknown", double price = 0.0);
    void set_price(double new_price);
    void set_name(const string& new_name);
    string get_name() const;
    double get_price() const;
    void display_info() const;
};

Drink::Drink(string name, double price)
    : name(name), price(price) {}

void Drink::set_price(double new_price) {
    if (new_price >= 0) {
        price = new_price;
    } else {
        cout << "Invalid price. Price must be non-negative.\n";
    }
}

void Drink::set_name(const string& new_name) {
    if (!new_name.empty()) {
        name = new_name;
    } else {
        cout << "Invalid name. Name cannot be empty.\n";
    }
}

string Drink::get_name() const {
    return name;
}

double Drink::get_price() const {
    return price;
}

void Drink::display_info() const {
    cout << "Drink Name: " << name << endl;
    cout << "Price: " << price << " VND" << endl;
}

#endif
