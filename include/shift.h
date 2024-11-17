#ifndef SHIFT_H
#define SHIFT_H
#include <regex>
#include <iostream>
#include "employee.h"
#include "linked_list.h"
#include<fstream>
using namespace std;

class Shift : public Employee {
protected:
    string date;
    string shift_time; 
    long long sales; 
    LinkedList<Employee> employeeList; 
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool validate_date(const string& date) {
        regex date_pattern("^\\d{2}/\\d{2}/\\d{4}$");
        if (!regex_match(date, date_pattern)) {
            return false;
        }

        stringstream ss(date);
        string day_str, month_str, year_str;
        getline(ss, day_str, '/');
        getline(ss, month_str, '/');
        getline(ss, year_str, '/');

        int day = stoi(day_str);
        int month = stoi(month_str);
        int year = stoi(year_str);

        if (year < 2000) {
            return false;
        }

        if (month < 1 || month > 12) {
            return false;
        }

        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year)) {
            days_in_month[1] = 29;
        }

        if (day < 1 || day > days_in_month[month - 1]) {
            return false;
        }

        return true;
    }
public:
    Shift(string phone, string date, string shift_time, long long sales);
    Shift(const string& excelFilePath, const string& date, const string& shift_time, long long sales);
    ~Shift();
    void AddEmployee(const Employee& employee);
    void DeleteEmployee(const string& phone);
    void FindEmployee(const string& phone);
    void setSales(int sale);
    void Display();
};

Shift::Shift(string phone, string date, string shift_time, long long sales) 
    : Employee(phone), date(date), shift_time(shift_time), sales(sales) {
    if (!validate_date(date)) {
        throw invalid_argument("Invalid date format. Date must be in dd/mm/yyyy format and valid.");
    }

    if (shift_time != "Morning" && shift_time != "Afternoon" && shift_time != "Evening") {
        throw invalid_argument("Invalid shift time. Must be 'Morning', 'Afternoon', or 'Evening'.");
    }
}

Shift::Shift(const string& csvFilePath, const string& date, const string& shift_time, long long sales)
    : date(date), shift_time(shift_time), sales(sales) {
    // Kiểm tra ngày hợp lệ
    if (!validate_date(date)) {
        throw invalid_argument("Invalid date format. Date must be in dd/mm/yyyy format and valid.");
    }

    // Kiểm tra thời gian ca làm hợp lệ
    if (shift_time != "Morning" && shift_time != "Afternoon" && shift_time != "Evening") {
        throw invalid_argument("Invalid shift time. Must be 'Morning', 'Afternoon', or 'Evening'.");
    }

    try {
        ifstream file(csvFilePath);
        if (!file.is_open()) {
            throw runtime_error("Could not open CSV file.");
        }

        string line;
        bool isHeader = true;

        while (getline(file, line)) {
            if (isHeader) {
                isHeader = false;
                continue;
            }

            stringstream ss(line);
            string phone, name;
            string pay_rate_str, work_sessions_str;
            double pay_rate;
            int work_sessions;

           
            getline(ss, phone, ',');            
            getline(ss, name, ',');             
            getline(ss, pay_rate_str, ',');     
            getline(ss, work_sessions_str, ',');

            
            pay_rate = stod(pay_rate_str);
            work_sessions = stoi(work_sessions_str);

            // Tạo đối tượng Employee và thêm vào danh sách
            Employee employee(phone, name, pay_rate, work_sessions);
            employeeList.addBack(employee);
        }

        file.close();
        cout << "Employees imported successfully from " << csvFilePath << ".\n";
    } catch (const exception& e) {
        cerr << "Error reading CSV file: " << e.what() << endl;
    }
}

Shift::~Shift() {
    employeeList.clear();
}

void Shift::AddEmployee(const Employee& employee) {
    employeeList.addBack(employee);
    cout << "Employee added successfully.\n";
}

void Shift::DeleteEmployee(const string& phone) {
    if (employeeList.isEmpty()) {
        cout << "No employees in the list.\n";
        return;
    }

    auto* current = employeeList.getHead();
    decltype(current) previous = nullptr;

    while (current) {
        if (current->data.get_phone() == phone) {
            if (previous) {
                previous->next = current->next;
            } else {
                employeeList.setHead(current->next);
            }

            delete current;
            employeeList.decrementSize();
            cout << "Employee with phone number: " << phone << " has been removed.\n";
            return;
        }
        previous = current;
        current = current->next;
    }

    cout << "Employee with phone number: " << phone << " not found.\n";
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

void Shift::setSales(int sale) {
    if (sale < 0) {
        cout << "Invalid sale amount. Sale cannot be negative.\n";
        return;
    }
    this->sales += sale;
    cout << "Sales updated successfully.\n";
}

void Shift::Display() {
    cout << "Date of shift: " << this->date << endl;
    cout << "Shift time: " << this->shift_time << endl;
    cout << "Sales of shift: " << this->sales << endl;
    cout << "Number of employees: " << employeeList.getSize() << endl;

    if (employeeList.isEmpty()) {
        cout << "No employees in this shift.\n";
        return;
    }

    cout << "List of employees in this shift:\n";

    auto* current = employeeList.getHead();
    while (current) {
        current->data.display_info();
        current = current->next;
    }
}

#endif
