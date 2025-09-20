#include <iostream>
#include <memory>

class Rectangle{
    int length;
    int breadth;
public: 
    Rectangle(int l , int b){
        length = l;
        breadth = b;
    }
    int area() {return length * breadth;}
};

int main(){
    std::shared_ptr<Rectangle> P1(new Rectangle(10,5));
    std::cout<< P1->area()<<std::endl;

    std::shared_ptr<Rectangle> P2;
    // P1 and P2 are pointing to the same object
    P2 = P1;
    std::cout<< P2->area() << std::endl;
    std::cout<< P1->area()<<std::endl;
    std::cout<<P1.use_count();
    return 0;
}