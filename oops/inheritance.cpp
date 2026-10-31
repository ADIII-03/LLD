
#include <iostream>
#include <string>
using namespace std;

// ============================================================
// 1. SINGLE INHERITANCE
// One parent class -> One child class
// ============================================================

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person() {
        name = "Unknown";
        age = 0;
    }

    // Setter for name
    void setName(string n) {
        name = n;
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for age
    void setAge(int a) {
        if (a > 0 && a <= 100) {
            age = a;
        }
    }

    // Getter for age
    int getAge() const {
        return age;
    }
};


// Student inherits Person
class Student : public Person {
private:
    int rollNumber;

public:
    Student() {
        rollNumber = 0;
    }

    void setRollNumber(int r) {
        if (r > 0) {
            rollNumber = r;
        }
    }

    int getRollNumber() const {
        return rollNumber;
    }

    void displayStudent() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Roll Number: " << getRollNumber() << endl;
    }
};


// ============================================================
// 2. MULTILEVEL INHERITANCE
// Person -> Student -> GraduateStudent
// ============================================================

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent() {
        researchTopic = "Not assigned";
    }

    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    void displayGraduateStudent() {
        // Inherited methods from Person and Student
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Roll Number: " << getRollNumber() << endl;

        // Own method
        cout << "Research Topic: " << getResearchTopic() << endl;
    }
};


// ============================================================
// 3. MULTIPLE INHERITANCE
// Person + Sports -> SportsStudent
// ============================================================

// Second parent class
class Sports {
private:
    string sportName;

public:
    Sports() {
        sportName = "Not assigned";
    }

    void setSport(string s) {
        sportName = s;
    }

    string getSport() const {
        return sportName;
    }
};


// Student inherits from Person
// SportsStudent inherits from both Person and Sports
class SportsStudent : public Person, public Sports {
private:
    int sportsId;

public:
    SportsStudent() {
        sportsId = 0;
    }

    void setSportsId(int id) {
        if (id > 0) {
            sportsId = id;
        }
    }

    int getSportsId() const {
        return sportsId;
    }

    void displaySportsStudent() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Sport: " << getSport() << endl;
        cout << "Sports ID: " << getSportsId() << endl;
    }
};


// ============================================================
// 4. HIERARCHICAL INHERITANCE
// One parent -> Multiple children
// Animal -> Dog and Cat
// ============================================================

class Animal {
private:
    string animalName;

public:
    Animal() {
        animalName = "Unknown";
    }

    void setAnimalName(string n) {
        animalName = n;
    }

    string getAnimalName() const {
        return animalName;
    }

    void eat() {
        cout << animalName << " is eating" << endl;
    }
};


// Dog inherits Animal
class Dog : public Animal {
public:
    void bark() {
        cout << getAnimalName() << " is barking" << endl;
    }
};


// Cat inherits Animal
class Cat : public Animal {
public:
    void meow() {
        cout << getAnimalName() << " is meowing" << endl;
    }
};


// ============================================================
// 5. HYBRID INHERITANCE
// Combination of hierarchical and multiple inheritance
//
//             Person
//            /      \
//       Student    Teacher
//            \      /
//         TeachingAssistant
//
// Virtual inheritance prevents duplicate Person subobjects.
// ============================================================

class Teacher : virtual public Person {
private:
    string subject;

public:
    Teacher() {
        subject = "Not assigned";
    }

    void setSubject(string s) {
        subject = s;
    }

    string getSubject() const {
        return subject;
    }
};


// Virtual inheritance from Person
class VirtualStudent : virtual public Person {
private:
    int studentId;

public:
    VirtualStudent() {
        studentId = 0;
    }

    void setStudentId(int id) {
        if (id > 0) {
            studentId = id;
        }
    }

    int getStudentId() const {
        return studentId;
    }
};


// TeachingAssistant inherits both Student and Teacher
class TeachingAssistant : public VirtualStudent, public Teacher {
public:
    void displayTA() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Student ID: " << getStudentId() << endl;
        cout << "Subject: " << getSubject() << endl;
    }
};


// ============================================================
// MAIN FUNCTION
// ============================================================

int main() {

    // --------------------------------------------------------
    // SINGLE INHERITANCE
    // --------------------------------------------------------

    cout << "\n===== SINGLE INHERITANCE =====" << endl;

    Student s;

    s.setName("Aditya");
    s.setAge(20);
    s.setRollNumber(101);

    s.displayStudent();


    // --------------------------------------------------------
    // MULTILEVEL INHERITANCE
    // --------------------------------------------------------

    cout << "\n===== MULTILEVEL INHERITANCE =====" << endl;

    GraduateStudent g;

    g.setName("Rahul");
    g.setAge(23);
    g.setRollNumber(102);
    g.setResearchTopic("Artificial Intelligence");

    g.displayGraduateStudent();


    // --------------------------------------------------------
    // MULTIPLE INHERITANCE
    // --------------------------------------------------------

    cout << "\n===== MULTIPLE INHERITANCE =====" << endl;

    SportsStudent ss;

    ss.setName("Aditya");
    ss.setAge(20);
    ss.setSport("Cricket");
    ss.setSportsId(501);

    ss.displaySportsStudent();


    // --------------------------------------------------------
    // HIERARCHICAL INHERITANCE
    // --------------------------------------------------------

    cout << "\n===== HIERARCHICAL INHERITANCE =====" << endl;

    Dog d;

    d.setAnimalName("Tommy");
    d.eat();
    d.bark();

    cout << endl;

    Cat c;

    c.setAnimalName("Kitty");
    c.eat();
    c.meow();


    // --------------------------------------------------------
    // HYBRID INHERITANCE
    // --------------------------------------------------------

    cout << "\n===== HYBRID INHERITANCE =====" << endl;

    TeachingAssistant ta;

    ta.setName("Aditya");
    ta.setAge(21);
    ta.setStudentId(201);
    ta.setSubject("C++");

    ta.displayTA();


    return 0;
}
