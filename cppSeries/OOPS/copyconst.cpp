// introduction to the copy constructor
// - A copy constructor is a constructor which is used to 
// intialize an object with an existing object of the same type
// - After the copy const executes, the newly created obj
// should be a copy of the obj passed as the initializer

// here we have used implicit copy const which is created by C++
// Fraction fCopy{f} invokes the implicit copy constructor to initialize
// fCopy with f


#include <iostream>

class Fraction{
    int m_num {0};
    int m_dem {1};
public:
    // default constructor
    Fraction(int num=0, int dem=1)
    : m_num{num}, m_dem{dem}
    {

    }
    void print() const{
        std::cout<<"Fraction( "<<m_num<<", "<<m_dem<<")\n";
    }
};

// we can explicitly deifne our own copy const too.
// Defining our own copy const here
class Fraction2{
    int m_num {0};
    int m_dem {1};
public:
    // default constructor
    Fraction2(int num=0, int dem=1)
    : m_num{num}, m_dem{dem}
    {

    }
    Fraction2(const Fraction2 &fraction)
    // intialize our members using the corresponding member 
    // of the parameter
    :m_num {fraction.m_num}, 
    m_dem{fraction.m_dem}
    {
        std::cout<<"Our own Copy constructor created\n"; //just to prove it works
    }
    void print() const{
        std::cout<<"Fraction( "<<m_num<<", "<<m_dem<<")\n";
    }
};


int main(){
    Fraction f {5, 3};
    Fraction fCopy {f};     // copy constructor

    f.print();
    fCopy.print();

    Fraction2 f2{6,4};
    Fraction2 FCopy {f2};

    f2.print();
    FCopy.print();
    return 0;
}