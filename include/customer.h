#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include <iostream>
#include <string>
using namespace std;
class Customer : public Person
{
protected:
    int loyalty_points;
    double discount_amount;

public:
    Customer(string phone = "000000000", string name = "null", int loyalty_points = 0, double discount_amount = 0.0);
    ~Customer();
    double calculate_discount();
    void display_info() const;
    int get_loyalty_points() const;
    double get_discount_amount() const;
};

Customer::Customer(string phone, string name, int loyalty_points, double discount_amount)
    : Person(phone, name){
        this->loyalty_points = loyalty_points;
        this->discount_amount = discount_amount;
    }

Customer::~Customer() {}


double Customer::calculate_discount()
{
    if(loyalty_points >= 5)
    {
        discount_amount = 0.3;
        loyalty_points = 0;
    }
    else
    {
        discount_amount = 0;
        loyalty_points++;
    }
}

void Customer::display_info() const
{
    display_name();
    display_phone();
    cout << "Loyalty Points: " << loyalty_points << endl;
    cout << "Discount Amount: " << discount_amount << endl;
}

int Customer::get_loyalty_points() const
{
    return loyalty_points;
}

double Customer::get_discount_amount() const
{
    return discount_amount;
}

#endif
