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
    // taking a line as an input
    std::getline(std::cin, s);
    std::cout<<s<<"\n";
    // making tanveer and kaur stick together
    std::string s1 = "tanveer", s2 = "kaur";
    std::string s3 = s1+s2;
    std::cout<<s3<<"\n";
    // another method to append strings together is
    std::string s4 = s1.append(s2);
    std::cout<<s4<<"\n";
    return 0;
}