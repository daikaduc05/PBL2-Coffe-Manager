#ifndef SHIFT_H
#define SHIFT_H
#include <iostream>
#include "employee.h"
using namespace std;

class Shift : public Employee
{
protected:
    /* data */
    string date;
    int start;
    int end;
    long long sales; // tổng doanh thu
    Employee *employList;
    int numberEmploy;

public:
    Shift(string phone, string date, int start, int end, long long sales, string *employList, int numberEmploy);
    ~Shift();
    void AddEmployee(const Employee &employee);
    void DeleteEmployee(string phone);
    void FindEmployee(string phone);
    void setSales(int sale);
    void Display();
};

Shift::Shift(string phone, string date, int start, int end, long long sales, string *employList, int numberEmploy) : Employee(phone)
{
    this->date = date;
    this->start = start;
    this->end = end;
    this->sales = sales;
    this->employList = new Employee[numberEmploy];
    for (int i = 0; i < numberEmploy; i++)
    {
        this->employList[i] = employList[i];
    }
}

Shift::~Shift()
{
    delete[] employList;
}

void Shift::AddEmployee(const Employee &employee)
{
    for (int i = 0; i < numberEmploy; i++)
    {
        if (employList[i].getPhone().empty())
        {
            employList[i] = employee;
            return;
        }
    }
    cout << "can not add any employ for this shift" << endl;
}

void Shift::DeleteEmployee(string phone)
{
    for (int i = 0; i < numberEmploy; i++)
    {
        if (!employList[i].getPhone().empty() && this->phone == phone)
        {
            employList[i].Delete();
            cout << "Just delete employ with number: " << phone << endl;
            return;
        }
        else{
            cout<<"Employ with number: " <<phone<<" does not exist\n";
        }
    }
}

void Shift::FindEmployee(string phone){
    for(int i=0;i<numberEmploy;i++){
        if(!employList[i].getPhone().empty() && this->phone==phone){
            cout << "Employ with number: " << phone <<" exist"<< endl;
            return;
        }
         else{
            cout<<"Employ with number: " <<phone<<" does not exist\n";
        }
    }
}
void Shift::setSales(int sale){
    this->sales += sale;
}
void Shift::Display(){
    cout<<"Date of shift: "<<this->date<<endl;
    cout<<"Start of shift: " <<this->start<<endl;
    cout<<"Start of end: "<<this->end<<endl;
    cout<<"Sales of shift: "<<this->sales<<endl;
    cout<<"Number of employ: "<<this->numberEmploy<<endl;
    cout<<"List employs of this shift: "; 
      for (int i = 0; i < numberEmploy; i++) {
        if (!employList[i].getPhone().empty()) { 
            employList[i].display_infor();
            if (i < numberEmploy - 1) {
                cout << ", "; 
            }
        }
    }}

#endif
