#ifndef BILL_H
#define BILL_H
#include <iostream>
#include "linked_list.h"
#include "drink.h"
#include "queue.h"
using namespace std;
class Bill
{
private:
    /* data */
    string date;
    string phoneEmployee;
    string phoneCustomer;
    double bill_amount;
    LinkedList<Drink> drink_list;
    LinkedList<int> nums_of_drink;
    
public:
    Bill(string date = "01/01/2000",string phoneEmployee = "000000000",string phoneCustomer = "000000000",double bill_amount = 0);   
    ~Bill();
    void add_drink();
    void delete_drink();
    void change_drink();
    void set_date();
    void set_phoneEmployee();
    double calculating_bill();
    void show_bill();
};

Bill::Bill(string date = "01/01/2000",string phoneEmployee = "000000000",string phoneCustomer = "000000000",double bill_amount = 0){
    this -> date = date;
    this -> phoneCustomer = phoneCustomer;
    this -> phoneEmployee = phoneEmployee;
    this -> bill_amount = bill_amount;
    
}
Bill::~Bill()
{
}
void Bill::add_drink()
{
    
}
class BillList
{
private:
    /* data */
    Queue<Bill> list;

public:
    BillList(/* args */);
    ~BillList();
    void add_bill(Bill bill);
    void find_bill();
    void pop_bill();
    void remove_bill_by_id(int id);
};

BillList::BillList(/* args */)
{
}

BillList::~BillList()
{
}
#endif
