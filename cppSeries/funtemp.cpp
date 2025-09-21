// function templates intro from learncpp.com


#include <iostream>

template <typename T>
T max(T x, T y){
    return (x < y) ? y: x;
}
template <typename T>
void print(T x){
    std::cout<<x;   // prints T however it normally prints
}
void print(bool x){
    std::cout<<std::boolalpha<<x; //prints bool as true or false, not 1 or 0
}

int main(){
    std::cout<<max<int>(1,2)<<" \n";
    print<bool>(true); //calls print<bool>(bool) --prints 1
    std::cout<<"\n";
    print<>(true); //deduces print<bool>(bool) --prints 1
    std::cout<<"\n";
    print(true);    // calls print(bool) -- prints true
    return 0;
}