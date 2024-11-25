#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include "customer.h"
#include "linked_list.h"
using namespace std;

class CustomerManager {
private:
    LinkedList<Customer> customers;

public:
    bool check_customer(const string &phone) const;
    void add_customer(const Customer &customer);
    void remove_customer_by_name(const string &name);
    void remove_customer_by_phone(const string &phone);
    Customer find_customer_by_phone(const string &phone) const;
    void display_all_customers() const;
};

bool CustomerManager::check_customer(const string &phone) const {
    if (customers.isEmpty()) {
        return false;
    }
    auto *current = customers.getHead();
    while (current) {
        if (current->data.get_phone() == phone) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void CustomerManager::add_customer(const Customer &customer) {
    if (check_customer(customer.get_phone())) {
        cout << "Customer with phone \"" << customer.get_phone() << "\" already exists.\n";
        return;
    }
    customers.addBack(customer);
    cout << "Customer added successfully.\n";
}

void CustomerManager::remove_customer_by_name(const string &name) {
    if (customers.isEmpty()) {
        cout << "The customer list is empty.\n";
        return;
    }
    auto *current = customers.getHead();
    decltype(current) previous = nullptr;

    while (current) {
        if (current->data.get_name() == name) {
            if (previous) {
                previous->next = current->next;
            } else {
                customers.setHead(current->next);
            }
            delete current;
            customers.decrementSize();
            cout << "Customer removed successfully.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Customer with name \"" << name << "\" not found.\n";
}

void CustomerManager::remove_customer_by_phone(const string &phone) {
    if (customers.isEmpty()) {
        cout << "The customer list is empty.\n";
        return;
    }
    auto *current = customers.getHead();
    decltype(current) previous = nullptr;

    while (current) {
        if (current->data.get_phone() == phone) {
            if (previous) {
                previous->next = current->next;
            } else {
                customers.setHead(current->next);
            }
            delete current;
            customers.decrementSize();
            cout << "Customer with phone \"" << phone << "\" removed successfully.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Customer with phone \"" << phone << "\" not found.\n";
}

Customer CustomerManager::find_customer_by_phone(const string &phone) const {
    if (customers.isEmpty()) {
        cout << "The customer list is empty.\n";
        return Customer();
    }
    auto *current = customers.getHead();
    while (current) {
        if (current->data.get_phone() == phone) {
            return current->data;
        }
        current = current->next;
    }
    cout << "Customer with phone \"" << phone << "\" not found.\n";
    return Customer();
}


void CustomerManager::display_all_customers() const {
    if (customers.isEmpty()) {
        cout << "No customers in the list.\n";
        return;
    }
    auto *current = customers.getHead();
    while (current) {
        current->data.display_info();
        cout << "-------------------\n";
        current = current->next;
    }
}

#endif