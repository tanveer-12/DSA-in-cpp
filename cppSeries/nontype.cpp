// non-type template parameters are useful for

#include <cassert>
#include <cmath>
#include <iostream>

template <int N>
void print(){
    std::cout<<N;
}

double getSqrt(double d){
    assert(d >= 0.0 && "getSrt(): d must be non-negative");
    // the assert above will probably be compiled out in non-dubug builds
    if(d >= 0){
        return std::sqrt(d);
    }
    return 0.0;
}

int main(){
    std::cout<< getSqrt(5.0)<<"\n";
    std::cout<<getSqrt(-5.0)<<"\n";
    print<5>();
    std::cout<<"\n";     // no conversion necessary
    print<'c'>();   // c converted to type int, prints 99
    return 0;
}