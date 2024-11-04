# Gradebook Application for CSC 122:

This project is a simple C++ gradebook application designed to track students, assignments, and their grades. It includes functionality to add students and assignments, enter grades, and print a formatted report.


# Features
The Gradebook application allows you to:

1. Add a student by entering their full name and student ID.
2. Add an assignment by specifying the assignment name and total points possible.
3. Record a grade for a specific student on a specific assignment.
4. Print a report displaying all students, their IDs, and their grades for each assignment.


# Getting Started
### Prerequisites

To compile and run this project, you need:

1. A C++ compiler, such as g++, which comes with the GCC Compiler Collection for most systems.
2. Any code editor, such as Visual Studio Code, CLion, or even a basic text editor.

## Compilation
1. Clone or download the code.

2. **Compile** using the following command (assuming you saved it as you_got_an_a_.cpp):

**g++ you_get_an_a.cpp -o gradebook**

3. **Run** the compiled program:

**./you_get_an_a**


## Usage
Here is an example of how to use the Gradebook program in your main function:

**Adding Students:** Use add_student to add a student to the gradebook.

gradebook.add_student("Bob Bobberson", "ABC123");
gradebook.add_student("Sam Sammerson", "DEF456");
gradebook.add_student("Jess Jesserson", "HIJ789");


**Adding Assignments:** Use add__Assignment to add an assignment, specifying the assignment name and total points.

gradebook.addAssignment("Quiz 1", 100);
gradebook.addAssignment("Lab 1", 50);


**Recording Grades:** Use enter_grade to record a grade for a specific student on a specific assignment.

gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
gradebook.enter_grade("Jess Jesserson", "Lab 1", 49);
gradebook.enter_grade("Jess Jesserson", "Quiz 1", 93);


**Printing the Report:** Use printReport to view a formatted table of students, assignments, and grades.

gradebook.printReport();

## Sample Output
A sample output after running the above example code would look like this:

       Student Name      Student ID       Quiz 1         Lab 1    
    Sam Sammerson       DEF456             95             N/A    
    Bob Bobberson       ABC123             85             0      
    Jess Jesserson      HIJ789             93             49     
Note: If a grade is not entered, it will display as N/A.


# Class Overview

## Student Class
Represents a student in the gradebook, with attributes for:

FirstName: The first name of the student.
LastName: The last name of the student.
StudentID: The unique identifier for the student.

## Assignment Class
Represents an assignment, with attributes for:

AssignmentName: Name of the assignment (e.g., "Quiz 1").
TotalPoints: Maximum points possible for the assignment.

## Gradebook Class
Holds all students, assignments, and grades. Key methods include:

**add_student:** Adds a student using full name and student ID.
**add__Assignment:** Adds an assignment with a name and total points.
**enter_grade:** Records a grade for a given student and assignment.
**printReport:** Prints a report of all students, their IDs, and grades for each assignment.


## Additional Notes
**Input Validation:** When entering grades, the program checks that the score is within the allowed range (0 to total points for that assignment).

**Student and Assignment Search:** Student lookups are by full name; assignment lookups are by name. Ensure no duplicate names are used to avoid ambiguity.
