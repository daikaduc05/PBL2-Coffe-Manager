#ifndef PAYROLL_H
#define PAYROLL_H

#include "employee.h"
#include <iostream>

using namespace std;

class Payroll {
private:
    Employee employee;
    int month;

public:
    Payroll(const Employee& emp, int month = 1) : employee(emp) {
        set_month(month);
    }

    void set_month(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            cout << "Invalid month. Setting default month to 1.\n";
            month = 1;
        }
    }

    double calculate_salary() const {
       
    }

    void display_payroll() const {
        cout << "Payroll for Employee: " << endl;
        employee.display_info();
        cout << "Month: " << month << endl;
        cout << "Calculated Salary: " << calculate_salary() << " VND" << endl;
    }
};

#endif
