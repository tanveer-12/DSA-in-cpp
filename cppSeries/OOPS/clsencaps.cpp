// this class encapsulates an int value, and provide some access
// func to get and set that value

//  the keyword 'this' is a const pointer that holds the address of 
// the current implicit object.

#include <iostream>

class Simple{
private:
    int m_id{};
public:
    Simple(int id)
    :m_id{id}{

    }
    int getID() const {return m_id;}
    void setID(int id) {m_id = id;}
    // use 'this' pointer to access the implicit obj
    // and operator -> to select member m_id
    void print() const {std::cout<<this->m_id;}
};

int main(){
    Simple sim{1};
    sim.setID(2);
    sim.print();
}