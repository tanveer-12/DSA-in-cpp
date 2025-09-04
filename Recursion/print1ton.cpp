//Print 1 to N using recursion

#include <bits/stdc++.h>

void printLinearly(int i, int &n);


int main(){
    int n,i=1;
    std::cout<<"Print numbers upto N: ";
    std::cin>>n;
    printLinearly(i,n);
    return 0;
}

void printLinearly(int i, int &n){
    if(i > n) return;
    std::cout<<i<<std::endl;
    printLinearly(i+1,n);
}