#include<iostream>
#include<string>

using namespace std;

class SportsCar{ // inheriting the base class Car to the derived class SportsCar
    private:
    // characteristics of the sports car
       string brand;
       string model;
       bool isEngineRunning;
       int currentSpeed;
       int currentGear;
    public:
        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineRunning = false;   
            this->currentSpeed = 0;
            this->currentGear = 0; // neutral gear
        }

        // getters and setters for private member variables

        string getBrand() {
            return brand;
        }

        void setBrand(string b) {
            brand = b;
        }

        string getModel() {
            return model;
        }

        void setModel(string m) {
            model = m;
        }

        int getCurrentSpeed() {
            return currentSpeed;
        }

        void setCurrentSpeed(int speed) {
            if (speed < 0) {
                cout << "Speed cannot be negative." << endl;
                return;
            }
            currentSpeed = speed;
        }

        int getCurrentGear() {
            return currentGear;
        }

        void setCurrentGear(int gear) {
            if (gear < 0 || gear > 6) {
                cout << "Invalid gear. Please select a gear between 0 and 6." << endl;
                return;
            }
            currentGear = gear;
        }       



        // behaviors of the sports car
        void startEngine(){
           isEngineRunning = true;
            cout << brand << " " << model << " engine started." << endl;
        }
        void shiftGreat(int gear) { 
          if (!isEngineRunning) {
                cout << "Cannot shift gears. Engine is not running." << endl;
                return;
            }
            if (gear < 1 || gear > 6) {
                cout << "Invalid gear. Please select a gear between 1 and 6." << endl;
                return;
            }
            currentGear = gear;      
            cout << brand << " " << model << " shifting to gear "               << gear << endl;
        }

        void accelerate() {
           if (!isEngineRunning) {
                cout << "Cannot accelerate. Engine is not running." << endl;
                return;
            }
            if (currentGear == 0) {
                cout << "Cannot accelerate. Please shift to a gear first." << endl;
                return;
            }
            currentSpeed += 10; // increase speed by 10 km/h
            cout << brand << " " << model << " accelerating. Current speed: " << currentSpeed << " km/h" << endl;
        }

        void brake() {
           if (!isEngineRunning) {
                cout << "Cannot brake. Engine is not running." << endl;
                return;
            }
            if (currentSpeed == 0) {
                cout << "Car is already stopped." << endl;
                return;
            }
            currentSpeed -= 10; // decrease speed by 10 km/h
            if (currentSpeed < 0) currentSpeed = 0; // prevent negative speed
            cout << brand << " " << model << " braking. Current speed: " << currentSpeed << " km/h" << endl;
        }

        void stopEngine() {
            if (!isEngineRunning) {
                cout << "Engine is already stopped." << endl;
                return;
            }
            isEngineRunning = false;
            currentSpeed = 0; // reset speed to 0 when engine stops
            currentGear = 0; // reset gear to neutral when engine stops      
            cout << "Sports car engine stopped." << endl;
        }
};


int main() {
    SportsCar* mySportsCar = new SportsCar("Ferrari", "488 Spider");
    mySportsCar->startEngine();
    mySportsCar->shiftGreat(1);
    mySportsCar->accelerate();
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->shiftGreat(2);
    mySportsCar->accelerate();
    mySportsCar->stopEngine();

    // setting arbitrary values to demonstrate encapsulation
    // mySportsCar->currentSpeed = 100; trying to set speed directly (not recommended) because it breaks encapsulation, it will throw an error since currentSpeed is private
    // for that we use getter and setter methods to access and modify the private member variables.

    // but we can do this using setter method
    mySportsCar->getCurrentSpeed(); // getting the current speed using getter method 
    delete mySportsCar; // delete the object to free memory
    return 0;
}