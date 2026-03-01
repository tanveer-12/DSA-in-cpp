#include <iostream>

class Base {
public:
    int x = 10;
    virtual void f() {
        std::cout << "Base::f\n";
    }
};

class Derived : public Base {
public:
    int y = 20;
    void f() override {
        std::cout << "Derived::f\n";
    }
};

int main() {
    Base* p = new Derived();
    p->f();     // breakpoint here
}
