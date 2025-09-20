#include <iostream>


// function template for maximum
template<typename T>    // defines a generic type T
T myMax(T x, T y){
    return (x > y) ? x : y;
}

int main(){
    std::cout<<myMax<int>(3,7)<<std::endl;
    std::cout<<myMax<char>('c', 'g')<<std::endl;
    return 0;
}