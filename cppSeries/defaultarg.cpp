// Default arguments in cpp
/*======================
A default argument is a value provided for a parameter in a
function declaration that is automatically assigned by the
compiler if no value is provided for those parameters in 
function call. If the value is passed for it, the default 
value is overwritten by the passed value.
- if a parameter has a default argument, all parameters to its
right must also have default values.
=========================
*/

#include <iostream>

void f(int a=10){
    std::cout<<a<<std::endl;
}

//function with default height h argument
double calcArea(double l, double h=10.0){
    return l *h;
}

int main(){
    // uses default argument
    f();
    // uses passed value
    f(288);
    std::cout<<"Area 1: "<<calcArea(5)<<std::endl;
    std::cout<<"Area 2: "<<calcArea(5, 9);
    return 0;
}