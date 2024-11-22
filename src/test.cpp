#include "../include/employee_manage.h"
#include "../include/menu.h"
#include "../include/bill.h"
#include "../include/customer.h"
#include "../include/employee.h"
#include "../include/drink.h"
#include "../include/customer_manager.h"
#include "../include/validate.h"
#include "../include/shift.h"

int main()
{   
    shiftList shift_list;
    Drink drink1("Coca", 10);
    Menu menu;
    menu.add_drink_to_menu(drink1);
    Shift shift("01/01/2021", "Morning");
    Employee emp("1234567890", "John", 10, 10);
    shift.AddEmployee(emp);
    Bill bill("01/01/2021", "1234567890", "0987654321");
    bill.add_drink(drink1, 2);
    shift.addBill(bill);
    shift.addDrink(drink1, 2);
    shift_list.addShift(shift);
    shift_list.displayShiftByDateandTime("01/01/2021", "Morning");
}