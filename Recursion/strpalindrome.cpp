// checking if the string is palindrome or not using recursion

#include <bits/stdc++.h>

bool chkpalindrome(int i, std::string &str){
    // base case
    if(i >= str.size()/2) return true;
    if(str[i] != str[str.size() - i -1]) return false;
    return chkpalindrome(i+1, str);
}

int main(){
    std::string s = "He lived as a devil, eh?";

    //preprocess: keep only alphanumeric, lowercase
    std::string cleaned;
    for(char c : s){
        if(isalnum(c)) cleaned.push_back(tolower(c));
    }
    bool check = chkpalindrome(0, cleaned);
    if(check) std::cout<<"Is a Palindrome";
    else std::cout<<"Not a Palindrome";
    return 0;
}