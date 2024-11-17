#include "../include/employee_manage.h"
void display_menu() {
    cout << "\nEmployee Management System" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Remove Employee by Name" << endl;
    cout << "3. Remove Employee by Phone" << endl;
    cout << "4. Find Employee by Phone" << endl;
    cout << "5. Update Employee" << endl;
    cout << "6. Display All Employees" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    EmployeeManager manager;
    int choice;
    string name, phone;
    double pay_rate;
    int work_sessions;

    while (true) {
        display_menu();
        cin >> choice;
        switch (choice) {
            case 1: {
                cin.ignore();
                cout << "Enter employee name: ";
                getline(cin, name); // Read full line including spaces

                cout << "Enter employee phone: ";
                cin >> phone;

                cout << "Enter pay rate: ";
                cin >> pay_rate;

                cout << "Enter work sessions: ";
                cin >> work_sessions;

                Employee emp(phone, name, pay_rate, work_sessions);
                manager.add_employee(emp);
                break;
            }
            case 2: {
                cout << "Enter employee name to remove: ";
                cin >> name;
                manager.remove_employee_by_name(name);
                break;
            }
            case 3: {
                cout << "Enter employee phone to remove: ";
                cin >> phone;
                manager.remove_employee_by_phone(phone);
                break;
            }
            case 4: {
                cout << "Enter employee phone to find: ";
                cin >> phone;
                manager.find_employee_by_phone(phone);
                break;
            }
            case 5: {
                cout << "Enter employee phone, new name, new pay rate, and new work sessions: ";
                cin >> phone >> name >> pay_rate >> work_sessions;
                manager.update_employee(phone, name, pay_rate, work_sessions);
                break;
            }
            case 6: {
                manager.display_all_employees();
                break;
            }
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
