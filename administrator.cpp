#include "administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator(): title(""), department(""), supervisor("")
{
    salary = 0;
}

Administrator::Administrator(string n, string s, string t, string d, string sup, double sal)
{
    name = n;
    ssn = s;
    title = t;
    department = d;
    supervisor = sup;
    salary = sal;
}

void Administrator::set_supervisor(const string& name) {
    supervisor = name;
}

void Administrator::set_title(const string& t) {
    title = t;
}

void Administrator::set_department(const string& d) {
    department = d;
}

void Administrator::set_name(const string& n) {
    name = n;
}

void Administrator::set_ssn(const string& s) {
    ssn = s;
}

void Administrator::set_salary(double sal) {
    salary = sal;
}

istream* Administrator::readAdminData(istream& input) {
    cout << "Enter title, department, supervisor, name, ssn, salary: ";
    input >> title >> department >> supervisor >> name >> ssn >> salary;
    return &input;
}

void Administrator::print(ostream& output) const {
    output << "Title: " << title << endl;
    output << "Department: " << department << endl;
    output << "Supervisor: " << supervisor << endl;
    output << "Name: " << name << endl;
    output << "SSN: " << ssn << endl;
    output << "Salary: " << salary << endl;
}

void Administrator::print_check() const {
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << name << endl;
    cout << "The sum of " << salary << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << ssn << endl;
    cout << "Salaried Employee. Regular Pay: " << salary << endl;
    cout << "_________________________________________________\n";
}


void Administrator::print_details() const
{
    cout << "Administrator\n";
    cout << "Title: " << title << endl;
    cout << "Department: " << department << endl;
    cout << "Supervisor: " << supervisor << endl;
    cout << "Name: " << name << endl;
    cout << "SSN: " << ssn << endl;
    cout << "Net Pay: " << net_pay << endl;
    cout << "Salary: " << salary << endl;
}


string Administrator::to_csv() const
{
    
    return "Administrator," + name + "," + ssn + "," + to_string(salary)
           + "," + title + "," + department + "," + supervisor;
}