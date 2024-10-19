#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;
class Person{
protected:
    /* data */
    string phone;
    string name;
public:
    Person(string phone = "000000000",string name = "null");
    ~Person();
    void set_phone(string new_phone);
    void set_name(string new_name);
    void display_name();
    void display_phone();
};

Person::Person(string phone,string name){
    this -> phone = phone;
    this -> name = name;   
}
Person::~Person(){
}
void Person::set_name(string new_name){
    this -> name = new_name;
}
void Person::set_phone(string new_phone){
    this -> phone = new_phone;
}
void Person::display_name(){
    cout << "Ten Khach Hang : " << this->name << '\n';
}
void Person::display_phone(){
    cout << "So Dien Thoai Khach Hang : " << this->phone << '\n';
}
#endif 
