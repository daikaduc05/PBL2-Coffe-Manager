#include "../include/employee_manage.h"
#include "../include/menu.h"
#include "../include/bill.h"
#include "../include/customer.h"
#include "../include/employee.h"
#include "../include/drink.h"
#include "../include/customer_manager.h"
int main(){
    Menu menu;
    menu.add_drink_to_menu(Drink("Coca", 10000));
    menu.add_drink_to_menu(Drink("Pepsi", 12000));
    menu.add_drink_to_menu(Drink("Fanta", 15000));
    menu.display_all_drinks();
    Bill bill("01/01/2000", "000000000", "000000000", 0);
    bill.add_drink(menu.get_drink_by_name("Coca"), 2);
    bill.add_drink(menu.get_drink_by_name("Pepsi"), 3);
    bill.calculating_bill();
    bill.show_bill();
}