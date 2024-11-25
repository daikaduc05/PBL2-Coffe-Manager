#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "validate.h"
using namespace std;

class Person: public Validate {
protected:
    string phone;
    string name;

public:
    Person(string phone , string name);
    ~Person();
    void display_name() const;   
    void display_phone() const;  
    string get_name() const;     
    string get_phone() const;    
    void set_name(const string& new_name);  
    void set_phone(const string& new_phone);
};

Person::Person(string phone="0000000000", string name="null")  {
    this->phone = phone;
    this->name = name;
    if(phone=="000000000" && name=="null"){
        cout<<"Invalid input"<<endl;
        return;
    }
    if(!is_valid_phone(phone)){
        cout<<"Invalid phone number"<<endl;
        return;
    }
    
}

Person::~Person() {}

void Person::display_name() const {
    cout << "Name: " << name << endl;
}

void Person::display_phone() const {
    cout << "Phone: " << phone << endl;
}

string Person::get_name() const {
    return name;
}

string Person::get_phone() const {
    return phone;
}

void Person::set_name(const string& new_name) {
    name = new_name;
}

void Person::set_phone(const string& new_phone) {
    if(!is_valid_phone(new_phone)){
        cout<<"Invalid phone number"<<endl;
        exit(0);
    }
    phone = new_phone;
}

#endif
