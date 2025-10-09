#include <iostream>

class Box{
    public:
        double len, breadth, height;

        // member functions declarations
        double getVolume(void);
        void setLength(double leng);
        void setBreadth(double bre);
        void setHeight(double hei);
};

double Box::getVolume(void){
    return len * breadth * height;
}

void Box::setLength(double leng){
    len = leng;
}

void Box::setBreadth(double bre){
    breadth = bre;
}

void Box::setHeight(double hei){
    height = hei;
}

int main(){
    Box box1;
    Box box2;
    double volume = 0.0;

    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    volume = box1.getVolume();
    std::cout<<"Volume of box1: "<<volume<<std::endl;
    return 0;
}