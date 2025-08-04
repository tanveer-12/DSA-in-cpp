/*
Find the trailing zeroes in a factorial
6! = 720, so there is one zero as the result
*/

#include <iostream>

int trailingZeroes(int N){
    int count = 0;
    while(N >= 5){      // N = 7
        count = count + (N/5);  //  = 0+7/5=>1
        N = N/5;            // 7/5=1        
    }
    return count;         // count = 1
}

int main(){
    int num;
    std::cout<<"Factorial num: "<<std::endl;
    std::cin>>num;
    std::cout<<trailingZeroes(num)<<std::endl;
    return 0;
}