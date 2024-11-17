#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include <iostream>
#include <string>
using namespace std;
class Customer : public Person {
protected:
    int loyalty_points;      
    double discount_amount;  

public:
    Customer(string phone = "000000000", string name = "null", int loyalty_points = 0)
        : Person(phone, name), loyalty_points(loyalty_points), discount_amount(0.0) {}

    ~Customer() {}

    void add_loyalty_points(int points) {
        loyalty_points += points;
    }

    double calculate_discount() {
        discount_amount = loyalty_points * 0.1; 
        return discount_amount;
    }

    void display_info() const {
        display_name();
        display_phone();
        cout << "Loyalty Points: " << loyalty_points << endl;
        cout << "Discount Amount: " << discount_amount << endl;
    }
};

#endif
