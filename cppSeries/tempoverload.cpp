// just like functions may be overloaded, function 
// templates may also be overloaded.

#include <iostream>

// add two values with matching types
template <typename T>
auto add(T x, T y){
    return x+y;
}

// add two values with non-matching types
// as of C++ 20 we could also use auto add(auto x, auto y)
template <typename T, typename U>
auto add(T x, U y){
    return x + y;
}

// add three values with any type
// as of c++ 20, we could also use auto add(auto x, auto y, auto z)
template <typename T, typename U, typename V>
auto add(T x, U y, V z){
    return x+y+z;
}

int main(){
    std::cout<<add(1.2,3.4)<<"\n";  // instantiates and calls add<double>()
    std::cout<<add(5.6, 7)<<"\n";   // instantiates and calls add<double, int>()
    std::cout<<add(8,9,10);         // instantiates and calls add<int, int, int>()
}