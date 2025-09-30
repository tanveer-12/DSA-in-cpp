// member variables are not the only type of member that can be made static.
// member functions can be made static as well. 
// While we could create a normal public member function to access the static member var, we’d 
// then need to instantiate an object of the class type to use the function!


#include <iostream>

class Something{
private:
    static inline int s_value {1};
public:
    // static member function
    // defined inside class definition
    static int getValue() {return s_value;}

    // static member func
    // just declared here
    static int getNextValue();
};

// definition of static func outside the class
// NOTE: WE DON"T USE STATIC KEYWORD HERE
int Something::getNextValue(){
    return s_value++;
}

// Because static member functions are not associated with a 
// particular object, they can be called directly by using the 
// class name and the scope resolution operator
int main(){
    for(int count{0}; count<5; ++count){
        std::cout<<"the next value is: "<<Something::getNextValue()<<"\n";
    }
    std::cout<<Something::getValue();
    return 0;
}

// Member functions defined outside the class definition are 
// not implicitly inline, but can be made inline by using the 
// inline keyword. 

// static member function that is defined in a header file 
// should be made inline so as not to violate the One Definition 
// Rule (ODR) if that header is then included into multiple 
// translation units.
