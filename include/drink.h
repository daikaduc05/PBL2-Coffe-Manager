#ifndef DRINK_H  
#define DRINK_H  
#include<iostream>
#include<string>
using namespace std;
class Drink
{
private:
    /* data */
    string name_of_drink;
    double drink_cost;
public:
    Drink(string name_of_drink = "null",double drink_cost = 0);
    ~Drink();
    void show_name_of_drink(){
        cout << "Name of drink : " << name_of_drink << endl;
    }
    void show_drink_cost(){
        cout << "Cost of drink: " << drink_cost << endl;
    }
};

Drink::Drink(string name_of_drink = "null",double drink_cost = 0)
{
    this->name_of_drink = name_of_drink;
    this->drink_cost = drink_cost;
}

Drink::~Drink()
{
}


#endif