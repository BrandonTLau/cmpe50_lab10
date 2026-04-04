//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 -member variable string title
 	 -ex: director or vice president
 -member variable string department
 	 -ex: accounting, production
-member variable sring name of supervisor
-protected member
-double annual salary
-set_supervisor (changes supervisor name)
-read function (read admin data from keyboard)
-print function (pass output stream)
-overloading of member function print_check()

 */

#include <iostream>
#include <string>
#include "salariedemployee.h"
#include "employee.h"
using namespace std;

class Administrator : public SalariedEmployee
{
public:
	void set_supervisor(string name);
	istream* readAdminData(istream &input);
	void print(ostream &output);
	void print_check();
	void set_name(string n);
	void set_ssn(string s);
	void set_net_pay(double p);
	void set_salary(double sal);
	Administrator();
	Administrator(string n, string s, string t, string d, string sup, double np);
	//void print_check() override;
private:
	string title;
	string department;
	string supervisor;
protected:
	double annualSalary;
};

void Administrator::set_supervisor(string name)
{
	supervisor = name;
}

istream* Administrator::readAdminData(istream &input)
{
	cout << "Enter title, department, supervisor, name, ssn, net_pay: ";
	input >> title >> department >> supervisor >> name >> ssn >> net_pay;
	return &input;
}

void Administrator::print(ostream &output)
{
	output << "Title: " << title << endl;
	output << "Department: " << department << endl;
	output << "Supervisor: " << supervisor << endl;
	output << "Name: " << name << endl;
	output << "Ssn: " << ssn << endl;
	output << "Net pay: " << net_pay << endl;
}

void Administrator::set_name(string n)
{
	name = n;
}

void Administrator::set_ssn(string s)
{
	ssn = s;
}

void Administrator::set_net_pay(double p)
{
	net_pay = p;
}

void Administrator::set_salary(double sal)
{
	salary = sal;
}

void Administrator::print_check( )
{
	cout << "admin.print_check()" << endl;


set_net_pay(salary);

  cout << "\n__________________________________________________\n";
cout << "Pay to the order of " << get_name( ) << endl;

cout << "The sum of " << get_net_pay( ) << " Dollars\n";
cout << "_________________________________________________\n";
cout << "Check Stub NOT NEGOTIABLE \n";

cout << "Employee Number: " << get_ssn( ) << endl;
cout << "Salaried Employee. Regular Pay: "
<< salary << endl;
cout << "_________________________________________________\n";


}

Administrator::Administrator()
{

}

Administrator::Administrator(string n, string s, string t, string d, string sup, double np)
{
	name = n;
	ssn = s;
	title = t;
	department = d;
	supervisor = sup;
	net_pay = np;
}


int main()
{

	Administrator admin;
//test to read employee data
	cout << "Testing read and write function." << endl;
	admin.readAdminData(cin);
//test to print employee data
	admin.print(cout);
//test for set supervisor
	cout << "Changing supervisor to Bob.";
	admin.set_supervisor("Bob");
	admin.print(cout);

	Administrator admin1("george", "415", "admin", "accounting", "martin", 1000);
	//admin.print(cout);
	admin1.set_salary(100);
	admin1.print_check();


	return 0;
}
