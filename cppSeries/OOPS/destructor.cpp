// a desctructor example

#include <iostream>

class Simple{
private:
    int m_id {};
public:
    Simple(int id)
    :m_id{id}
    {
        std::cout<<"Constructing simple "<<m_id<<"\n";
    }
    ~Simple(){  //here is our destructor
        std::cout<<"Destructing simple "<<m_id<<"\n";
    }
    int getID() const {return m_id;}
};

int main(){
    Simple simple1{1};   // allocates a Simple
    Simple simple2 {2}; 
    //simple 2 dies here
    return 0;
} // simple1 dies here