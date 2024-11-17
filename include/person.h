#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string phone;
    string name;

public:
    Person(string phone = "000000000", string name = "null");
    ~Person();

    void display_name() const;   
    void display_phone() const;  

    string get_name() const;     // Lấy tên
    string get_phone() const;    // Lấy số điện thoại
    void set_name(const string& new_name);  // Đặt lại tên
    void set_phone(const string& new_phone); // Đặt lại số điện thoại
};

Person::Person(string phone, string name) : phone(phone), name(name) {}

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
    phone = new_phone;
}

#endif
