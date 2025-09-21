#include "add.h"
#include <iostream>

template <typename T>
T addOne(T x);      // func template forward declaration

int main(){
    std::cout<<addOne(1)<<"\n";
    std::cout<<addOne(2.3);
    return 0;
}