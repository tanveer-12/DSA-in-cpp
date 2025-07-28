#include <iostream>

char Convert(char name){
    char ans = name - 'a' + 'A';
    return ans;
}

int main(){
    char name;
    std::cin>>name;
    std::cout<<Convert(name)<<std::endl;
}