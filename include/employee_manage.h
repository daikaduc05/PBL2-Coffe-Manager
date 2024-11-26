#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employee.h"
#include "linked_list.h"
#include <fstream>
#include <sstream>
using namespace std;

class EmployeeManager
{
private:
    LinkedList<Employee> employees;

public:
    bool check_employee(const string &phone) const;
    void add_employee(const Employee &employee);
    void add_employee_from_csv(const string& file_path);
    void remove_employee_by_phone(const string &phone);
    void find_employee_by_phone(const string &phone) const;
    void update_employee(const string &phone, const string &new_name, double new_pay_rate, int new_work_sessions);
    void display_all_employees() const;
    Employee get_employee_by_phone(const string &phone);

};

void EmployeeManager::add_employee_from_csv(const std::string& file_path) {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string phone, name;
        double pay_rate;
        int work_sessions;

        // Parse CSV line into variables
        if (std::getline(ss, phone, ',') &&
            std::getline(ss, name, ',') &&
            ss >> pay_rate &&
            ss.ignore(1) && // Ignore the comma or space after pay_rate
            ss >> work_sessions) {
            
            // Create an Employee object and add to the list
            Employee new_employee(phone, name, pay_rate, work_sessions);
            add_employee(new_employee);
        } else {
            std::cerr << "Warning: Skipping invalid line: " << line << std::endl;
        }
    }

    file.close();
}
bool EmployeeManager::check_employee(const string &phone) const
{
    if (employees.isEmpty())
    {
        return false;
    }
    auto *current = employees.getHead();
    while (current)
    {
        if (current->data.get_phone() == phone)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

Employee EmployeeManager::get_employee_by_phone(const string &phone)
{
    if (employees.isEmpty())
    {
        cout << "The employee list is empty.\n";
        return Employee();
    }
    auto *current = employees.getHead();
    while (current)
    {
        if (current->data.get_phone() == phone)
        {
            return current->data;
        }
        current = current->next;
    }
    cout << "Employee with phone \"" << phone << "\" not found.\n";
    return Employee();
}

void EmployeeManager::add_employee(const Employee &employee)
{
    if (check_employee(employee.get_phone()))
    {
        cout << "Employee with phone \"" << employee.get_phone() << "\" already exists.\n";
        return;
    }
    employees.addBack(employee);
    cout << "Employee added successfully.\n";
}


void EmployeeManager::remove_employee_by_phone(const string &phone)
{
    if (employees.isEmpty())
    {
        cout << "The employee list is empty.\n";
        return;
    }
    auto *current = employees.getHead();
    decltype(current) previous = nullptr;

    while (current)
    {
        if (current->data.get_phone() == phone)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                employees.setHead(current->next);
            }
            delete current;
            employees.decrementSize();
            cout << "Employee with phone \"" << phone << "\" removed successfully.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Employee with phone \"" << phone << "\" not found.\n";
}

void EmployeeManager::find_employee_by_phone(const string &phone) const
{
    if (employees.isEmpty())
    {
        cout << "The employee list is empty.\n";
        return;
    }
    auto *current = employees.getHead();
    while (current)
    {
        if (current->data.get_phone() == phone)
        {
            cout << "Employee found:\n";
            current->data.display_info();
            return;
        }
        current = current->next;
    }
    cout << "Employee with phone \"" << phone << "\" not found.\n";
    return;
}

void EmployeeManager::update_employee(const string &phone, const string &new_name, double new_pay_rate, int new_work_sessions)
{
    if (employees.isEmpty())
    {
        cout << "The employee list is empty.\n";
        return;
    }
    auto *current = employees.getHead();
    while (current)
    {
        if (current->data.get_phone() == phone)
        {
            current->data.set_name(new_name);
            current->data = Employee(phone, new_name, new_pay_rate, new_work_sessions);
            cout << "Employee updated successfully.\n";
            return;
        }
        current = current->next;
    }
    cout << "Employee with phone \"" << phone << "\" not found.\n";
}

void EmployeeManager::display_all_employees() const
{
    if (employees.isEmpty())
    {
        cout << "No employees in the list.\n";
        return;
    }
    auto *current = employees.getHead();
    while (current)
    {
        current->data.display_info();
        cout << "-------------------\n";
        current = current->next;
    }
}

#endif