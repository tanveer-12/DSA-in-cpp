#include <string>
#include <iostream>

int main(){
    std::string s = "Tanu";
    std::cout<<s.size()<<"\n";
    // adding a character K at the end of my string
    s.push_back('K');
    std::cout<<s<<"\n";
    // deleting the last char from the string
    s.pop_back();
    std::cout<<s<<"\n";
    return 0;
}