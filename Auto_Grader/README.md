Overview
********
Auto Grader is a software tool designed to assist the Computer Science department in managing and automating the course allocation process. Developed as a part of an academic assignment, this system handles the assignment of courses to professors based on provided data files.

Features
********
    •	File Handling: Reads course and professor data from external files.
    •	Dynamic Allocation: Supports allocation for a variable number of courses and professors.
    •	Data Parsing: Implements parsing of data into structured formats using arrays and strings.
    •	Prediction Algorithm: Includes an algorithm to predict professor assignments for future terms.
    •	User Interface: Offers a menu-driven interface for interactive user engagement.



Technical Details
*****************
    •	Languages Used: C (Standard: C99)
    •	Key Concepts: File handling, command-line arguments, arrays, strings, and data structures.
    •	Development Tools: Makefile for compilation and GitLab for version control.


Functionality
*************
    1.	File Reading: Opens and reads data from specified files.
    2.	Data Processing: Processes course and professor information into structured formats.
    3.	Statistical Analysis: Computes statistics like the average number of courses taught per professor.
    4.	Prediction and Allocation: Predicts future course assignments.
    5.	User Interaction: Provides a menu for accessing various functionalities.


Compilation and Execution
*************************
Compiled using -std=c99 -Wall flags. The makefile provided simplifies the compilation process.
Running the Program
bashCopy code---  
./ShamsToahaAymanA1


Usage
*****
    •	First, populate the data using functions from tasks 1, 2, and 3.
    •	Interact with the system through the menu to perform tasks 4 to 8.
    •	The system exits when a choice other than 4, 5, 6, 7, or 8 is entered.


Future Enhancements
*******************
    •	Implementing a more robust error-handling mechanism.
    •	Enhancing the prediction algorithm for course allocation.
    •	Developing a graphical user interface for ease of use.
