#include "../include/employee_manage.h"
// #include "../include/menu.h"
#include "../include/bill.h"
#include "../include/customer.h"
#include "../include/employee.h"
#include "../include/drink.h"
#include "../include/customer_manager.h"
#include "../include/validate.h"
#include "../include/shift.h"
#include "../include/menu.h"
#include <iostream>
using namespace std;

void display_menu()
{
    cout << "\n=====================================" << endl;
    cout << "       PROJECT Management System    " << endl;
    cout << "=====================================" << endl;
    cout << "MENU OPTIONS" << endl;
    cout << "1. Open Employee menu" << endl;
    cout << "2. Open Drink menu" << endl;
    cout << "3. Open Shift & Bill menu" << endl;
    cout << "4. Open Customer menu" << endl;
    cout << "5. Open Shift menu" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void display_menu_drink()
{
    cout << "\n=====================================" << endl;
    cout << "       MENU    " << endl;
    cout << "=====================================" << endl;
    cout << "1. Add Drink" << endl;
    cout << "2. Remove Drink" << endl;
    cout << "3. Display All Drinks" << endl;
    cout << "4. Exit to Main Menu" << endl;
    cout << "Enter your choice: ";
}

void display_menu_bill()
{
    cout << "\n=====================================" << endl;
    cout << "       BILL    " << endl;
    cout << "=====================================" << endl;
    cout << "1. Add Bill" << endl;
    cout << "2. Remove Bill by customer phone" << endl;
    cout << "3. Display All Bills" << endl;
    cout << "4. End shift and exit to menu" << endl;
    cout << "Enter your choice: ";
}

void display_menu_employee()
{
    cout << "\n=====================================" << endl;
    cout << "       EMPLOYEE    " << endl;
    cout << "=====================================" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Remove Employee" << endl;
    cout << "3. Find Employee" << endl;
    cout << "4. Update Employee" << endl;
    cout << "5. Display All Employees" << endl;
    cout << "6. Exit to Main Menu" << endl;
    cout << "Enter your choice: ";
}

void display_menu_customer()
{
    cout << "\n=====================================" << endl;
    cout << "       CUSTOMER    " << endl;
    cout << "=====================================" << endl;
    cout << "1. Remove Customer" << endl;
    cout << "2. Find Customer" << endl;
    cout << "3. Update Customer" << endl;
    cout << "4. Display All Customers" << endl;
    cout << "5. Exit to Main Menu" << endl;
    cout << "Enter your choice: ";
}
void display_shift_menu()
{
    cout << "\n=====================================" << endl;
    cout << "       SHIFT    " << endl;
    cout << "=====================================" << endl;
    cout << "1. Remove Shift" << endl;
    cout << "2. Display shift by date and time" << endl;
    cout << "3. Display all shift by date" << endl;
    cout << "3. Exit to Main Menu" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    EmployeeManager employee_manager;
    Menu menu;
    CustomerManager customer_manager;
    // option for main menu
    int choice;
    billList bill_list;
    shiftList shift_list;
    // employee attributes
    Validate validate;

    while (true)
    {
        display_menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            bool exit_employee_menu = false;
            while (!exit_employee_menu)
            {
                display_menu_employee();
                cin >> choice;
                string phone, name;
                double pay_rate;
                int work_sessions;
                switch (choice)
                {
                case 1:
                {
                    cout << "Enter employee phone (Enter exactly 10 digits): ";
                    cin >> phone;

                    cin.ignore();
                    cout << "\nEnter employee name: ";
                    getline(cin, name);

                    cout << "Enter pay rate: ";
                    cin >> pay_rate;

                    cout << "Enter work sessions: ";
                    cin >> work_sessions;

                    Employee emp(phone, name, pay_rate, work_sessions);
                    employee_manager.add_employee(emp);
                    break;
                }
                case 2:
                {
                    cout << "\nEnter employee phone to remove: ";
                    cin.ignore();
                    getline(cin, name);
                    employee_manager.remove_employee_by_phone(name);
                    break;
                }
                case 3:
                {
                    cout << "\nEnter employee phone to find (Enter exactly 10 digits): ";
                    cin >> phone;
                    employee_manager.find_employee_by_phone(phone);
                    break;
                }
                case 4:
                {
                    cout << "\nEnter employee phone to update (Enter exactly 10 digits): ";
                    cin >> phone;
                    cout << "\nEnter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "\nEnter new pay rate: ";
                    cin >> pay_rate;
                    cout << "\nEnter new work sessions: ";
                    cin >> work_sessions;
                    employee_manager.update_employee(phone, name, pay_rate, work_sessions);
                    break;
                }
                case 5:
                {
                    cout << "\nEmployees: " << endl;
                    employee_manager.display_all_employees();
                    break;
                }
                case 6:
                {
                    exit_employee_menu = true;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again.\n";
                }
                }
            }
            break;
        }
        case 2:
        {
            bool exit_drink_menu = false;
            while (!exit_drink_menu)
            {
                display_menu_drink();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    cout << "Enter drink name: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter drink price: ";
                    double price;
                    cin >> price;
                    Drink drink(name, price);
                    menu.add_drink_to_menu(drink);
                    break;
                }
                case 2:
                {
                    cout << "\nEnter drink name to remove: ";
                    cin.ignore();
                    string drink_name;
                    getline(cin, drink_name);
                    menu.remove_drink_by_name(drink_name);
                    break;
                }
                case 3:
                {
                    menu.display_all_drinks();
                    break;
                }
                case 4:
                {
                    exit_drink_menu = true;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again.\n";
                }
                }
            }
            break;
        }
        case 3:
        {
            string date, employee_phone, customer_phone, shift_time;
            cout << "Enter date(day/month/year): ";
            cin >> date;
            if (!validate.validateDate(date))
            {
                cout << "Date is valid, please create shift again!" << endl;
                break;
            }
            cout << "Enter shift (Morning || Afternoon || Evening): ";
            cin >> shift_time;
            if (!validate.validateShiftTime(shift_time))
            {
                cout << "Time is valid, please create shift again!" << endl;
                break;
            }
            if (shift_list.checkShift(date, shift_time))
            {
                cout << "Shift already exists" << endl;
                cout << "=====================================" << endl;
                continue;
            }
            Shift shift(date, shift_time);
            while (true)
            {
                cout << "Enter employee phone: ";
                cin >> employee_phone;
                shift.AddEmployee(employee_manager.get_employee_by_phone(employee_phone));
                cout << "Add more employees? (Y/N): ";
                char choice;
                cin >> choice;
                if (choice == 'N' || choice == 'n')
                {
                    break;
                }
            }
            cout << "Shift created successfully." << endl;
            bool exit_bill_menu = false;
            while (!exit_bill_menu)
            {
                display_menu_bill();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    cout << "Enter bill information: " << endl;
                    string date = shift.getShiftDate();
                    cout << "Enter employee phone: ";
                    cin >> employee_phone;
                    if (!shift.checkEmployee(employee_phone))
                    {
                        cout << "Employee with phone \"" << employee_phone << "\" not found.\n";
                        cout << "please enter again: ";
                        continue;
                    }
                    cout << "Enter customer phone: ";
                    cin >> customer_phone;
                    if (!customer_manager.check_customer(customer_phone))
                    {
                        cout << "Customer with phone \"" << customer_phone << "\" not found.\n";
                        cout << "Create new customer with phone \"" << customer_phone << "\"? (Y/N): ";
                        char choice;
                        cin >> choice;
                        if (choice == 'Y' || choice == 'y')
                        {
                            cout << "Enter customer name: ";
                            string name;
                            cin.ignore();
                            getline(cin, name);
                            Customer cus(customer_phone, name);
                            customer_manager.add_customer(cus);
                        }
                        else
                        {
                            break;
                        }
                    }
                    Bill bill(date, employee_phone, customer_phone);
                    while (true)
                    {
                        string drink_name;
                        menu.display_all_drinks();
                        cout << "Enter drink name: ";
                        cin.ignore();
                        getline(cin, drink_name);
                        cout << "drink just added: " << drink_name << endl;
                        if (!menu.check_drink(drink_name))
                        {
                            cout << "Drink with name \"" << drink_name << "\" not found.\n";
                            cout << "Please enter again: ";
                            continue;
                        }
                        cout << "Enter number of drink: ";
                        int num;
                        cin >> num;
                        bill.add_drink(menu.get_drink_by_name(drink_name), num);
                        shift.addDrink(menu.get_drink_by_name(drink_name), num);
                        cout << "Add more drinks? (Y/N): ";
                        char choice;
                        cin >> choice;
                        if (choice == 'N' || choice == 'n')
                        {
                            break;
                        }
                    }

                    Customer customer = customer_manager.find_customer_by_phone(customer_phone);
                    bill.calculating_bill(customer);
                    bill_list.add_bill(bill);
                    shift.addBill(bill);
                    bill.show_bill();
                    // shift_list.addShift(shift);
                    break;
                }
                case 2:
                {
                    cout << "Enter customer phone";
                    string phone;
                    cin >> phone;
                    Bill bill = shift.findBillByCustomerPhone(phone);
                    shift.removeBill(bill);
                    cout << "Bill with customer phone" << phone << "removed successfully.\n";
                    cout << "=====================================" << endl;
                    cout << "Your bill list now: " << endl;
                    shift.Display();
                    break;
                }
                case 3:
                {
                    cout << "\nMenu: " << endl;
                    shift.Display();
                    break;
                }
                case 4:
                {
                    shift_list.addShift(shift);
                    cout << "End shift successfully." << endl;
                    exit_bill_menu = true;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again.\n";
                }
                }
            }
            break;
        }
        case 4:
        {
            bool exit_customer_menu = false;
            while (!exit_customer_menu)
            {
                display_menu_customer();
                cin >> choice;
                string phone, name;
                switch (choice)
                {
                case 1:
                {
                    cout << "\nEnter customer name to remove: ";
                    cin.ignore();
                    getline(cin, name);
                    customer_manager.remove_customer_by_name(name);
                    break;
                }
                case 2:
                {
                    cout << "\nEnter customer phone to find (Enter exactly 10 digits): ";
                    cin >> phone;
                    customer_manager.find_customer_by_phone(phone);
                    break;
                }
                case 3:
                {
                    customer_manager.display_all_customers();
                    break;
                }
                case 4:
                {
                    exit_customer_menu = true;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again.\n";
                }
                }
            }
            break;
        }
        case 5:
        {
            bool exit_shift_menu = false;
            while (!exit_shift_menu)
            {
                display_shift_menu();
                cin >> choice;
                string date, shift_time;
                switch (choice)
                {
                case 1:
                {
                    cout << "Enter date(day/month/year): ";
                    cin >> date;
                    if (!validate.validateDate(date))
                    {
                        cout << "Date is valid, please create shift again!" << endl;
                        break;
                    }
                    cout << "Enter shift (Morning || Afternoon || Evening): ";
                    cin >> shift_time;
                    if (!validate.validateShiftTime(shift_time))
                    {
                        cout << "Time is valid, please create shift again!" << endl;
                        break;
                    }
                    Shift shift = shift_list.findShift(date, shift_time);
                    shift_list.removeShift(shift);
                    break;
                }
                case 2:
                {
                    cout << "Enter date(day/month/year): ";
                    cin >> date;
                    if (!validate.validateDate(date))
                    {
                        cout << "Date is valid, please create shift again!" << endl;
                        break;
                    }
                    cout << "Enter shift (Morning || Afternoon || Evening): ";
                    cin >> shift_time;
                    if (!validate.validateShiftTime(shift_time))
                    {
                        cout << "Time is valid, please create shift again!" << endl;
                        break;
                    }
                    shift_list.displayShiftByDateandTime(date, shift_time);
                    break;
                }
                case 3:
                {
                    exit_shift_menu = true;
                    break;
                }
                }
            }
        }
        case 6:
        {
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again.\n";
        }
        }
    }

    return 0;
}