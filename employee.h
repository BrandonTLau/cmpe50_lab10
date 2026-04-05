#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
    Employee();
    Employee(string the_name, string the_ssn, double the_net_pay = 0);

    string get_name() const;
    string get_ssn() const;
    double get_net_pay() const;

    void set_name(string new_name);
    void set_ssn(string new_ssn);
    void set_net_pay(double new_net_pay);

    
    virtual void print_details() const;
    virtual void print_check() const;
    virtual string to_csv() const;

protected:
    string name;
    string ssn;
    double net_pay;
};

#endif // EMPLOYEE_H_




