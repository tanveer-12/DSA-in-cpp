// size of the string without using the size() func

#include <iostream>
#include <string>

int main(){
    std::string s = "Tanveer";
    int size = 0;
    while(s[size] != '\0'){
        size++;
    }
    std::cout<<"Size of the string is: "<<size<<"\n";
    return 0;
}