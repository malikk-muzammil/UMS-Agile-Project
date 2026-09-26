#include <iostream>
#include <string>

using namespace std;

// Maximum capacity for array storage
const int MAX_COURSES = 5;

// ======================================================
// FEATURE 1: Student Academic Profile (UMS-3)
// ======================================================
struct Student {
    string studentID;
    string name;
    string department;
    string registeredCourses[MAX_COURSES]; // Array instead of vector
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
// FEATURE 2: Faculty Management (UMS-2)
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
// FEATURE 3: Course Registration System (UMS-1)
// ======================================================
class CourseRegistrationSystem {
private:
    int maxCapacity;
    int currentEnrolled;

public:
    CourseRegistrationSystem(int capacity, int enrolled) 
        : maxCapacity(capacity), currentEnrolled(enrolled) {}

    // Validation logic for registration (TDD & Pair Programming logic)
    bool registerCourse(Student& student, const string& courseCode) {
        cout << "\nAttempting registration for " << student.name 
             << " in course: " << courseCode << "...\n";

        // Capacity check validation
        if (currentEnrolled >= maxCapacity) {
            cout << "[ERROR]: Course capacity is FULL! Registration failed.\n";
            return false;
        }

        // Student array limit check
        if (student.courseCount >= MAX_COURSES) {
            cout << "[ERROR]: Student course limit reached.\n";
            return false;
        }

        // Duplicate registration check validation
        for (int i = 0; i < student.courseCount; i++) {
            if (student.registeredCourses[i] == courseCode) {
                cout << "[ERROR]: Student already registered for this course.\n";
                return false;
            }
        }

        // Successful enrollment into array
        student.registeredCourses[student.courseCount] = courseCode;
        student.courseCount++;
        currentEnrolled++;
        cout << "[SUCCESS]: Registration approved for " << courseCode << "!\n";
        return true;
    }
};

// ======================================================
// MAIN EXECUTION LOGIC
// ======================================================
int main() {
    cout << "==================================================\n";
    cout << "     UNIVERSITY MANAGEMENT SYSTEM (UMS) - AGILE  \n";
    cout << "==================================================\n";

    // 1. Initialize Student and Faculty Profile
    Student student1 = {"ST-101", "Zainab Naveed", "Computer Science"};
    Faculty faculty1 = {"FC-201", "Malik Muzammil", "Software Engineering", "CS-101"};

    // Display initial state
    faculty1.displayFacultyDetails();
    student1.displayProfile();

    // 2. Initialize Course Registration System (Capacity: 30, Enrolled: 29)
    CourseRegistrationSystem registrationSystem(30, 29);

    // 3. Register Student for CS-101 (Should succeed)
    registrationSystem.registerCourse(student1, "CS-101");
    student1.displayProfile();

    // 4. Try registering for CS-101 again (Should trigger duplicate validation error)
    registrationSystem.registerCourse(student1, "CS-101");

    return 0;
}
