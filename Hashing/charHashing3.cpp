// char hashing using all letters 
// so our hash arr ican be of size 256 because this is the number
// of chars that exist

#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin>>s;

    // pre computing 
    int hash[256] = {0};
    for(int i=0; i<s.size();i++){
        hash[s[i]]++;   // because chars already have designated index in 256 size
    }
    int q;
    std::cin>>q;
    while(q--){
        char ch;
        std::cin>>ch;
        std::cout<<ch << " -> "<<hash[ch]<<std::endl;
    }
    return 0;
}