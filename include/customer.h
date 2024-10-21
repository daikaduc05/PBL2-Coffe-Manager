#ifndef CUSTOMER_H  
#define CUSTOMER_H  
#include<person.h>
#include<iostream>
#include<string>
class Customer: public Person
{
protected:
    int LoyaltyPoints; // diem_tich_luy_cua_khach_hang
public:
    Customer(string phone = "000000000",string name = "null",int LoyaltyPoints = 0);
    ~Customer();
    void set_loyalty_points(int loyaltyPoints);
    void get_loyalty_points() const;
};  

<<<<<<< HEAD
Customer::Customer(string phone,string name ,int LoyaltyPoints ):Person(phone,name){}

Customer::Customer(const Person&Person, int LoyaltyPoints):Person(Person) {}
=======
Customer::Customer(string phone,string name ,int LoyaltyPoints ):Person(phone,name){
    this->LoyaltyPoints=LoyaltyPoints;
}
>>>>>>> 5723c9b63713e3f750d9bb3718dbcbc0b4c0a1b6

Customer::~Customer()
{
}

void Customer::set_loyalty_points(int loyaltyPoints){
    if(this->phone!="000000000"){
        this->LoyaltyPoints+=LoyaltyPoints;
    }
    else{
        cout<<"this customer with the number: "<<phone<<" do not exist\n";
    }
}

void Customer::get_loyalty_points() const{
    if(this->phone!="000000000"){
        cout<<"The loyalty point with the number: "<<this->phone<<" is: "<<this->LoyaltyPoints<<endl;
    }
    else{
        cout<<"this customer with the number: "<<this->phone<<" do not exist\n";
    }
}


#endif