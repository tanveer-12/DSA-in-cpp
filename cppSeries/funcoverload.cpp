// function overloading intro
// Function overloading allows us to create multiple 
// functions with the same name, so long as each identically
// named function has different parameter types (or the
// functions can be otherwise differentiated)

#include <iostream>

int add(int x, int y){  // int version  
    return x+y;
}

double add(double x, double y){     //float version
    return x + y;
}

int main(){
    std::cout<<add(1,2)<<" ";
    std::cout<<add(1.4, 1.6);
    return 0;
}