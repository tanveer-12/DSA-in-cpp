#include <iostream>

int main(){
    int x{5};
    int &ref{x};    // get a reference to x
    int *ptr{&x};   // get a pointer to x
    std::cout<<x;
    std::cout<<ref;
    std::cout<< *ptr<<'\n';

    ref = 6;
    std::cout<< x;
    std::cout<<ref;
    std::cout<<*ptr<<'\n';
    *ptr = 7;
    std::cout<<x;
    std::cout<<ref;
    std::cout<<*ptr<<'\n';

    int *ptr {};    // ptr is a null pointer.
    int *ptr {nullptr};  // explicitly initialize or assign a pointer a null value
    return 0;
}