// Print Name n times using recursion
#include <bits/stdc++.h>

void printNames(int i, int n,std::string &name){
    if(i >n) return;
    std::cout<<name<<std::endl;
    printNames(i+1, n,name);
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int n;
    std::string name;
    std::cout<<"What is your good name: ";
    std::cin>>name;
    std::cout<<"How many times you want the name to be printed: ";
    std::cin>>n;
    printNames(1,n,name);
    return 0;
}