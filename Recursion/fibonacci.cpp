// Re 5: Multiple recursion calls
// fibonacci numbers through recursion

#include <iostream>

int fib(int n){
    //base case
    if(n<=1) return n;  //because 
    int last = fib(n-1);
    int slast = fib(n-2);
    return last+slast;
}

int main(){
    int num;
    std::cout<<"Enter num for the fibonacci series: ";
    std::cin>>num;
    std::cout<<"Fibonacci number is: " <<fib(num);
    return 0;
}