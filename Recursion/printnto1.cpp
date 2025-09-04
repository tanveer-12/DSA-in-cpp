// print N to 1 using recursion
#include <bits/stdc++.h>

void printLinearly(int i, int n);

int main(){
    int i=1,n;
    std::cout<<"Print N numbers from N to 1: ";
    std::cin>>n;
    printLinearly(i,n);
    return 0;
}

void printLinearly(int i, int n){
    if(n<i) return;
    std::cout<<n<<std::endl;
    printLinearly(i,n-1);
}