#include <iostream>
#include <string>

using namespace std;

class Car {

    public:
    virtual void startEngine()=0;  //here virtual void means that the function is a pure virtual function, which means that any derived class must provide an implementation for this function
    // The "=0" syntax indicates that the function has no implementation in the base class and must be overridden in any subclass.
    // This makes the Car class an abstract class, meaning it cannot be instantiated on its own and is intended to be used as a base class for other classes that represent specific types of cars.
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car() {}  //virtual destructor to ensure proper cleanup of derived classes
};


class SportsCar : public Car {
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b ,  string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed=0;
        currentGear=0; //neutral
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " engine started." << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << "Cannot shift gear. Engine is off." << endl;
            return; 
        }
        currentGear=gear;
        cout << brand << " " << model << " shifted to gear " << currentGear << "." << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << "Cannot accelerate. Engine is off." << endl;
            return; 
        }
        currentSpeed += 20;
        cout << brand << " " << model << " accelerated to " << currentSpeed << " km/h." << endl;
    }

    void brake(){
        if(!isEngineOn){
            cout << "Cannot brake. Engine is off." << endl;
            return; 
        }
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " slowed down to " << currentSpeed << " km/h." << endl;
    }
    
    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;   
        currentGear=0;
        cout << brand << " " << model << " engine stopped." << endl;
    }
};


//Main method

int main(){
       Car* myCar= new SportsCar("Ferrari", "488 Spider");
       myCar->startEngine();        
       myCar->shiftGear(1);
       myCar->accelerate();     
       myCar->brake();
       myCar->stopEngine();

       delete myCar;// clean up memory allocated for the car object
       return 0;
};


//ABSTRACTION is nothing but hiding the implementation details and showing only functionality to the user.
//  In C++, abstraction can be achieved using abstract classes and interfaces. 
// An abstract class is a class that cannot be instantiated on its own and is intended to be used as a base class for other classes. 
// It can contain pure virtual functions, which are functions that have no implementation in the base class and must be overridden in any derived class.
//  This allows for a clear separation between the interface (what the class does) and the implementation (how it does it), making the code easier to understand, maintain, and extend.