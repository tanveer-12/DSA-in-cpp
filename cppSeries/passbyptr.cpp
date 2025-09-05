// Pass by pointer 
// it is very similar to pass by ref, only difference is that
// the raw address of the argument is paassed as the parameter
// to the function instead of the reference

#include <iostream>

void change(int *a){
    std::cout<<*a<<"\nBefore modifying\n";
    *a = 22;
    std::cout<<*a;
}

int main(){
    int x = 5;
    change(&x);
    return 0;
}