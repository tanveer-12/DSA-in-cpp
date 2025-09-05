#include <iostream>


void f(int n){
    std::cout<<n<<"'s Stack frame pushed\n";
    if(n>1){
        f(n-1);
        f(n-1);
    }
    std::cout<<n<<"'s Stack frame removed\n";
}

int main(){
    f(3);
    return 0;
}