#ifndef SALARY_H
#define SALARY_H

#include <string>
#include <iostream>
#include "employee.h"

class Salary {
private:
    Employee TheEmployee; // Attribute to store the employee object
    int Month;            // Attribute to store the month
    double TotalSalary;   // Attribute to store the total salary

public:
    // Default Constructor
    Salary() : Month(0), TotalSalary(0.0) {
        // Initialize TheEmployee with default values if needed
    }

    // Parameterized Constructor
    Salary(const Employee& employee, int month, double totalSalary) 
        : TheEmployee(employee), Month(month), TotalSalary(totalSalary) {
    }

    // Setters
    void SetTotalSalary() {
        TotalSalary = TheEmployee.Salary_count();
    }

    void SetMonth(int month) {
        Month = month;
    }

    // Display methods
    void DisplayMonth() const {
        std::cout << "Month: " << Month << std::endl;
    }

    void DisplayTotalSalary() const {
        std::cout << "Total Salary: " << TotalSalary << std::endl;
    }
};

#endif // SALARY_H