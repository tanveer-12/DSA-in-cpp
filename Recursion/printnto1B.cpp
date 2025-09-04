// print numbers from N to 1 using backtracking

#include <bits/stdc++.h>

void printB(int i, int n);

int main(){
    int n;
    std::cout<<"Enter numbers from N to 1(specify N): ";
    std::cin>>n;
    printB(1,n);
    return 0;
}

void printB(int i, int n){
    if(i>n) return;
    printB(i+1, n);
    std::cout<<i<<std::endl;
}