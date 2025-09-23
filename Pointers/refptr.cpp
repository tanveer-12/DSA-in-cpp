// using reference to change the value inside a pointer

#include <iostream>

void fun(int *p1){
    p1 = p1+1;
    std::cout<<p1;
}

int main(){
    int n = 10;
    std::cout<<&n;
    fun(&n);
    return 0;
}