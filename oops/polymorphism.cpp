
#include <iostream>
#include <string>
using namespace std;


// =====================================================
// 1. COMPILE-TIME POLYMORPHISM
//    FUNCTION OVERLOADING
// =====================================================

class Calculator {

public:

    // Same function name, no parameters

    void add() {

        cout << "Addition without parameters"
             << endl;

    }


    // Same function name, two integer parameters

    int add(int a, int b) {

        return a + b;

    }


    // Same function name, three integer parameters

    int add(int a, int b, int c) {

        return a + b + c;

    }


    // Same function name, different parameter types

    double add(double a, double b) {

        return a + b;

    }

};


// =====================================================
// 2. OPERATOR OVERLOADING
// =====================================================

class Speed {

private:

    int speed;

public:

    Speed(int s) {

        speed = s;

    }


    // Overloading + operator

    Speed operator+(Speed other) {

        Speed result(speed + other.speed);

        return result;

    }


    void display() {

        cout << "Combined Speed: "
             << speed << endl;

    }

};


// =====================================================
// 3. ABSTRACT BASE CLASS
//    RUNTIME POLYMORPHISM
// =====================================================

class Car {

public:

    // Pure virtual functions

    virtual void start() = 0;

    virtual void accelerate() = 0;

    virtual void brake() = 0;

    virtual void stop() = 0;

    virtual void honk() = 0;

    virtual void display() = 0;


    // Virtual destructor

    virtual ~Car() {

        cout << "Car Base Destructor Called"
             << endl;

    }

};


// =====================================================
// 4. SPORTS CAR
// =====================================================

class SportsCar : public Car {

private:

    string brand;

    int topSpeed;

    int currentSpeed;

    int currentGear;

    bool isEngineOn;


public:

    // Constructor

    SportsCar(string b, int ts) {

        brand = b;

        topSpeed = ts;

        currentSpeed = 0;

        currentGear = 1;

        isEngineOn = false;

    }


    // ---------------- GETTERS ----------------

    string getBrand() {

        return brand;

    }


    int getTopSpeed() {

        return topSpeed;

    }


    int getCurrentSpeed() {

        return currentSpeed;

    }


    int getCurrentGear() {

        return currentGear;

    }


    bool getEngineStatus() {

        return isEngineOn;

    }


    // ---------------- SETTERS ----------------

    void setCurrentGear(int gear) {

        if (gear >= 1 && gear <= 6) {

            currentGear = gear;

        }
        else {

            cout << "Invalid Gear!"
                 << endl;

        }

    }


    void setCurrentSpeed(int speed) {

        if (speed >= 0 && speed <= topSpeed) {

            currentSpeed = speed;

        }
        else {

            cout << "Invalid Speed!"
                 << endl;

        }

    }


    // ---------------- OVERRIDING ----------------

    void start() override {

        if (!isEngineOn) {

            isEngineOn = true;

            cout << brand
                 << " Sports Engine Started"
                 << endl;

        }
        else {

            cout << "Engine Already Running"
                 << endl;

        }

    }


    void accelerate() override {

        if (isEngineOn) {

            if (currentSpeed + 20 <= topSpeed) {

                currentSpeed += 20;

                cout << brand
                     << " Sports Car Accelerating"
                     << endl;

                cout << "Speed: "
                     << currentSpeed << endl;

            }
            else {

                currentSpeed = topSpeed;

                cout << "Maximum Speed Reached!"
                     << endl;

            }

        }
        else {

            cout << "Engine is OFF"
                 << endl;

        }

    }


    void brake() override {

        if (isEngineOn) {

            if (currentSpeed >= 20) {

                currentSpeed -= 20;

            }
            else {

                currentSpeed = 0;

            }

            cout << brand
                 << " Sports Car Braking"
                 << endl;

            cout << "Speed: "
                 << currentSpeed << endl;

        }
        else {

            cout << "Engine is OFF"
                 << endl;

        }

    }


    void stop() override {

        if (currentSpeed == 0) {

            isEngineOn = false;

            cout << brand
                 << " Sports Car Stopped"
                 << endl;

        }
        else {

            cout << "Apply Brakes First!"
                 << endl;

        }

    }


    void honk() override {

        cout << "Sports Car: Beep Beep!"
             << endl;

    }


    void display() override {

        cout << "\n----- Sports Car -----"
             << endl;

        cout << "Brand: "
             << brand << endl;

        cout << "Top Speed: "
             << topSpeed << endl;

        cout << "Current Speed: "
             << currentSpeed << endl;

        cout << "Current Gear: "
             << currentGear << endl;

        cout << "Engine: "
             << (isEngineOn ? "ON" : "OFF")
             << endl;

    }


    // Derived destructor

    ~SportsCar() override {

        cout << "SportsCar Destructor Called"
             << endl;

    }

};


// =====================================================
// 5. ELECTRIC CAR
// =====================================================

class ElectricCar : public Car {

private:

    string brand;

    int battery;


public:

    ElectricCar(string b) {

        brand = b;

        battery = 100;

    }


    void start() override {

        cout << brand
             << " Electric Motor Started"
             << endl;

    }


    void accelerate() override {

        cout << brand
             << " Electric Car Accelerating"
             << endl;

    }


    void brake() override {

        cout << brand
             << " Regenerative Braking"
             << endl;

    }


    void stop() override {

        cout << brand
             << " Electric Car Stopped"
             << endl;

    }


    void honk() override {

        cout << "Electric Car: Silent Beep!"
             << endl;

    }


    void display() override {

        cout << "\n----- Electric Car -----"
             << endl;

        cout << "Brand: "
             << brand << endl;

        cout << "Battery: "
             << battery << "%"
             << endl;

    }


    ~ElectricCar() override {

        cout << "ElectricCar Destructor Called"
             << endl;

    }

};


// =====================================================
// 6. BUS
// =====================================================

class Bus : public Car {

private:

    string brand;

    int passengers;


public:

    Bus(string b) {

        brand = b;

        passengers = 40;

    }


    void start() override {

        cout << brand
             << " Diesel Engine Started"
             << endl;

    }


    void accelerate() override {

        cout << brand
             << " Bus Accelerating Slowly"
             << endl;

    }


    void brake() override {

        cout << brand
             << " Bus Applying Brakes"
             << endl;

    }


    void stop() override {

        cout << brand
             << " Bus Stopped"
             << endl;

    }


    void honk() override {

        cout << "Bus: HONK HONK!"
             << endl;

    }


    void display() override {

        cout << "\n----- Bus -----"
             << endl;

        cout << "Brand: "
             << brand << endl;

        cout << "Passengers: "
             << passengers << endl;

    }


    ~Bus() override {

        cout << "Bus Destructor Called"
             << endl;

    }

};


// =====================================================
// 7. MAIN FUNCTION
// =====================================================

int main() {


    // -------------------------------------------------
    // FUNCTION OVERLOADING
    // -------------------------------------------------

    cout << "\n===== FUNCTION OVERLOADING ====="
         << endl;

    Calculator calc;

    calc.add();

    cout << calc.add(10, 20)
         << endl;

    cout << calc.add(10, 20, 30)
         << endl;

    cout << calc.add(10.5, 20.5)
         << endl;


    // -------------------------------------------------
    // OPERATOR OVERLOADING
    // -------------------------------------------------

    cout << "\n===== OPERATOR OVERLOADING ====="
         << endl;

    Speed s1(100);

    Speed s2(150);

    Speed s3 = s1 + s2;

    s3.display();


    // -------------------------------------------------
    // RUNTIME POLYMORPHISM
    // -------------------------------------------------

    cout << "\n===== RUNTIME POLYMORPHISM ====="
         << endl;


    // Base class pointers

    Car* car1 = new SportsCar("Ferrari", 400);

    Car* car2 = new ElectricCar("Tesla");

    Car* car3 = new Bus("Volvo");


    // SportsCar behavior

    cout << "\n===== SPORTS CAR ====="
         << endl;

    car1->start();

    car1->accelerate();

    car1->honk();

    car1->brake();

    car1->display();


    // Access derived class getter using downcasting

    SportsCar* sports =
        dynamic_cast<SportsCar*>(car1);

    if (sports != nullptr) {

        cout << "Current Gear: "
             << sports->getCurrentGear()
             << endl;

        sports->setCurrentGear(3);

        cout << "Updated Gear: "
             << sports->getCurrentGear()
             << endl;

    }


    // ElectricCar behavior

    cout << "\n===== ELECTRIC CAR ====="
         << endl;

    car2->start();

    car2->accelerate();

    car2->honk();

    car2->brake();

    car2->display();

    car2->stop();


    // Bus behavior

    cout << "\n===== BUS ====="
         << endl;

    car3->start();

    car3->accelerate();

    car3->honk();

    car3->brake();

    car3->display();

    car3->stop();


    // -------------------------------------------------
    // DELETE OBJECTS
    // -------------------------------------------------

    cout << "\n===== DESTRUCTORS ====="
         << endl;

    delete car1;

    delete car2;

    delete car3;


    return 0;

}
