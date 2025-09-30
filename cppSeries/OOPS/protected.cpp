// protected access specifier allows the class the member belongs to, friends and 
// derived classes to access the member.
// however, protected members are not accessible from outside the class

class Base
{
public:
    int m_pub {};
private:
    int m_pri {};
protected:
    int m_prot {};
};

class Derived: public Base
{
public:
    Derived()
    {
        m_pub = 1;
        m_prot = 2;
        // m_pri = 3; // not allowed: cannot access private base members from derived class directly
    }
};

int main(){
    Base base;
    base.m_pub = 1;
    //base.m_pri = 3;     // not allowed: cannot access private members from outside class
    //base.m_prot = 2;    // not allowed: cannot access protected members from outside the class
}