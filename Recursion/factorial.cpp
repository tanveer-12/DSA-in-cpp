// Factorial of N numbers using recursion

#include <iostream>

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

int main(){
    int n;
    std::cout<<"Factorial of N numbers: ";
    std::cin>>n;
    std::cout<<fact(n);
    return 0;
}