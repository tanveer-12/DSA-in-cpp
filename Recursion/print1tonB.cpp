// printing numbers from 1 to N using backtracking

#include <bits/stdc++.h>

void printBacktrack(int i, int n);

int main(){
    int n;
    std::cout<<"Number from 1 to N: ";
    std::cin>>n;
    printBacktrack(n,n);
    return 0;
}

void printBacktrack(int i, int n){
    if(i<1) return;
    printBacktrack(i-1, n);
    std::cout<<i<<std::endl;
}