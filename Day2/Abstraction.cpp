#include<iostream>
#include<string>

using namespace std;

class Car{
    public : 
    // virtural void mean, the method are only declaring here and not defining.  
        virtual void startEngine() = 0; 
        virtual void shiftGreat(int gear) = 0; 
        virtual void accelerate() = 0; 
        virtual void brake() = 0; 
        virtual void stopEngine() = 0; 
        virtual ~Car(){} // this is a virtual destructor, which is used to ensure that the derived class's destructor is called when an object of the derived class is deleted through a pointer to the base class.
};

class SportsCar : public Car{ // inheriting the base class Car to the derived class SportsCar
    public:
       string brand;
       string model;
       bool isEngineRunning;
       int currentSpeed;
       int currentGear;
 
        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineRunning = false;   
            this->currentSpeed = 0;
            this->currentGear = 0; // neutral gear
        }
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
    SportsCar mySportsCar("Ferrari", "488 Spider");
    mySportsCar.startEngine();
    mySportsCar.shiftGreat(1);
    mySportsCar.accelerate();
    mySportsCar.accelerate();
    mySportsCar.brake();
    mySportsCar.shiftGreat(2);
    mySportsCar.accelerate();
    mySportsCar.stopEngine();
    delete &mySportsCar; // delete the object to free memory
    return 0;
}