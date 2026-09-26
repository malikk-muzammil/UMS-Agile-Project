#include <iostream>
#include <string>

using namespace std;

const int MAX_COURSES = 5;

// ======================================================
// FEATURE 1 & 3: Student Profile & Registration Logic
// ======================================================
struct Student {
    string studentID;
    string name;
    string department;
    string registeredCourses[MAX_COURSES];
    int courseCount = 0;
    
    void displayProfile() const {
        cout << "\n========================================\n";
        cout << "         STUDENT ACADEMIC PROFILE       \n";
        cout << "========================================\n";
        cout << "ID         : " << studentID << "\n";
        cout << "Name       : " << name << "\n";
        cout << "Department : " << department << "\n";
        cout << "Courses Enrolled (" << courseCount << "): ";
        if (courseCount == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << registeredCourses[i] << " ";
            }
        }
        cout << "\n========================================\n";
    }
};

// ======================================================
// FEATURE 2: Faculty Management
// ======================================================
struct Faculty {
    string facultyID;
    string name;
    string department;
    string assignedCourse;

    void displayFacultyDetails() const {
        cout << "\n========================================\n";
        cout << "           FACULTY DETAILS              \n";
        cout << "========================================\n";
        cout << "Faculty ID : " << facultyID << "\n";
        cout << "Name       : " << name << "\n";
        cout << "Department : " << department << "\n";
        cout << "Assigned   : " << assignedCourse << "\n";
        cout << "========================================\n";
    }
};

// ======================================================
// COURSE REGISTRATION SYSTEM WITH VALIDATION RULES
// ======================================================
class CourseRegistrationSystem {
private:
    int maxCapacity;
    int currentEnrolled;

public:
    CourseRegistrationSystem(int capacity, int enrolled) 
        : maxCapacity(capacity), currentEnrolled(enrolled) {}

    bool registerCourse(Student& student, const string& courseCode) {
        cout << "\nAttempting registration for " << student.name 
             << " in course: " << courseCode << "...\n";

        if (currentEnrolled >= maxCapacity) {
            cout << "[ERROR]: Course capacity is FULL! Registration failed.\n";
            return false;
        }

        if (student.courseCount >= MAX_COURSES) {
            cout << "[ERROR]: Student course limit reached.\n";
            return false;
        }

        for (int i = 0; i < student.courseCount; i++) {
            if (student.registeredCourses[i] == courseCode) {
                cout << "[ERROR]: Student already registered for this course.\n";
                return false;
            }
        }

        student.registeredCourses[student.courseCount] = courseCode;
        student.courseCount++;
        currentEnrolled++;
        cout << "[SUCCESS]: Registration approved for " << courseCode << "!\n";
        return true;
    }
};

int main() {
    cout << "==================================================\n";
    cout << "     UNIVERSITY MANAGEMENT SYSTEM (UMS) - AGILE  \n";
    cout << "==================================================\n";

    // Team members testing student registration logic
    Student student1 = {"ST-101", "Malik Muzammil", "Computer Science"};
    Student student2 = {"ST-102", "Zainab Naveed", "Software Engineering"};
    Faculty instructor = {"FC-201", "Dr. Ahmad", "Computer Science", "CS-101"};

    instructor.displayFacultyDetails();
    
    CourseRegistrationSystem registrationSystem(30, 28);

    // Registering both team members as students in the test system
    registrationSystem.registerCourse(student1, "CS-101");
    student1.displayProfile();

    registrationSystem.registerCourse(student2, "CS-101");
    student2.displayProfile();

    return 0;
}
