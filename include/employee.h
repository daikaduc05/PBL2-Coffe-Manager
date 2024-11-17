#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"
#include <iostream>
#include <string>
using namespace std;

class Employee : public Person {
protected:
    double pay_rate;        
    int work_sessions;      

public:
    Employee(string phone = "000000000", string name = "null", double pay_rate = 0.0, int work_sessions = 0)
        : Person(phone, name), pay_rate(pay_rate), work_sessions(work_sessions) {}

    ~Employee() {}

    
    void display_info() const {
        display_name();
        display_phone();
        cout << "Pay Rate: " << pay_rate << endl;
        cout << "Work Sessions: " << work_sessions << endl;
    }
};

#endif
