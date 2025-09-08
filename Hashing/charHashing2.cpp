// char hashing using lowercase letters only
// so our hash arr is just of size 26

#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin>>s;

    //pre compute
    int hash[26] = {0};
    for(int i=0; i<s.size();i++){
        hash[s[i] - 'a']++; // 'b' - 'a' and then increasing count,
    }
    int q;
    std::cin>>q;
    while(q--){
        char ch;
        std::cin>>ch;
        //fetching the hashed char count
        std::cout<<ch<<" -> "<<hash[ch-'a']<<std::endl;
    }
    return 0;
}