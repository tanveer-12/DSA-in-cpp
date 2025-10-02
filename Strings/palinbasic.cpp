// tell if the string is a palindrome or not [basic]

#include <string>
#include <iostream>

int main(){
    std::string s="ama";
    int start=0, last = s.size()-1;
    while(start < last)
    {
        if(s[start] != s[last]){
            std::cout<<"Not a palindrome";
            return -1;
        }
        start++; last--;
    }
    std::cout<<"It is a palindrome";
    return 0;
}