// printing sum of first N numbers using functional recursion
#include <iostream>

int fsum(int n){
    if(n==0) return 0;
    return n+fsum(n-1);
}

int main(){
    int n;
    std::cout<<"Enter n: ";
    std::cin>>n;
    std::cout<<fsum(n);
    return 0;
}
