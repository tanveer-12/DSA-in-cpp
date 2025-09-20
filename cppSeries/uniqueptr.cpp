// unique pointers

#include <iostream>
#include <memory>

class Rectangle{
    int length;
    int breadth;

public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
    int area() {return length * breadth;}
};

int main(){
    std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    std::cout<<P1->area() <<std::endl;

    std::unique_ptr<Rectangle> P2;

    P2 = move(P1);
    std::cout<<P2->area();
    return 0;
}