#include <iostream>
#include <bits/stdc++.h>

class Engine{
public:
    Engine() {std::cout<<"Engine constructed\n";}
    ~Engine() {std::cout<<"Engine destroyed\n";}
};

class Vehicle{
public: 
    Vehicle(int speed){
        std::cout<<"Vehicle constructed with speed: "<<speed<<"\n";
    }
    ~Vehicle(){
        std::cout<<"Vehicle destroyed\n";
    }
};

class Car: public Vehicle{
    Engine engine;
    int wheel;
public: 
    Car(int speed, int w)
    : Vehicle(speed), wheel(w)
    {
        std::cout<<"Car constructed\n";
    }
    ~Car(){
        std::cout<<"Car destroyed\n";
    }
};

int main(){
    Car c(100, 4);
    return 0;
}