#ifndef MENU_H
#define MENU_H
#include "drink.h"
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

class Menu 
{
protected:
    LinkedList<Drink> drink_list_menu;

public:
    Menu();
    ~Menu();
    void add_drink_to_menu(const Drink &drink);
    void add_drink_from_csv(const string& file_path);
    void remove_drink_by_name(const string &name);
    void display_all_drinks();
    void display_drink_by_name();
    Drink get_drink_by_name(const string &name);
    bool check_drink(const string &name) const;
};

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::add_drink_from_csv(const string& file_path) {
    ifstream file(file_path);

    if (!file.is_open()) {
        cout << "Error: Could not open file " << file_path << endl;
        return;
    }

    string line;
    int line_number = 0;

    while (getline(file, line)) {
        ++line_number;
        string name;
        double price;
        stringstream ss(line);
        try {
            if (getline(ss, name, ',') && ss >> price) {
                if (name.empty() || price < 0) {
                    throw invalid_argument("Invalid data values.");
                }

                Drink new_drink(name, price);
                add_drink_to_menu(new_drink);
            } else {
                throw invalid_argument("Invalid CSV format.");
            }
        } catch (const exception& e) {
            cout << "Warning: Line " << line_number << " is invalid: " << e.what() << endl;
            cout << "Skipped line: " << line << endl;
        }
    }

    file.close();
}

void Menu::add_drink_to_menu(const Drink &drink)
{
    drink_list_menu.addBack(drink);
    cout << drink.get_name() <<" added successfully.\n";
}

void Menu::remove_drink_by_name(const string &name)
{
    if (drink_list_menu.isEmpty())
    {
        cout << "The drink list is empty.\n";
        return;
    }
    auto *current = drink_list_menu.getHead();
    decltype(current) previous = nullptr;

    while (current)
    {
        if (current->data.get_name() == name)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                drink_list_menu.setHead(current->next);
            }
            delete current;
            drink_list_menu.decrementSize();
            cout << name <<" removed successfully.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Drink with name \"" << name << "\" not found.\n";
}

void Menu::display_all_drinks()
{
    if (drink_list_menu.isEmpty())
    {
        cout << "No drinks in the list.\n";
        return;
    }
    cout << "Menu: " << endl;
    auto *current = drink_list_menu.getHead();
    while (current)
    {
        cout << "Name: " << current->data.get_name() << ", Price: " << current->data.get_price() << endl;
        current = current->next;
    }
}

void Menu::display_drink_by_name()
{
    string name;
    cout << "Enter drink name to display: ";
    cin.ignore();
    getline(cin, name);
    auto *current = drink_list_menu.getHead();
    while (current)
    {
        if (current->data.get_name() == name)
        {
            cout << "Name: " << current->data.get_name() << ", Price: " << current->data.get_price() << endl;
            return;
        }
        current = current->next;
    }
    cout << "Drink with name \"" << name << "\" not found.\n";
}

Drink Menu::get_drink_by_name(const string &name)
{
    auto *current = drink_list_menu.getHead();
    while (current)
    {
        if (current->data.get_name() == name)
        {
            return current->data;
        }
        current = current->next;
    }
    return Drink();
}
bool Menu::check_drink(const string &name) const
{
    auto *current = drink_list_menu.getHead();
    while (current)
    {
        if (current->data.get_name() == name)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
#endif