
#include <iostream>
#include <string>
using namespace std;


// =====================================================
// ABSTRACT BASE CLASS
// =====================================================

class Car {

public:

    // Pure virtual functions
    // Every derived car class must implement these functions

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual void accelerate() = 0;

    virtual void brake() = 0;

    virtual void honk() = 0;

    virtual void display() = 0;


    // Virtual destructor
    // Ensures proper destruction of derived objects
    // through a base class pointer

    virtual ~Car() {
        cout << "Car Base Destructor Called" << endl;
    }

};


// =====================================================
// DERIVED CLASS
// =====================================================

class SportsCar : public Car {

private:

    // Private data members
    // Cannot be directly accessed from main()

    string brand;

    int topSpeed;

    string model;

    int currentGear;

    string color;

    bool isEngineOn;

    int currentSpeed;


public:

    // -------------------------------------------------
    // CONSTRUCTOR
    // -------------------------------------------------

    SportsCar(string b, int ts, string m, int cg, string c) {

        brand = b;

        topSpeed = ts;

        model = m;

        currentGear = cg;

        color = c;

        isEngineOn = false;

        currentSpeed = 0;
    }


    // -------------------------------------------------
    // GETTERS
    // -------------------------------------------------

    string getBrand() {
        return brand;
    }

    int getTopSpeed() {
        return topSpeed;
    }

    string getModel() {
        return model;
    }

    int getCurrentGear() {
        return currentGear;
    }

    string getColor() {
        return color;
    }

    bool getEngineStatus() {
        return isEngineOn;
    }

    int getCurrentSpeed() {
        return currentSpeed;
    }


    // -------------------------------------------------
    // SETTERS
    // -------------------------------------------------

    void setCurrentGear(int cg) {

        if (cg >= 1 && cg <= 6) {

            currentGear = cg;

        }
        else {

            cout << "Invalid Gear!" << endl;

        }

    }


    void setCurrentSpeed(int cs) {

        if (cs >= 0 && cs <= topSpeed) {

            currentSpeed = cs;

        }
        else {

            cout << "Invalid Speed!" << endl;

        }

    }


    // -------------------------------------------------
    // IMPLEMENTATION OF ABSTRACT FUNCTIONS
    // -------------------------------------------------

    // Starts the engine

    void start() override {

        if (!isEngineOn) {

            isEngineOn = true;

            cout << "Sports Car Engine Started" << endl;

        }
        else {

            cout << "Engine is already running" << endl;

        }

    }


    // Stops the engine
    // Engine can stop only when car speed is zero

    void stop() override {

        if (currentSpeed == 0) {

            isEngineOn = false;

            cout << "Sports Car Engine Stopped" << endl;

        }
        else {

            cout << "Apply brakes before stopping!" << endl;

        }

    }


    // Accelerates the car

    void accelerate() override {

        if (isEngineOn) {

            if (currentSpeed + 10 <= topSpeed) {

                currentSpeed += 10;

                cout << "Sports Car Accelerating" << endl;

                cout << "Current Speed: "
                     << currentSpeed << endl;

            }
            else {

                currentSpeed = topSpeed;

                cout << "Maximum Speed Reached!" << endl;

            }

        }
        else {

            cout << "Sports Car Engine is off" << endl;

        }

    }


    // Applies brakes

    void brake() override {

        if (isEngineOn) {

            if (currentSpeed > 0) {

                currentSpeed -= 10;

                // Prevent negative speed

                if (currentSpeed < 0) {

                    currentSpeed = 0;

                }

                cout << "Sports Car Braking" << endl;

                cout << "Current Speed: "
                     << currentSpeed << endl;

            }
            else {

                cout << "Car is already stationary" << endl;

            }

        }
        else {

            cout << "Sports Car Engine is off" << endl;

        }

    }


    // Honks the car

    void honk() override {

        cout << "Sports Car Honking" << endl;

    }


    // Displays car details

    void display() override {

        cout << "\n----- Sports Car Details -----" << endl;

        cout << "Brand: " << brand << endl;

        cout << "Top Speed: " << topSpeed << endl;

        cout << "Model: " << model << endl;

        cout << "Current Gear: " << currentGear << endl;

        cout << "Color: " << color << endl;

        cout << "Current Speed: " << currentSpeed << endl;

        cout << "Engine Status: "
             << (isEngineOn ? "ON" : "OFF") << endl;

    }


    // -------------------------------------------------
    // DERIVED CLASS DESTRUCTOR
    // -------------------------------------------------

    ~SportsCar() override {

        cout << "SportsCar Destructor Called" << endl;

    }

};


// =====================================================
// MAIN FUNCTION
// =====================================================

int main() {


    // Base class pointer
    // Points to a SportsCar object

    Car* myCar = new SportsCar(
        "Ferrari",
        400,
        "F8",
        5,
        "Red"
    );


    // Runtime polymorphism
    // Car pointer calls SportsCar implementations

    myCar->start();

    myCar->honk();

    myCar->accelerate();

    myCar->accelerate();

    myCar->brake();

    myCar->display();


    // Stop the car safely
    // Current speed is 10, so brake once more

    myCar->brake();

    myCar->stop();


    // Delete dynamically allocated object

    delete myCar;


    return 0;

}
