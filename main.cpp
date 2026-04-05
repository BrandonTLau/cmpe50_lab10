#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "employee.h"
#include "salariedemployee.h"
#include "administrator.h"

using namespace std;

//store employees
vector<Employee*> employees;

//csv handling

// Load employees from CSV
void load_csv(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "CSV file not found, starting with empty data.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        // skip empty lines
        if (line.empty()) continue;

        stringstream ss(line);
        string type, name, ssn, sal_str;

        // read basic fields
        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, ssn, ',');
        getline(ss, sal_str, ',');

        if (sal_str.empty()) continue;

        double sal = 0;
        try {
            sal = stod(sal_str);
        } catch (...) {
            cout << "Invalid salary: " << sal_str << endl;
            continue; 
        }

        // create objects based on type
        if (type == "Administrator") {
            string title, dept, sup;
            getline(ss, title, ',');
            getline(ss, dept, ',');
            getline(ss, sup, ',');
            employees.push_back(new Administrator(name, ssn, title, dept, sup, sal));
        }
        else if (type == "SalariedEmployee") {
            employees.push_back(new SalariedEmployee(name, ssn, sal));
        }
        else if (type == "Employee") {
            employees.push_back(new Employee(name, ssn, sal));
        }
        else {
            cout << "Unknown employee type: " << type << endl;
        }
    }

    file.close();
}

void save_csv(const string& filename) {
    ofstream file(filename);

    for (int i = 0; i < employees.size(); i++) {
        file << employees[i]->to_csv() << endl;
    }
}

//crud functions

void add_employee() {
    int type;
    cout << "Enter type: 1-Employee, 2-Salaried, 3-Administrator: "; 
    cin >> type; 
    cin.ignore(); 

    string name, ssn, title, dept, sup; 
    double sal;
    cout << "Name: "; getline(cin, name);
    cout << "SSN: "; getline(cin, ssn);
    cout << "Salary: "; cin >> sal; cin.ignore();

    if (type == 3) {
        cout << "Title: "; getline(cin, title);
        cout << "Department: "; getline(cin, dept);
        cout << "Supervisor: "; getline(cin, sup);
        employees.push_back(new Administrator(name, ssn, title, dept, sup, sal));
    } else if (type == 2) {
        employees.push_back(new SalariedEmployee(name, ssn, sal));
    } else {
        employees.push_back(new Employee(name, ssn, sal));
    }

    save_csv("employees.csv");
    cout << "Employee added!\n";
}

void view_employees() {
    if (employees.empty()) {
        cout << "No employees found.\n";
        return;
    }
	for (int i = 0; i < employees.size(); i++) {
    	employees[i]->print_details();
	}
}

void delete_employee() {
    string ssn; 
    cout << "Enter SSN to delete: "; 
    cin >> ssn;

    for (int i = 0; i < employees.size(); i++) {
    	if (employees[i]->get_ssn() == ssn) {
        	delete employees[i];                
        	employees.erase(employees.begin() + i);  
        	save_csv("employees.csv");          
        	cout << "Employee deleted.\n";
        	return;
    	}
	}
    cout << "Employee not found.\n";
}

void update_employee() {
    string ssn;
    cout << "Enter the SSN of the employee to update: ";
    cin >> ssn;

    bool found = false;
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i]->get_ssn() == ssn) {
            found = true;

            cout << "Employee found. Enter new details (leave blank to keep current):\n";

            string new_name;
            cout << "New name: ";
            cin.ignore(); 
            getline(cin, new_name);
            if (!new_name.empty()) {
                employees[i]->set_name(new_name);
            }

            string new_ssn;
            cout << "New SSN: ";
            getline(cin, new_ssn);
            if (!new_ssn.empty()) {
                employees[i]->set_ssn(new_ssn);
            }

            
            SalariedEmployee* salariedPtr = dynamic_cast<SalariedEmployee*>(employees[i]);
            if (salariedPtr != nullptr) {
                string salary_input;
                cout << "New salary: ";
                getline(cin, salary_input);
                if (!salary_input.empty()) {
                    try {
                        double new_salary = stod(salary_input);
                        if (new_salary >= 0) {
                            salariedPtr->set_salary(new_salary);
                        } else {
                            cout << "Salary must be non-negative. Skipping update.\n";
                        }
                    } catch (...) {
                        cout << "Invalid salary input. Skipping update.\n";
                    }
                }
            }

           
            Administrator* adminPtr = dynamic_cast<Administrator*>(employees[i]);
            if (adminPtr != nullptr) {
                string input;
                cout << "New title: ";
                getline(cin, input);
                if (!input.empty()) adminPtr->set_title(input);

                cout << "New department: ";
                getline(cin, input);
                if (!input.empty()) adminPtr->set_department(input);

                cout << "New supervisor: ";
                getline(cin, input);
                if (!input.empty()) adminPtr->set_supervisor(input);
            }

            cout << "Employee updated successfully.\n";
            save_csv("employees.csv"); // save after update
            break;
        }
    }

    if (!found) {
        cout << "Employee with SSN " << ssn << " not found.\n";
    }
}

void print_employee_check() {
    if (employees.empty()) {
        cout << "No employees available.\n";
        return;
    }

    string ssn;
    cout << "Enter SSN of employee to print paycheck: ";
    cin >> ssn;

    for (int i = 0; i < employees.size(); ++i) {
        if (employees[i]->get_ssn() == ssn) {
            employees[i]->print_check();  // polymorphic call
            return;
        }
    }

    cout << "Employee not found.\n";
}


void cleanup() {
    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }
    employees.clear();
}

int main() {
    load_csv("employees.csv");

    int choice;
    do {
        cout << "\n--- Employee Management Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Delete Employee\n";
        cout << "4. Update/Edit Employee\n";
        cout << "5. Print Paycheck\n";   // new menu option
        cout << "6. Exit\n";
        cout << "Choice: "; 
        cin >> choice; 
        cin.ignore();

        switch(choice) {
            case 1: 
                add_employee(); 
                break;
            case 2: 
                view_employees(); 
                break;
            case 3: 
                delete_employee(); 
                break;
            case 4: 
                update_employee(); 
                break;
            case 5: 
                print_employee_check();   // call to new paycheck function
                break;
            case 6: 
                cout << "Exiting...\n"; 
                break;
            default: 
                cout << "Invalid choice.\n";
        }
    } while(choice != 6);

    // Clean up dynamically allocated memory
    cleanup();
    return 0;
}