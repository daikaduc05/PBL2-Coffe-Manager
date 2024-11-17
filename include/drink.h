#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>

using namespace std;

class Drink {
private:
    string name;
    double price;

public:
    Drink(string name = "Unknown", double price = 0.0)
        : name(name), price(price) {}

    void set_price(double new_price) {
        if (new_price >= 0) {
            price = new_price;
        } else {
            cout << "Invalid price. Price must be non-negative.\n";
        }
    }

    void display_info() const {
        cout << "Drink Name: " << name << endl;
        cout << "Price: " << price << " VND" << endl;
    }
};

#endif
