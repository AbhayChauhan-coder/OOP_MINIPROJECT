# Employee Payroll Management System

A simple, menu-driven C++ console application for managing employee payroll records. Add employees, calculate gross and net salary, view payslips, and search records by employee ID.

## Features

- Add employee records with ID, name, salary components, and deductions
- Prevent duplicate employee IDs
- Validate IDs, names, and salary inputs
- Calculate gross salary and net salary
- Display payslips for all employees
- Search for an employee by ID

## Requirements

- A C++ compiler that supports C++11 or later, such as `g++`

## Compile and Run

From the project directory, compile the source file:

```bash
g++ -std=c++11 main.cpp -o payroll
```

Run the application:

```bash
./payroll
```

On Windows with MinGW, run:

```bash
payroll.exe
```

## Usage

Choose an option from the menu:

1. Add Employee
2. Display All Employees and Payslips
3. Search Employee by ID
4. Exit

For each employee, enter a unique positive ID, a name, basic salary, HRA, DA, and total deductions. Deductions must not exceed the total of basic salary, HRA, and DA.

**Salary calculations:**

```text
Gross Salary = Basic Salary + HRA + DA
Net Salary   = Gross Salary - Deductions
```

## Note

Employee records are kept in memory while the program is running. They are not saved to a file or database, so records are cleared when the application exits.
