#ifndef SHIFT_H
#define SHIFT_H
#include <regex>
#include <iostream>
#include "employee.h"
#include "linked_list.h"
#include<fstream>
#include"validate.h"
#include"bill.h"
using namespace std;

Validate validate;

class Shift{
protected:
    string date;
    string shift_time; 
    double sales; 
    LinkedList<Employee> employeeList; 
    LinkedList<Bill> billList;
    LinkedList<Drink> drinkList;
    LinkedList<int> num_drink;
public:
    Shift(string date, string shift_time, double sales=0);
    ~Shift();
    bool AddEmployee(const Employee& employee);
    void DeleteEmployee(const Employee& employee);
    void FindEmployee(const string& phone);
    void addBill(const Bill& bill);
    void removeBill(const Bill& bill);
    void Display();
    void addDrink(const Drink& drink, int num);
    string getShiftDate() const;
    string getShiftTime() const;
    bool checkEmployee(const string& phone) const;
    Bill findBillByCustomerPhone(const string&phone);
};

Shift::Shift(string date, string shift_time, double sales) {
    this->date = date;
    this->shift_time = shift_time;
    this->sales = sales;
}

Shift::~Shift() {
    employeeList.clear();
}

Bill Shift::findBillByCustomerPhone(const string&phone){
    if (billList.isEmpty()) {
        cout << "No bills in the list.\n";
        return Bill("null", "null", "null");
    }

    auto* current = billList.getHead();
    while (current) {
        if (current->data.phoneCustomer == phone) {
            return current->data;
        }
        current = current->next;
    }

    cout << "Bill with customer phone: " << phone << " not found.\n";
    return Bill("null", "null", "null");
}

bool Shift::checkEmployee(const string& phone) const {
    if (employeeList.isEmpty()) {
        return false;
    }

    auto* current = employeeList.getHead();
    while (current) {
        if (current->data.get_phone() == phone) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool Shift::AddEmployee(const Employee& employee) {
    if(employee.get_name() != "null")
    {
        employeeList.addBack(employee);
        cout << "Employee added successfully.\n";
        return 1;
    }
    else{
        cout << "Employee add fail.\n";
        return 0;
    }
}

void Shift::DeleteEmployee(const Employee& employee) {
    if (employeeList.isEmpty()) {
        cout << "No employees in the list.\n";
        return;
    }

    auto* current = employeeList.getHead();
    decltype(current) previous = nullptr;

    while (current) {
        if (current->data.get_phone() == employee.get_phone()) {
            if (previous) {
                previous->next = current->next;
            } else {
                employeeList.setHead(current->next);
            }

            delete current;
            employeeList.decrementSize();
            cout << "Employee with phone number: " << employee.get_phone() <<"||"<<" Name: "<<employee.get_name()<< " has been removed.\n";
            return;
        }
        previous = current;
        current = current->next;
    }

    cout << "Employee with phone number: " << employee.get_phone() << " not found.\n";
}

void Shift::FindEmployee(const string& phone) {
    if (employeeList.isEmpty()) {
        cout << "No employees in the list.\n";
        return;
    }

    auto* current = employeeList.getHead();
    while (current) {
        if (current->data.get_phone() == phone) {
            cout << "Employee found:\n";
            current->data.display_info();
            return;
        }
        current = current->next;
    }

    cout << "Employee with phone number: " << phone << " not found.\n";
}

void Shift::addBill(const Bill& bill) {
    billList.addBack(bill);
    
    this->sales += bill.bill_amount;
    cout << "Bill added successfully.\n";
}
void Shift::addDrink(const Drink& drink, int num) {
    auto* current = drinkList.getHead();
    auto* current_num = num_drink.getHead();
    while(current){
        if(current->data.get_name()==drink.get_name()){
            current_num->data+=num;
            return;
        }
        current = current->next;
        current_num = current_num->next;
    }
    drinkList.addBack(drink);
    num_drink.addBack(num);
}

void Shift::removeBill(const Bill& bill) {
    if (billList.isEmpty()) {
        cout << "No bills in the list.\n";
        return;
    }

    auto* current = billList.getHead();
    decltype(current) previous = nullptr;

    while (current) {
        if (current->data.phoneCustomer == bill.phoneCustomer) {
            if (previous) {
                previous->next = current->next;
            } else {
                billList.setHead(current->next);
            }

            delete current;
            billList.decrementSize();
            cout << "Bill with ID: " << bill.phoneCustomer
             << " has been removed.\n";
             this->sales -= bill.bill_amount;
            return;
        }
        previous = current;
        current = current->next;
    }
}

string Shift::getShiftDate() const {
    return date;
}
string Shift::getShiftTime() const {
    return shift_time;
}

void Shift::Display() {
    cout << "=====================================\n";
    cout << "Date of shift: " << this->date << endl;
    cout << "Shift time: " << this->shift_time << endl;
    cout << "Number of employees: " << employeeList.getSize() << endl;

    if (employeeList.isEmpty()) {
        cout << "No employees in this shift.\n";
        return;
    }

    cout << "List of employees in this shift:\n";

    auto* current = employeeList.getHead();
    while (current) {
        cout<<"Name: "<<current->data.get_name()<<" ||";
        cout<<" Phone: "<<current->data.get_phone()<<" "<<endl;
        current = current->next;
    }
    auto* current_drink = drinkList.getHead();
    auto* current_num = num_drink.getHead();
    cout<<"List of drinks in this shift:\n";
    while(current_drink){
        cout<<"Name: "<<current_drink->data.get_name()<<" ||";
        cout<<" Number: "<<current_num->data<<endl;
        current_drink = current_drink->next;
        current_num = current_num->next;
    }
    cout<<"Shift amount:"<<sales<<endl;
}
class shiftList
{
private:
    /* data */
    LinkedList<Shift> shift_list;
public:
    shiftList(/* args */);
    ~shiftList();
    void addShift(const Shift& shift);
    void removeShift(const Shift& shift);
    Shift findShift(const string& date, const string& shift_time);
    bool checkShift(const string& date, const string& shift_time);
    void displayShiftList();
    void displayShiftByDateandTime(const string& date, const string& shift_time);
};

shiftList::shiftList(/* args */)
{
}

shiftList::~shiftList()
{
}

void shiftList::addShift(const Shift& shift)
{
    shift_list.addBack(shift);
}

void shiftList::removeShift(const Shift& shift){
    if (shift_list.isEmpty()) {
        cout << "No shifts in the list.\n";
        return;
    }

    auto* current = shift_list.getHead();
    decltype(current) previous = nullptr;

    while (current) {
        if (current->data.getShiftDate() == shift.getShiftDate() && current->data.getShiftTime() == shift.getShiftTime()) {
            if (previous) {
                previous->next = current->next;
            } else {
                shift_list.setHead(current->next);
            }

            delete current;
            shift_list.decrementSize();
            cout << "Shift with date: " << shift.getShiftDate() << " and shift time: "<<shift.getShiftTime()
             << " has been removed.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
}

Shift shiftList::findShift(const string& date, const string& shift_time){
    if (shift_list.isEmpty()) {
        cout << "No shifts in the list.\n";
        return Shift("null", "null");
    }

    auto* current = shift_list.getHead();
    while (current) {
        if (current->data.getShiftDate() == date && current->data.getShiftTime() == shift_time) {
            return current->data;
        }
        current = current->next;
    }

    cout << "Shift with date: " << date << " and shift time: "<<shift_time
     << " not found.\n";
    return Shift("null", "null");
}

bool shiftList::checkShift(const string& date, const string& shift_time){
    if (shift_list.isEmpty()) {
        cout << "No shifts in the list.\n";
        return false;
    }

    auto* current = shift_list.getHead();
    while (current) {
        if (current->data.getShiftDate() == date && current->data.getShiftTime() == shift_time) {
            return true;
        }
        current = current->next;
    }

    cout << "Shift with date: " << date << " and shift time: "<<shift_time
     << " not found.\n";
    return false;
}

void shiftList::displayShiftList(){
    if (shift_list.isEmpty()) {
        cout << "No shifts in the list.\n";
        return;
    }

    auto* current = shift_list.getHead();
    while (current) {
        current->data.Display();
        current = current->next;
    }
}

void shiftList::displayShiftByDateandTime(const string& date, const string& shift_time){
    if (shift_list.isEmpty()) {
        cout << "No shifts in the list.\n";
        return;
    }

    auto* current = shift_list.getHead();
    while (current) {
        if (current->data.getShiftDate() == date && current->data.getShiftTime() == shift_time) {
            current->data.Display();
            return;
        }
        current = current->next;
    }

    cout << "Shift with date: " << date << " and shift time: "<<shift_time
     << " not found.\n";
}

#endif
