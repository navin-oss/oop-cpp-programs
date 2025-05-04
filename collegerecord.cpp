#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
    int rollNumber;
    string branch;
    float CGPA;
public:
    Student(string n, int a, int roll, string br, float marks[]) 
    : Person(n, a), rollNumber(roll), branch(br) {
        CGPA = 0;
        for (int i = 0; i < 5; i++) CGPA += marks[i];
        CGPA /= 5;
    }
    void display() {
        Person::display();
        cout << "Roll No: " << rollNumber << ", Branch: " << branch << ", CGPA: " << CGPA << endl;
    }
};

class Faculty : public Person {
    int facultyID;
    string department;
    float salary;
public:
    Faculty(string n, int a, int id, string dept, float sal) 
    : Person(n, a), facultyID(id), department(dept), salary(sal) {}
    void display() {
        Person::display();
        cout << "Faculty ID: " << facultyID << ", Department: " << department << ", Salary: " << salary << endl;
    }
};

int main() {
    float marks[] = {8.2, 8.5, 8.1, 9.0, 8.8};
    Student s("Navin Karavade", 20, 50, "AIML", marks);
    Faculty f("Avni Shahane", 35, 2001, "Computer Science", 97000);

    cout << "Student Details:\n";
    s.display();
    cout << "\nFaculty Details:\n";
    f.display();

    return 0;
}

