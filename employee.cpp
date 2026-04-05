#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee() : name("No name yet"), ssn("No number yet"), net_pay(0) {}

Employee::Employee(string the_name, string the_ssn, double the_net_pay)
    : name(the_name), ssn(the_ssn), net_pay(the_net_pay) {}

string Employee::get_name() const { return name; }
string Employee::get_ssn() const { return ssn; }
double Employee::get_net_pay() const { return net_pay; }

void Employee::set_name(string new_name) { name = new_name; }
void Employee::set_ssn(string new_ssn) { ssn = new_ssn; }
void Employee::set_net_pay(double new_net_pay) { net_pay = new_net_pay; }

void Employee::print_details() const {
    cout << "Employee - Name: " << name 
         << ", SSN: " << ssn 
         << ", Net Pay: " << net_pay << endl;
}

void Employee::print_check() const {
    cout << "\nERROR: print_check called for base Employee. Aborting.\n";
    exit(1);
}

string Employee::to_csv() const {
    return "Employee," + name + "," + ssn + "," + to_string(net_pay);
}