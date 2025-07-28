#include <iostream>

int main()
{
    std::string name;
    // std::cout << "Hi, My name is Tanveer Kaur\n";
    std::cout << "what is your name: " << std::endl;
    ;
    std::cin >> name;
    std::cout << "Hi, " + name + " , it's a wonderful day" << std::endl;
    return 0;
}