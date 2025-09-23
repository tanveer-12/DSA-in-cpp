#include <iostream>

void fun(int *p){
    *p = *p + 5;
}

int main(){
    int n = 10;
    int *p = &n;
    fun(p);
    std::cout<<n;
    return 0;
}