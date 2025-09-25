// Member initialization order using constructors

#include <iostream>

class Foo {
private:
    int m_x{};
    int m_y{};
public:
    Foo(int x, int y)
        : m_x {x}, m_y {y}
        {   
            std::cout<<"Foo constructed\n";
        }
    const int& getx() const{return m_x;}
    void print() const {
        std::cout<<"Foo ("<<m_x<<", "<<m_y<<")\n";
    }
};

int main(){
    Foo foo{6,7};
    foo.print();
    return 0;
}