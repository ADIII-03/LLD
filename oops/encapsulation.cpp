
#include <iostream>
#include <string>
using namespace std;

class SportsCar {

private:
    // Private data members
    // These cannot be accessed directly from main()

    string brand;
    int topSpeed;
    string model;
    int currentGear;
    string color;
    bool isEngineOn;
    int currentSpeed;

public:

    // Constructor
    // Initializes the car when an object is created

    SportsCar(string b, int ts, string m, int cg, string c) {

        brand = b;
        topSpeed = ts;
        model = m;
        currentGear = cg;
        color = c;

        isEngineOn = false;
        currentSpeed = 0;
    }

    // ---------------- GETTERS ----------------

    // Returns the current speed
    int getCurrentSpeed() {
        return currentSpeed;
    }

    // Returns the current gear
    int getCurrentGear() {
        return currentGear;
    }

    // Returns the brand
    string getBrand() {
        return brand;
    }

    // Returns the model
    string getModel() {
        return model;
    }

    // Returns the color
    string getColor() {
        return color;
    }

    // Returns the maximum speed
    int getTopSpeed() {
        return topSpeed;
    }

    // Returns engine status
    bool getEngineStatus() {
        return isEngineOn;
    }


    // ---------------- SETTERS ----------------

    // Sets current speed
    // Speed must be between 0 and topSpeed

    void setCurrentSpeed(int cs) {

        if (cs >= 0 && cs <= topSpeed) {
            currentSpeed = cs;
        }
        else {
            cout << "Invalid speed!" << endl;
        }
    }

    // Sets current gear
    // Gear must be between 1 and 6

    void setCurrentGear(int cg) {

        if (cg >= 1 && cg <= 6) {
            currentGear = cg;
        }
        else {
            cout << "Invalid gear!" << endl;
        }
    }


    // ---------------- CAR FUNCTIONS ----------------

    // Starts the engine

    void start() {

        if (!isEngineOn) {
            isEngineOn = true;
            cout << "Sports Car Engine Started" << endl;
        }
        else {
            cout << "Engine is already running" << endl;
        }
    }


    // Stops the engine
    // Car must be stationary before stopping

    void stop() {

        if (currentSpeed == 0) {
            isEngineOn = false;
            cout << "Sports Car Engine Stopped" << endl;
        }
        else {
            cout << "Apply brakes before stopping the engine!" << endl;
        }
    }


    // Accelerates the car

    void accelerate() {

        if (isEngineOn) {

            if (currentSpeed + 10 <= topSpeed) {

                currentSpeed += 10;

                cout << "Sports Car Accelerating" << endl;
                cout << "Current Speed: "
                     << currentSpeed << endl;
            }
            else {
                currentSpeed = topSpeed;

                cout << "Maximum speed reached!" << endl;
            }

        }
        else {
            cout << "Sports Car Engine is off" << endl;
        }
    }


    // Applies brakes and reduces speed

    void brake() {

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

    void honk() {

        cout << "Sports Car Honking" << endl;
    }


    // Displays car details

    void display() {

        cout << "\n----- Sports Car Details -----" << endl;

        cout << "Brand: " << brand << endl;
        cout << "Top Speed: " << topSpeed << endl;
        cout << "Model: " << model << endl;
        cout << "Current Gear: " << currentGear << endl;
        cout << "Color: " << color << endl;

        cout << "Current Speed: "
             << currentSpeed << endl;

        cout << "Is Engine On: "
             << (isEngineOn ? "Yes" : "No") << endl;
    }

};


int main() {

    // Creating object of SportsCar

    SportsCar myCar("Ferrari", 400, "F8", 5, "Red");


    // Calling public functions

    myCar.start();

    myCar.honk();

    myCar.accelerate();

    myCar.accelerate();

    myCar.brake();

    myCar.stop();


    // Displaying car details

    myCar.display();


    // Using setter to modify private data

    myCar.setCurrentGear(3);

    cout << "\nUpdated Gear: "
         << myCar.getCurrentGear() << endl;


    // Using getter to access private data

    cout << "Brand: "
         << myCar.getBrand() << endl;


    return 0;
}
