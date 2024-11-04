#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Student class
class Student {
public:
    string FirstName;
    string LastName;
    string StudentID;

    Student(string FN, string LN, string SID) : FirstName(FN), LastName(LN), StudentID(SID) {}

    // Method to get the full name of the student
    string getFullName() const {
        return FirstName + " " + LastName;
    }
};

// Assignment class
class Assignment {
public:
    string AssignmentName;
    int TotalPoints;

    Assignment(string AN, int TP) : AssignmentName(AN), TotalPoints(TP) {}
};

// Gradebook class
class Gradebook {
private:
    vector<Student> Students;
    vector<Assignment> Assignments;
    vector<vector<int>> grades; // Matrix to store grades for each student and assignment

public:
    // Method to add a new student using full name and ID
    void add_student(const string& fullName, const string& studentID) {
        // Split full name into first and last name
        size_t spacePos = fullName.find(" ");
        if (spacePos == string::npos) {
            cout << "Invalid full name format. Please provide both first and last name.\n";
            return;
        }
        string firstName = fullName.substr(0, spacePos);
        string lastName = fullName.substr(spacePos + 1);

        // Add student to the vector
        Students.push_back(Student(firstName, lastName, studentID));
        grades.push_back(vector<int>(Assignments.size(), -1)); // Initialize grades to -1 for each assignment
    }

    // Method to add a new assignment
    void add_Assignment(const string& assignmentName, int totalPoints) {
        Assignments.push_back(Assignment(assignmentName, totalPoints));
        for (auto& studentGrades : grades) {
            studentGrades.push_back(-1); // Initialize new assignment grade as -1 for each student
        }
    }

    // Method to give a student a grade for an assignment using full name
    void enter_grade(const string& fullName, const string& assignmentName, int score) {
        int studentIndex = findStudentIndexByName(fullName);
        int assignmentIndex = findAssignmentIndex(assignmentName);

        if (studentIndex == -1) {
            cout << "Student not found.\n";
            return;
        }
        if (assignmentIndex == -1) {
            cout << "Assignment not found.\n";
            return;
        }
        if (score < 0 || score > Assignments[assignmentIndex].TotalPoints) {
            cout << "Invalid score. It should be between 0 and " << Assignments[assignmentIndex].TotalPoints << ".\n";
            return;
        }

        grades[studentIndex][assignmentIndex] = score;
    }

    // Method to print a formatted grade report
    void printReport() const {
        cout << setw(20) << "Student Name" << setw(15) << "Student ID";
        for (const auto& assignment : Assignments) {
            cout << setw(15) << assignment.AssignmentName;
        }
        cout << "\n";

        for (size_t i = 0; i < Students.size(); ++i) {
            const Student& student = Students[i];
            cout << setw(20) << student.getFullName()
                << setw(15) << student.StudentID;
            for (int grade : grades[i]) {
                cout << setw(15) << (grade == -1 ? "N/A" : to_string(grade));
            }
            cout << "\n";
        }
    }

private:
    // Helper function to find the index of a student by full name
    int findStudentIndexByName(const string& fullName) const {
        for (size_t i = 0; i < Students.size(); ++i) {
            if (Students[i].getFullName() == fullName) return i;
        }
        return -1;
    }

    // Helper function to find the index of an assignment by name
    int findAssignmentIndex(const string& assignmentName) const {
        for (size_t i = 0; i < Assignments.size(); ++i) {
            if (Assignments[i].AssignmentName == assignmentName) return i;
        }
        return -1;
    }
};

int main() {
    Gradebook gradebook;

    // Add students using full name and ID
    gradebook.add_student("Bob Bobberson", "ABC123");
    gradebook.add_student("Sam Sammerson", "DEF456");
    gradebook.add_student("Jess Jesserson", "HIJ789");

    // Add assignments
    gradebook.add_Assignment("Quiz 1", 100);
    gradebook.add_Assignment("Lab 1", 50);

    // Record grades using full names
    gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
    gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
    gradebook.enter_grade("Jess Jesserson", "Lab 1", 49);
    gradebook.enter_grade("Jess Jesserson", "Quiz 1", 93);
    gradebook.enter_grade("Bob Bobberson", "Lab 1", 0);

    // Print the grade report
    gradebook.printReport();

    return 0;
}
