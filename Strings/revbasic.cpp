// reverse the string basic

#include <iostream>
#include <string>

int main(){
    std::string s = "Tanveer";
    int start=0, last = s.size()-1;
    while(start <= last){
        char temp = s[start];
        s[start] = s[last];
        s[last] = temp;
        start++;
        last--;
    }
    std::cout<<s;
    return 0;
}