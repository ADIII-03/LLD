
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    void setName(string n) {
        name = n;
    }

    void displayName() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    int rollNumber;
};

class Teacher : public Person {
public:
    string subject;
};

class TeachingAssistant : public Student, public Teacher {
};

int main() {

    TeachingAssistant ta;

    // ERROR: TeachingAssistant contains
    // two Person subobjects.

    // ta.setName("Aditya");

    // ta.displayName();

    return 0;
}



// solution 


class Person {
public:
    string name;

    Person(string n) {
        name = n;
    }
};

class Student : virtual public Person {
public:
    Student() : Person("Student") {}
};

class Teacher : virtual public Person {
public:
    Teacher() : Person("Teacher") {}
};

class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant()
        : Person("Aditya"), Student(), Teacher() {}
};