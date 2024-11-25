#ifndef BILL_H
#define BILL_H
#include <iostream>
#include "linked_list.h"
#include "drink.h"
// #include "queue.h"
#include "employee.h"
#include "employee_manage.h"
#include "customer.h"
#include "validate.h"
#include "menu.h"
#include "customer_manager.h"
using namespace std;
class Bill
{
public:
    /* data */
    string date;
    string phoneEmployee;
    string phoneCustomer;
    LinkedList<Drink> drink_list;
    LinkedList<int> nums_of_drink;
    double bill_amount;

public:
    Bill(string date = "01/01/2000", string phoneEmployee = "000000000", string phoneCustomer = "000000000", double bill_amount = 0);
    ~Bill();
    void add_drink(const Drink &drink, int num);
    void delete_drink_by_name(const string &name);
    void update_num_drink_by_name(const string &name);
    void calculating_bill(Customer &customer);
    void show_bill();
};

Bill::Bill(string date, string phoneEmployee, string phoneCustomer, double bill_amount)
{
    this->date = date;
    this->phoneEmployee = phoneEmployee;
    this->phoneCustomer = phoneCustomer;
    this->bill_amount = 0;
}
Bill::~Bill()
{
}
void Bill::add_drink(const Drink &drink, int num)
{
    drink_list.addBack(drink);
    nums_of_drink.addBack(num);
}

void Bill::delete_drink_by_name(const string &name)
{
    if (drink_list.isEmpty())
    {
        cout << "The drink list is empty.\n";
        return;
    }
    auto *current = drink_list.getHead();
    auto *current_num = nums_of_drink.getHead();
    decltype(current) previous = nullptr;
    decltype(current_num) previous_num = nullptr;

    while (current)
    {
        if (current->data.get_name() == name)
        {
            if (previous)
            {
                previous->next = current->next;
                previous_num->next = current_num->next;
            }
            else
            {
                drink_list.setHead(current->next);
                nums_of_drink.setHead(current_num->next);
            }
            delete current;
            delete current_num;
            drink_list.decrementSize();
            nums_of_drink.decrementSize();
            return;
        }
        previous = current;
        previous_num = current_num;
        current = current->next;
        current_num = current_num->next;
    }
    cout << "Drink with name \"" << name << "\" not found.\n";
}

void Bill::update_num_drink_by_name(const string &name)
{
    if (drink_list.isEmpty())
    {
        cout << "The drink list is empty.\n";
        return;
    }
    auto *current = drink_list.getHead();
    auto *current_num = nums_of_drink.getHead();
    while (current)
    {
        if (current->data.get_name() == name)
        {
            cout << "=====================================" << endl;
            cout << "Enter new number of " << name << ": " ;
            int new_num;
            cin >> new_num;
            current_num->data = new_num;
            return;
        }
        current = current->next;
        current_num = current_num->next;
    }
    cout << "Drink with name \"" << name << "\" not found.\n";
}

void Bill::calculating_bill(Customer &customer)
{
    if (drink_list.isEmpty())
    {
        cout << "The drink list is empty.\n";
        return;
    }
    auto *current = drink_list.getHead();
    auto *current_num = nums_of_drink.getHead();
    while (current)
    {
        bill_amount += current->data.get_price() * current_num->data;
        current = current->next;
        current_num = current_num->next;
    }
    bill_amount -= bill_amount * customer.get_discount_amount();
}
void Bill::show_bill()
{
    cout << "=====================================" << endl;
    cout << "Bill Information:\n";
    cout << "Bill Date: " << date << endl;
    cout << "Employee Phone: " << phoneEmployee << endl;
    cout << "Customer Phone: " << phoneCustomer << endl;
    cout << "Your order: " << endl;
    auto *current = drink_list.getHead();
    auto *current_num = nums_of_drink.getHead();
    while (current)
    {
        cout << "Name: " << current->data.get_name() << ", Price: " << current->data.get_price() << ", Number: " << current_num->data << endl;
        current = current->next;
        current_num = current_num->next;
    }
    cout << "Bill Amount: " << bill_amount << endl;
    cout << "Thank you for your order!" << endl;
}

class billList
{
protected:
    LinkedList<Bill> bill_list;

public:
    void add_bill(const Bill &bill);
    void find_bill_by_costumer_phone(const string &phone);
    void remove_bill_by_costumer_phone(const string &phone);
    void display_all_bills();
    double get_billList_amount();
    void reset_billList(billList &bill_list);
};
void billList::add_bill(const Bill &bill)
{
    bill_list.addBack(bill);
}

void billList::find_bill_by_costumer_phone(const string &phone)
{
    if (bill_list.isEmpty())
    {
        cout << "The bill list is empty.\n";
        return;
    }
    auto *current_bill = bill_list.getHead();
    decltype(current_bill) previous_bill = nullptr;
    while (current_bill)
    {
        if (current_bill->data.phoneCustomer == phone)
        {
            current_bill->data.show_bill();
            return;
        }
        previous_bill = current_bill;
        current_bill = current_bill->next;
    }

    cout << "Bill with costumer phone \"" << phone << "\" not found.\n";
}

void billList::remove_bill_by_costumer_phone(const string &phone)
{
    if (bill_list.isEmpty())
    {
        cout << "The bill list is empty.\n";
        return;
    }
    auto *current_bill = bill_list.getHead();
    decltype(current_bill) previous_bill = nullptr;

    while (current_bill)
    {
        if (current_bill->data.phoneCustomer == phone)
        {
            if (previous_bill)
            {
                previous_bill->next = current_bill->next;
            }
            else
            {
                bill_list.setHead(current_bill->next);
            }
            delete current_bill;
            bill_list.decrementSize();
            cout << "Bill with costumer phone \"" << phone << "\" removed successfully.\n";
            return;
        }
        previous_bill = current_bill;
        current_bill = current_bill->next;
    }

    cout << "Bill with costumer phone \"" << phone << "\" not found.\n";
}

void billList::display_all_bills()
{
    if (bill_list.isEmpty())
    {
        cout << "The bill list is empty.\n";
        return;
    }
    auto *current = bill_list.getHead();
    while (current)
    {
        current->data.show_bill();
        current = current->next;
    }
}

double billList::get_billList_amount()
{
    double sum = 0;
    auto *current = bill_list.getHead();
    while (current)
    {
        sum += current->data.bill_amount;
        current = current->next;
    }
    return sum;
}

void billList::reset_billList(billList &bill_list)
{
    bill_list.bill_list.clear();
}

#endif