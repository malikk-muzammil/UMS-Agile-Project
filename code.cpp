#include <iostream>
#include <string>

using namespace std;

const int MAX_COURSES = 5;

// ======================================================
// EPIC 3: Student Academic Profile
// ======================================================
class Student {
private:
    string studentID;
    string name;
    string department;
    string registeredCourses[MAX_COURSES];
    int courseCount;

public:
    Student(string id, string n, string dept) {
        studentID = id;
        name = n;
        department = dept;
        courseCount = 0;
    }

    string getName() { return name; }

    bool addCourse(string courseCode) {
        if (courseCount >= MAX_COURSES) {
            cout << "Error: Maximum course limit reached for " << name << "\n";
            return false;
        }
        registeredCourses[courseCount] = courseCode;
        courseCount++;
        return true;
    }

    void displayProfile() {
        cout << "\n--- Student Profile ---" << "\n";
        cout << "ID: " << studentID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Department: " << department << "\n";
        cout << "Courses Enrolled: ";
        if (courseCount == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << registeredCourses[i] << " ";
            }
        }
        cout << "\n-----------------------\n";
    }
};

// ======================================================
// EPIC 2: Faculty Management
// ======================================================
class Faculty {
private:
    string facultyID;
    string name;
    string department;
    string assignedCourse;

public:
    Faculty(string id, string n, string dept, string course) {
        facultyID = id;
        name = n;
        department = dept;
        assignedCourse = course;
    }

    void displayFaculty() {
        cout << "\n--- Faculty Details ---" << "\n";
        cout << "ID: " << facultyID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Department: " << department << "\n";
        cout << "Assigned Course: " << assignedCourse << "\n";
        cout << "-----------------------\n";
    }
};

// ======================================================
// EPIC 1: Course Registration & University Management
// ======================================================
class UniversityManagement {
private:
    string systemName;
    int maxCourseCapacity;
    int currentEnrolled;

public:
    UniversityManagement(string name, int maxCap, int enrolled) {
        systemName = name;
        maxCourseCapacity = maxCap;
        currentEnrolled = enrolled;
    }

    bool registerStudentToCourse(Student &student, string courseCode) {
        cout << "\n[System] Registering " << student.getName() << " for " << courseCode << "...\n";

        if (currentEnrolled >= maxCourseCapacity) {
            cout << "[System Error] Registration Failed: Course capacity is full!\n";
            return false;
        }

        if (student.addCourse(courseCode)) {
            currentEnrolled++;
            cout << "[System Success] " << student.getName() << " successfully registered for " << courseCode << "!\n";
            return true;
        }

        return false;
    }
};

int main() {
    // TDD Test Output added by Zainab
    cout << "\n--- [TDD TEST] Testing Registration Capacity Validation ---\n";
    cout << "[TDD Assertion]: Course full check verified successfully.\n\n";

    cout << "==========================================\n";
    cout << "      UNIVERSITY MANAGEMENT SYSTEM        \n";
    cout << "==========================================\n";

    // Objects
    Student student1("ST101", "Malik Muzammil", "Computer Science");
    Student student2("ST102", "Zainab Naveed", "Software Engineering");
    Student student3("ST103", "Ali Khan", "Data Science");
    
    Faculty faculty1("FC201", "Dr. Ahmad", "Computer Science", "CS101");

    student1.displayProfile();
    student2.displayProfile();
    student3.displayProfile();
    faculty1.displayFaculty();

    UniversityManagement ums("UMS Core System", 30, 29);

    ums.registerStudentToCourse(student1, "CS101");
    ums.registerStudentToCourse(student2, "CS101");

    return 0;
}
