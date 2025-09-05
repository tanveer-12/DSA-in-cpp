// sum of first N numbers using parameterized recursion

#include <iostream>

void psum(int i, int sum){
    if(i<1){
        std::cout<<sum;
        return;
    }
    psum(i-1, sum+i);
}

int main(){
    int n, sum=0;
    std::cout<<"Enter n: ";
    std::cin>>n;
    psum(n,sum);
    return 0;
}