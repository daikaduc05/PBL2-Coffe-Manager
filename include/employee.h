#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <person.h>
#include <iostream>
#include <string>
class Employee : public Person
{
protected:
    /* data */
    int PayRate;
    double DrinkSevice;
    string EmployeeType;
    int TimeWork;

public:
    Employee(string phone = "000000000", string name = "null", int PayRate = 0, double DrinkSevice = 0, string EmployeeType = "null", int TimeWork);
    ~Employee();
    void display_infor();
    void set_Timework(int hour);
    void set_drinkservice(double drinkservice);
    void set_payrate();
    void Delete();
    double Salary_count();
    string Employee::getPhone() const
{
    return this->phone; 
}
};

Employee::Employee(string phone = "000000000", string name = "null", int PayRate = 0, double DrinkSevice = 0, string EmployeeType = "null", int TimeWork) : Person(phone, name)
{
    this->PayRate = PayRate;
    this->DrinkSevice = DrinkSevice;
    this->EmployeeType = EmployeeType;
    this->TimeWork = TimeWork;
}

Employee::~Employee()
{
}

double Employee::Salary_count()
{
    return this->PayRate * this->TimeWork + this->DrinkSevice / 100;
}

void Employee::display_infor()
{
    if (this)
    {
        Person::display_name();
        Person::display_phone();
        cout << "Employee job is: " << this->EmployeeType << endl;
        cout << "Employee payrate is: " << this->PayRate << endl;
        cout << "Employee salary is: " << Salary_count() << endl;
    }
}

void Employee::set_drinkservice(double drinkservice)
{
    this->DrinkSevice += drinkservice;
}

void Employee::set_payrate()
{
    if (this)
    {
        this->PayRate++;
    }
}

void Employee::set_Timework(int hour)
{
    if (this)
    {
        this->TimeWork += hour;
    }
}
void Employee::Delete()
{
    cout << "Deleting employee: " << this->name << endl;
}

#endif