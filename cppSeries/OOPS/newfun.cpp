// to add a new functionality to a derived class, simply declare that functionality in 
// in the derived class like normal
#include <iostream>
class Base
{
protected:
    int m_value {};
public:
    Base(int value)
    :m_value {value}
    {}
    void identify() const {std::cout<<"I am Base\n";}
};

class Derived: public Base
{
public:
    Derived(int value)
    :Base {value}
    {

    }
    int getValue() const {return m_value;}
};

int main(){
    Derived derived{5};
    std::cout<<"derived has value "<<derived.getValue()<<"\n";
    return 0;
}