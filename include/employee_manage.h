#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employee.h"
#include "linked_list.h"
using namespace std;

class EmployeeManager {
private:
    LinkedList<Employee> employees;

public:
    void add_employee(const Employee& employee) {
        employees.addBack(employee);
        cout << "Employee added successfully.\n";
    }

    void remove_employee_by_name(const string& name) {
        if (employees.isEmpty()) {
            cout << "The employee list is empty.\n";
            return;
        }
        auto* current = employees.getHead();
        decltype(current) previous = nullptr;

        while (current) {
            if (current->data.get_name() == name) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    employees.setHead(current->next);
                }

                delete current;
                employees.decrementSize();
                cout << "Employee removed successfully.\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Employee with name \"" << name << "\" not found.\n";
    }

    void remove_employee_by_phone(const string& phone) {
        if (employees.isEmpty()) {
            cout << "The employee list is empty.\n";
            return;
        }

        auto* current = employees.getHead();
        decltype(current) previous = nullptr;

        while (current) {
            if (current->data.get_phone() == phone) {
                if (previous) {
                    previous->next = current->next;
                } else {
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

    void find_employee_by_phone(const string& phone) const {
        if (employees.isEmpty()) {
            cout << "The employee list is empty.\n";
            return;
        }

        auto* current = employees.getHead();
        while (current) {
            if (current->data.get_phone() == phone) {
                cout << "Employee found:\n";
                current->data.display_info();
                return;
            }
            current = current->next;
        }

        cout << "Employee with phone \"" << phone << "\" not found.\n";
    }

    void update_employee(const string& phone, const string& new_name, double new_pay_rate, int new_work_sessions) {
        if (employees.isEmpty()) {
            cout << "The employee list is empty.\n";
            return;
        }

        auto* current = employees.getHead();
        while (current) {
            if (current->data.get_phone() == phone) {
                current->data.set_name(new_name);
                current->data = Employee(phone, new_name, new_pay_rate, new_work_sessions);
                cout << "Employee updated successfully.\n";
                return;
            }
            current = current->next;
        }

        cout << "Employee with phone \"" << phone << "\" not found.\n";
    }

    void display_all_employees() const {
        if (employees.isEmpty()) {
            cout << "No employees in the list.\n";
            return;
        }
        auto* current = employees.getHead();
        while (current) {
            current->data.display_info();
            cout << "-------------------\n";
            current = current->next;
        }
    }
};

#endif
