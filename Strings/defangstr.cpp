// LC 1108 - Defanging an IP Address

#include <string>
#include <iostream>


std::string defang(std::string &s){
    int index = 0;
    std::string ans;
    while(index < s.size()){
        if(s[index] == '.'){
            ans = ans + "[.]";
        }
        else
           ans = ans + s[index];
        index++;
    }
    return ans;
}

int main(){
    std::string str = "1.1.1.1";
    std::cout<<defang(str);
    return 0;
}