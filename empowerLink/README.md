EmpowerLink: Dynamic Employee Management System

Introduction
************
EmpowerLink is a comprehensive employee management solution designed for companies seeking an efficient way to organize and manage employee records. Utilizing dynamic linked lists in C programming, EmpowerLink offers an intuitive interface for handling various tasks such as adding, editing, and removing employee details.


Key Features
************
    •	Dynamic Linked List Implementation: Efficient handling of employee records using dynamic linked lists.
    •	User-Friendly Interface: Command-line based menu for easy navigation and operation.
    •	Versatile Employee Management: Functions include adding, displaying, searching, and removing employee data.
    •	Unique Employee ID Generation: Auto-generates unique employee IDs based on a predefined rule.
    •	Dependent Management: Dynamic allocation for storing dependent names.
    •	Sorting and Counting: Ability to sort employees by ID and count the total number of employees.

  
Technical Specifications
*************************
    •	Programming Language: C (Standard: C99)
    •	Data Structure: User-defined structure for employee records.
    •	Folder Structure: Organized into src, include, and bin folders for source files, header files, and executable files


Functionality Overview
***********************
    1.	Add New Employee: recruitEmployee for entering and adding new employee data.
    2.	Print All Employees: printAll to display data of all employees in the linked list.
    3.	Print Specific Employee: printOne for showing details of the nth employee.
    4.	Search by ID: lookOnId to find an employee based on their empId.
    5.	Search by Name: lookOnFullName to search an employee by their full name.
    6.	Count Employees: countEmployees to get the total number of employees.
    7.	Sort by ID: sortEmployeesId for ordering employees based on empId.
    8.	Remove Specific Employee: fireOne to remove the nth employee from the list.
    9.	Remove All Employees: fireAll to clear the entire employee list.


Compilation and Usage
*********************
    •	Compiled with -std=c99 -Wall flags.
    •	Makefile provided for streamlined compilation.
    •	Run with ./bin/proFile.
