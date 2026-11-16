#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

bool readInt(const string& prompt, int& value) {
    cout << prompt;
    if (cin >> value) {
        return true;
    }

    if (!cin.eof()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return false;
}

bool readAmount(const string& prompt, double& value) {
    cout << prompt;
    if (cin >> value && isfinite(value)) {
        return true;
    }

    if (!cin.eof()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return false;
}

class Employee {
private:
    int id;
    string name;
    double basicSalary;
    double hra;
    double da;
    double deductions;

public:
    Employee(int employeeId, const string& employeeName,
             double basic, double houseRentAllowance,
             double dearnessAllowance, double totalDeductions)
        : id(employeeId),
          name(employeeName),
          basicSalary(basic),
          hra(houseRentAllowance),
          da(dearnessAllowance),
          deductions(totalDeductions) {}

    int getId() const {
        return id;
    }

    double calculateGrossSalary() const {
        return basicSalary + hra + da;
    }

    double calculateNetSalary() const {
        return calculateGrossSalary() - deductions;
    }

    void displayDetails() const {
        cout << fixed << setprecision(2);
        cout << "\n----------------------------------------\n";
        cout << "          EMPLOYEE PAYSLIP\n";
        cout << "----------------------------------------\n";
        cout << "Employee ID       : " << id << '\n';
        cout << "Employee Name     : " << name << '\n';
        cout << "Basic Salary      : Rs. " << basicSalary << '\n';
        cout << "HRA               : Rs. " << hra << '\n';
        cout << "DA                : Rs. " << da << '\n';
        cout << "Gross Salary      : Rs. " << calculateGrossSalary() << '\n';
        cout << "Deductions        : Rs. " << deductions << '\n';
        cout << "Net Salary        : Rs. " << calculateNetSalary() << '\n';
        cout << "----------------------------------------\n";
    }
};

class PayrollManagementSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee() {
        int id;
        string name;
        double basicSalary, hra, da, deductions;

        if (!readInt("\nEnter employee ID: ", id)) {
            cout << "Invalid employee ID.\n";
            return;
        }

        if (id <= 0) {
            cout << "Employee ID must be positive.\n";
            return;
        }

        for (const Employee& employee : employees) {
            if (employee.getId() == id) {
                cout << "An employee with this ID already exists.\n";
                return;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter employee name: ";
        if (!getline(cin, name) ||
            name.find_first_not_of(" \t") == string::npos) {
            cout << "Employee name cannot be empty.\n";
            return;
        }

        if (!readAmount("Enter basic salary: Rs. ", basicSalary) ||
            !readAmount("Enter HRA: Rs. ", hra) ||
            !readAmount("Enter DA: Rs. ", da) ||
            !readAmount("Enter total deductions: Rs. ", deductions)) {
            cout << "Invalid salary input. Please enter numeric amounts.\n";
            return;
        }

        if (basicSalary < 0 || hra < 0 || da < 0 || deductions < 0 ||
            deductions > basicSalary + hra + da) {
            cout << "Invalid salary details. Please enter valid amounts.\n";
            return;
        }

        employees.emplace_back(id, name, basicSalary, hra, da, deductions);
        cout << "\nEmployee added successfully!\n";
    }

    void displayAllEmployees() const {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        for (const Employee& employee : employees) {
            employee.displayDetails();
        }
    }

    void searchEmployee() const {
        int searchId;
        if (!readInt("\nEnter employee ID to search: ", searchId)) {
            cout << "Invalid employee ID.\n";
            return;
        }

        for (const Employee& employee : employees) {
            if (employee.getId() == searchId) {
                employee.displayDetails();
                return;
            }
        }

        cout << "Employee not found.\n";
    }

    void showMenu() {
        int choice = 0;

        do {
            cout << "\n========== EMPLOYEE PAYROLL MANAGEMENT ==========\n";
            cout << "1. Add Employee\n";
            cout << "2. Display All Employees and Payslips\n";
            cout << "3. Search Employee by ID\n";
            cout << "4. Exit\n";

            if (!readInt("Enter your choice: ", choice)) {
                if (cin.eof()) {
                    cout << "\nInput ended. Exiting.\n";
                    break;
                }
                cout << "\nInvalid input. Please enter a number.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    displayAllEmployees();
                    break;
                case 3:
                    searchEmployee();
                    break;
                case 4:
                    cout << "\nThank you for using the Payroll Management System!\n";
                    break;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    PayrollManagementSystem payrollSystem;
    payrollSystem.showMenu();
    return 0;
}
