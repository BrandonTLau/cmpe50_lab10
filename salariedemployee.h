#ifndef SALARIEDEMPLOYEE_H_
#define SALARIEDEMPLOYEE_H_

#include "employee.h"
#include <string>
using namespace std;

class SalariedEmployee : public Employee {
public:
    SalariedEmployee();
    SalariedEmployee(string n, string s, double sal);

    double get_salary() const;
    void set_salary(double new_salary);

    void print_details() const override;
    void print_check() const override;
    string to_csv() const override;

protected:
    double salary; 
};

#endif // SALARIEDEMPLOYEE_H_
