#include "salariedemployee.h"
#include <iostream>
using namespace std;

SalariedEmployee::SalariedEmployee() : Employee(), salary(0) {}
SalariedEmployee::SalariedEmployee(string n, string s, double sal)
    : Employee(n, s, sal), salary(sal) {}

double SalariedEmployee::get_salary() const { return salary; }
void SalariedEmployee::set_salary(double new_salary) { salary = new_salary; }

void SalariedEmployee::print_details() const {
    cout << "Salaried Employee - Name: " << name
         << ", SSN: " << ssn
         << ", Weekly Salary: " << salary
         << ", Net Pay: " << net_pay << endl;
}

void SalariedEmployee::print_check() const {
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << name << endl;
    cout << "The sum of " << net_pay << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << ssn << endl;
    cout << "Salaried Employee. Regular Pay: " << salary << endl;
    cout << "_________________________________________________\n";
}

string SalariedEmployee::to_csv() const {
    return "SalariedEmployee," + name + "," + ssn + "," + to_string(salary);
}