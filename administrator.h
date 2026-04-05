#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_

#include <iostream>
#include <string>
#include "salariedemployee.h"
using namespace std;

class Administrator : public SalariedEmployee {
public:
    Administrator();
    Administrator(string n, string s, string t, string d, string sup, double sal);

    void set_supervisor(const string& name);
    void set_title(const string& t);
    void set_department(const string& d);
    void set_name(const string& n);
    void set_ssn(const string& s);
    void set_salary(double sal);

    string get_supervisor() const { return supervisor; }
    string get_title() const { return title; }
    string get_department() const { return department; }
    
    istream* readAdminData(istream& input);
    void print(ostream& output) const;
    void print_check() const;

    void print_details() const override; 
    string to_csv() const override;       


private:
    string title;
    string department;
    string supervisor;
};

#endif // ADMINISTRATOR_H_