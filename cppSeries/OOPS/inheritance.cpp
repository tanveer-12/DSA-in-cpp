// constructors and initialization of derived classes
// derived classes need to use access functions to access the private members of the base class
#include <iostream>
class Base{
private:
    int m_id{}; 
public:
    Base(int id=0)
    : m_id {id}
    {}

    int getID() const {return m_id;}
};

class Derived: public Base 
{
private:
    double m_cost{};
public:
    Derived(double cost=0.0, int id=0.0)
    : Base {id} // call Base(int) cons with value id
    , m_cost {cost}
    {}

    double getCost() const {return m_cost;}
};

int main(){
    Derived derived{1.3, 4};    // use Derived(double, int) constructor
    std::cout<<"ID: "<<derived.getID();
    std::cout<<"Cost"<<derived.getCost();
    return 0;
}