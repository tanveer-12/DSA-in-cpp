#include <iostream>

void charge(int &a){
    std::cout<<a<<"\nafter change\n";
    a = 20;
    std::cout<<a;
}

int main(){
    int x = 5;
    charge(x);
    return 0;
}