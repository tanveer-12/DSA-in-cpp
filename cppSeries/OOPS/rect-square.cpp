/*
RECTANGLE SQUARE PROBLEM
*/


// 1. rectangle class
#include <iostream>
#include <stdexcept>
#include <cmath>

class Rectangle{
    double x_;
    double y_;
    double w_;
    double h_;
public:
    // default constructor
    Rectangle()
    : x_ {0.0},
    y_ {0.0},
    w_ {1.0},
    h_ {1.0}
    {}

    // constructor from top-left + size
    Rectangle(double x, double y, double width, double height){
        if(width <= 0 || height <= 0){
            throw std::invalid_argument("Width and height must be positive");
        }
        x_ = x;
        y_ = y;
        w_ = width;
        h_ = height;
    }

    // getters - const
    double x() const {return x_;}
    double y() const {return y_;}
    double width() const {return w_;}
    double height() const {return h_;}

    // area and perimeter - derived, not stored
    double area() const {return w_ * h_;}
    double perimeter() const {return 2 * (w_ + h_);}

    // setters - validate first
    void set_width(double w){
        if(w <= 0){
            throw std::invalid_argument("Width must be positive");
        }
        w_ = w;
    }

    void set_height(double h){
        if(h <= 0){
            throw std::invalid_argument("Height must be positive");
        }
        h_ = h;
    }
};

class Square: public Rectangle{
public:
    // constructor: force widht = height
    Square(double x, double y, double side)
    : Rectangle(x,y,side, side) {}

    // override setters to keep square property
    // void set_width(double new_w) {
    //     Rectangle::set_width(new_w);
    //     Rectangle::set_height(new_w);
    // }
};

int main(){
    std::cout<<"===Scenario 1: Default rectangle===\n";
    {
        Rectangle r; // default (0,0,1,1)
        std::cout<< "Default rect: (" <<r.x() <<", "<<r.y()
            <<"), w=" << r.width() <<", h=" <<r.height() <<"\n";
        std::cout<<"Area: "<<r.area() <<", Perimeter: "<<r.perimeter()<<"\n";
    }
    std::cout << "\n=== Scenario 2: Valid Custom Rectangle ===\n";
    {
        Rectangle r(2.0, 3.0, 4.0, 5.0);
        std::cout << "r = (" << r.x() << "," << r.y() << "), " 
                  << r.width() << "x" << r.height() << "\n";
        std::cout << "Area: " << r.area() << "\n";
    }
    std::cout << "\n=== Scenario 2: Invalid Construction ===\n";
    try {
        Rectangle r(0, 0, -1, 2);  // invalid width
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }
    std::cout << "\n=== Scenario 4: Modifying Rectangle ===\n";
    {
        Rectangle r(1, 1, 2, 3);
        std::cout << "Before: " << r.width() << "x" << r.height() << "\n";
        r.set_width(4);
        std::cout << "After set_width(4): " << r.width() << "x" << r.height() << "\n";
        r.set_height(6);
        std::cout << "After set_height(6): " << r.width() << "x" << r.height() << "\n";
        // Expected: 4x6 — independent changes. This is core rectangle behavior.
    }
    Square sqr(2,3,8);
    std::cout << "sqr = (" << sqr.x() << "," << sqr.y() << "), " 
                  << sqr.width() << "x" << sqr.height() << "\n";
    return 0;
}